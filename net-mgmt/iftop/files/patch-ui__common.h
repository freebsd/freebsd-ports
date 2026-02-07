--- ui_common.h.orig	2014-01-01 14:17:08 UTC
+++ ui_common.h
@@ -33,12 +33,12 @@ typedef struct host_pair_line_tag {
 
 extern options_t options;
 
-sorted_list_type screen_list;
-host_pair_line totals;
-int peaksent, peakrecv, peaktotal;
+extern sorted_list_type screen_list;
+extern host_pair_line totals;
+extern int peaksent, peakrecv, peaktotal;
 extern history_type history_totals;
-hash_type* screen_hash;
-hash_type* service_hash;
+extern hash_type* screen_hash;
+extern hash_type* service_hash;
 
 void analyse_data(void);
 void screen_list_init(void);
