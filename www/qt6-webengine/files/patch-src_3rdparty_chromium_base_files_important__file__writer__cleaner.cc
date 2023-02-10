--- src/3rdparty/chromium/base/files/important_file_writer_cleaner.cc.orig	2022-09-26 10:05:50 UTC
+++ src/3rdparty/chromium/base/files/important_file_writer_cleaner.cc
@@ -25,7 +25,8 @@ base::Time GetUpperBoundTime() {
 namespace {
 
 base::Time GetUpperBoundTime() {
-#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_IOS) || BUILDFLAG(IS_FUCHSIA)
+// needed because of .CreationTime() pledge
+#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_IOS) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
   // If process creation time is not available then use instance creation
   // time as the upper-bound for old files. Modification times may be
   // rounded-down to coarse-grained increments, e.g. FAT has 2s granularity,
