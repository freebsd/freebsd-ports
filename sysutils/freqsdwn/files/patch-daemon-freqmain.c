--- daemon/freqmain.c.orig	Thu Jun 30 09:20:10 2005
+++ daemon/freqmain.c	Sun Feb  5 00:06:50 2006
@@ -553,12 +553,12 @@
     unlink(idf);
 
     /* シャットダウン準備 */
-    system("/bin/sync");
-    system("/bin/sync");
-    system("/bin/sync");
+    sync();
+    sync();
+    sync();
 
     /* シャットダウン開始 */
-    system("shutdown -h now");
+    system("/sbin/shutdown -h now");
 
     exit(0);
 }
