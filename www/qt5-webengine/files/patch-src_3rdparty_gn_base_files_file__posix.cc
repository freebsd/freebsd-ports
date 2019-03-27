--- src/3rdparty/gn/base/files/file_posix.cc.orig	2018-11-13 18:25:11 UTC
+++ src/3rdparty/gn/base/files/file_posix.cc
@@ -86,7 +86,7 @@ void File::Info::FromStat(const stat_wrapper_t& stat_i
   is_symbolic_link = S_ISLNK(stat_info.st_mode);
   size = stat_info.st_size;
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   time_t last_modified_sec = stat_info.st_mtim.tv_sec;
   int64_t last_modified_nsec = stat_info.st_mtim.tv_nsec;
   time_t last_accessed_sec = stat_info.st_atim.tv_sec;
