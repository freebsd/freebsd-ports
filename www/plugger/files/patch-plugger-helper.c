--- plugger-helper.c.old	Wed Feb 11 16:19:27 2004
+++ plugger-helper.c	Wed Feb 11 16:20:30 2004
@@ -76,7 +76,7 @@
 
 static void very_low_run(char **argv)
 {
-  setpgrp();
+  setpgrp(0, 0);
 #ifdef H_NOISY
   if(flags & H_NOISY)
   {
