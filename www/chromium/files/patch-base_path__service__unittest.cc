--- base/path_service_unittest.cc.orig	2021-12-31 00:57:18 UTC
+++ base/path_service_unittest.cc
@@ -46,7 +46,7 @@ bool ReturnsValidPath(int key) {
   if (key == DIR_CACHE)
     check_path_exists = false;
 #endif
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   // On the linux try-bots: a path is returned (e.g. /home/chrome-bot/Desktop),
   // but it doesn't exist.
   if (key == DIR_USER_DESKTOP)
