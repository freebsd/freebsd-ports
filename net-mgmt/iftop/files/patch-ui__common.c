--- ui_common.c.orig	2014-01-05 18:40:46 UTC
+++ ui_common.c
@@ -17,6 +17,12 @@
 
 #include "ui_common.h"
 
+sorted_list_type screen_list;
+host_pair_line totals;
+int peaksent, peakrecv, peaktotal;
+hash_type* screen_hash;
+hash_type* service_hash;
+
 /* 2, 10 and 40 seconds */
 int history_divs[HISTORY_DIVISIONS] = {1, 5, 20};
 
