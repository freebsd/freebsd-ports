--- base/path_service_unittest.cc.orig	2020-07-07 21:57:30 UTC
+++ base/path_service_unittest.cc
@@ -37,7 +37,7 @@ bool ReturnsValidPath(int dir_type) {
   if (dir_type == DIR_CACHE)
     check_path_exists = false;
 #endif
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // On the linux try-bots: a path is returned (e.g. /home/chrome-bot/Desktop),
   // but it doesn't exist.
   if (dir_type == DIR_USER_DESKTOP)
