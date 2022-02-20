--- base/files/important_file_writer_cleaner.cc.orig	2022-02-07 13:39:41 UTC
+++ base/files/important_file_writer_cleaner.cc
@@ -24,7 +24,8 @@ namespace base {
 namespace {
 
 base::Time GetUpperBoundTime() {
-#if defined(OS_ANDROID) || defined(OS_IOS) || defined(OS_FUCHSIA)
+// needed because of .CreationTime() pledge
+#if defined(OS_ANDROID) || defined(OS_IOS) || defined(OS_FUCHSIA) || defined(OS_BSD)
   // If process creation time is not available then use instance creation
   // time as the upper-bound for old files. Modification times may be
   // rounded-down to coarse-grained increments, e.g. FAT has 2s granularity,
