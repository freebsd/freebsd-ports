--- src/rw-sleep.c.orig	2021-04-23 23:23:16 UTC
+++ src/rw-sleep.c
@@ -5,6 +5,7 @@
 #include <limits.h>
 #include <signal.h>
 
+#include <skalibs/exec.h>
 #include <skalibs/stddjb.h>
 #include "prjlibs-include/constants.h"
 #include "prjlibs-include/diewarn.h"
@@ -36,7 +37,7 @@ int main(int argc, char** argv) {
     timer.it_value.tv_sec=0;
     timer.it_value.tv_usec=0;
   } else {
-    tain_t now, wake_time;
+    tain now, wake_time;
     tain_now(&now);
     rw_scan(&wake_time, argv[1]);
     if (tain_less(&wake_time, &now)) flag_sleep=0;
