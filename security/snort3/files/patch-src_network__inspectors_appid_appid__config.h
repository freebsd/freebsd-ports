--- src/network_inspectors/appid/appid_config.h.orig	2020-04-28 22:50:18 UTC
+++ src/network_inspectors/appid/appid_config.h
@@ -65,8 +65,8 @@ class AppIdConfig (public)
     uint32_t first_decrypted_packet_debug = 0;
 #endif
     bool log_stats = false;
-    unsigned long app_stats_period = 300;
-    unsigned long app_stats_rollover_size = 0;
+    uint32_t app_stats_period = 300;
+    uint32_t app_stats_rollover_size = 0;
     const char* app_detector_dir = nullptr;
     std::string tp_appid_path = "";
     std::string tp_appid_config = "";
