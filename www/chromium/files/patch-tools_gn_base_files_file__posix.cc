--- tools/gn/base/files/file_posix.cc.orig	2018-12-12 23:06:54.000000000 +0100
+++ tools/gn/base/files/file_posix.cc	2018-12-15 21:58:11.127692000 +0100
@@ -86,7 +86,7 @@
   is_symbolic_link = S_ISLNK(stat_info.st_mode);
   size = stat_info.st_size;
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   time_t last_modified_sec = stat_info.st_mtim.tv_sec;
   int64_t last_modified_nsec = stat_info.st_mtim.tv_nsec;
   time_t last_accessed_sec = stat_info.st_atim.tv_sec;
