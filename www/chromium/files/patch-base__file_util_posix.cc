--- ./base/file_util_posix.cc.orig	2014-04-24 22:36:11.000000000 +0200
+++ ./base/file_util_posix.cc	2014-04-24 23:23:41.000000000 +0200
@@ -672,7 +672,7 @@
 #endif  // defined(OS_ANDROID)
   results->is_directory = S_ISDIR(file_info.st_mode);
   results->size = file_info.st_size;
-#if defined(OS_MACOSX)
+#if defined(OS_MACOSX) || (defined(OS_FREEBSD) && __FreeBSD_version < 900000)
   results->last_modified = Time::FromTimeSpec(file_info.st_mtimespec);
   results->last_accessed = Time::FromTimeSpec(file_info.st_atimespec);
   results->creation_time = Time::FromTimeSpec(file_info.st_ctimespec);
