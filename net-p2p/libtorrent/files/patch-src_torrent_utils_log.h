--- src/torrent/utils/log.h.orig	2012-04-20 08:41:43.000000000 +0200
+++ src/torrent/utils/log.h	2014-02-02 18:40:40.000000000 +0100
@@ -124,15 +124,15 @@
 
 #define lt_log_print(log_group, ...)                                    \
   if (torrent::log_groups[log_group].valid())                           \
-    torrent::log_groups[log_group].internal_print(NULL, NULL, NULL, NULL, __VA_ARGS__);
+    torrent::log_groups[log_group].internal_print(NULL, NULL, NULL, 0, __VA_ARGS__);
 
 #define lt_log_print_info(log_group, log_info, log_subsystem, ...)      \
   if (torrent::log_groups[log_group].valid())                           \
-    torrent::log_groups[log_group].internal_print(&log_info->hash(), log_subsystem, NULL, NULL, __VA_ARGS__);
+    torrent::log_groups[log_group].internal_print(&log_info->hash(), log_subsystem, NULL, 0, __VA_ARGS__);
 
 #define lt_log_print_data(log_group, log_data, log_subsystem, ...)      \
   if (torrent::log_groups[log_group].valid())                           \
-    torrent::log_groups[log_group].internal_print(&log_data->hash(), log_subsystem, NULL, NULL, __VA_ARGS__);
+    torrent::log_groups[log_group].internal_print(&log_data->hash(), log_subsystem, NULL, 0, __VA_ARGS__);
 
 #define lt_log_print_dump(log_group, log_dump_data, log_dump_size, ...) \
   if (torrent::log_groups[log_group].valid())                           \
