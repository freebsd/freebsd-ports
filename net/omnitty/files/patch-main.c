--- main.c.orig	2005-10-26 06:08:25.000000000 +0800
+++ main.c	2008-02-17 22:45:29.000000000 +0800
@@ -335,9 +335,10 @@
 
    while (!quit) {
       if (zombie_count) {
-         zombie_count--;
-         chldpid = wait(NULL);
-         machmgr_handle_death(chldpid);
+         if ((chldpid = waitpid(-1, NULL, WNOHANG)) > 0) {
+            zombie_count--;
+            machmgr_handle_death(chldpid);
+         }
       }
 
       machmgr_update();
