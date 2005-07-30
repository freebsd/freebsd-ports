--- server-src/infofile.c.orig	Wed Mar 16 11:15:28 2005
+++ server-src/infofile.c	Thu Jul  7 14:12:54 2005
@@ -274,7 +274,7 @@
     rc = 0;
 
     nb_history = 0;
-    for(i=0;i<=NB_HISTORY+1;i++) {
+    for(i=0;i<sizeof(info->history)/sizeof(info->history[0]);i++) {
 	info->history[i].level = -2;
     }
     for(rc = -2; (line = agets(infof)) != NULL; free(line)) {
