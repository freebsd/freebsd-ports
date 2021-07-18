--- base/path_service_unittest.cc.orig	2021-04-14 18:40:48 UTC
+++ base/path_service_unittest.cc
@@ -38,7 +38,7 @@ bool ReturnsValidPath(int dir_type) {
   if (dir_type == DIR_CACHE)
     check_path_exists = false;
 #endif
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   // On the linux try-bots: a path is returned (e.g. /home/chrome-bot/Desktop),
   // but it doesn't exist.
   if (dir_type == DIR_USER_DESKTOP)
