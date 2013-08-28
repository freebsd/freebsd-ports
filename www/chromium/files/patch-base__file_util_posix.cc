--- base/file_util_posix.cc.orig	2013-08-19 01:53:01.000000000 +0200
+++ base/file_util_posix.cc	2013-08-28 10:18:48.000000000 +0200
@@ -592,7 +592,7 @@
     return false;
   results->is_directory = S_ISDIR(file_info.st_mode);
   results->size = file_info.st_size;
-#if defined(OS_MACOSX)
+#if defined(OS_MACOSX) || (defined(OS_FREEBSD) && __FreeBSD_version < 900000)
   results->last_modified = base::Time::FromTimeSpec(file_info.st_mtimespec);
   results->last_accessed = base::Time::FromTimeSpec(file_info.st_atimespec);
   results->creation_time = base::Time::FromTimeSpec(file_info.st_ctimespec);
