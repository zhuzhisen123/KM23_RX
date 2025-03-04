#ifndef APP_MAIN_H
#define APP_MAIN_H

typedef struct _APP_VAR {
    s8 music_volume;
    s8 call_volume;
    s8 wtone_volume;
    u8 opid_play_vol_sync;
    u8 aec_dac_gain;
    u8 aec_mic_gain;
    u8 rf_power;
    u8 poweron_charge;                  //开机进充电标志
    u8 goto_poweroff_flag;
    u8 goto_poweroff_cnt;
    u8 play_poweron_tone;
    u8 remote_dev_company;
    u8 siri_stu;
    int auto_stop_page_scan_timer;     //用于1拖2时，有一台连接上后，超过三分钟自动关闭Page Scan
    volatile int auto_shut_down_timer;
    volatile int wait_exit_timer;
    u16 auto_off_time;
    u16 warning_tone_v;
    u16 poweroff_tone_v;
    u32 start_time;
    s8  usb_mic_gain;
    u8  reverb_status;                 //用于tws+混响在pc模式时，同步关闭混响, 0:非pc模式
    u8 	cycle_mode;
    u8 chargestore_online;
    u8 charge_full_flag;
    u32 tx_mute_cnt;
    u8 flag_rf_dut;
    u8 rx_conn_num;
    u8 flag_tx2_mute;
    u8 LRConnect_Status[2];
    u8 LRMicGainSyncReady[2];
    u8 usr_tx_ch[2]; // 数据
    u8 usr_tx_conn[2]; // 标记
    u8 usr_tx_mute[2];
    u8 flag_tx_mute[2];
    u8 flag_wlm_denoise[2];

    // for bonding.
    u8 usr_pair_clear[2];
    u8 usr_pair_celar_cnt;
    u8 flag_spk_ready;
    u8 spk_delay;
    int spk_timeout_timer;
    int spk_led_timer;
    u8 spk_switch_cnt;
    u8 denoise_switch_cnt;
    int denoise_led_timer;
    u8 flag_charge;
    u8 flag_low_pwr;
    u8 flag_vbat_low_pwr;

    u8 wlm_voice_change_ready;
    u8 wlm_voice_change_delay;
    u8 wlm_voice_change_data[2];
    u8 is_denoise_led;
    u16 wlm_pair_clear;
} APP_VAR;


#define    BT_EMITTER_EN     1
#define    BT_RECEIVER_EN    2

typedef struct _BT_USER_COMM_VAR {
} BT_USER_COMM_VAR;

extern APP_VAR app_var;

extern void app_main();

#define earphone (&bt_user_priv_var)

extern void usr_mono_stereo_mode(u8 stereo);
extern void usr_rx_conn_deal();
extern void usr_rx_dconn_deal();
#endif
