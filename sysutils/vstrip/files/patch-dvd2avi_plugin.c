--- dvd2avi_plugin.c.orig	Mon Jan  2 17:49:31 2006
+++ dvd2avi_plugin.c	Mon Jan  2 17:49:53 2006
@@ -13,6 +13,8 @@
 #include "vstrip.h"
 #include "dvd2avi_plugin.h"
 
+#define max(a,b) ((a) >= (b) ? (a) : (b))
+
 bool dvd2avi_process(byte *data, tp_vs_streaminfo const si, void *user_data)
 {
 	t_dvd2avi* d2v = (t_dvd2avi *)user_data;
