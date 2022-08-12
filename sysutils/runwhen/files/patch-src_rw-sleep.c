--- src/rw-sleep.c.orig	2022-08-10 16:08:24 UTC
+++ src/rw-sleep.c
@@ -36,7 +36,7 @@ int main(int argc, char** argv) {
     timer.it_value.tv_sec=0;
     timer.it_value.tv_usec=0;
   } else {
-    tain_t now, wake_time;
+    tain now, wake_time;
     tain_now(&now);
     rw_scan(&wake_time, argv[1]);
     if (tain_less(&wake_time, &now)) flag_sleep=0;
