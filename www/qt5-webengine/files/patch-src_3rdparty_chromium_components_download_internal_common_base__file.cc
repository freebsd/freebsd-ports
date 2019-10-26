--- src/3rdparty/chromium/components/download/internal/common/base_file.cc.orig	2019-05-23 12:39:34 UTC
+++ src/3rdparty/chromium/components/download/internal/common/base_file.cc
@@ -446,7 +446,7 @@ DownloadInterruptReason BaseFile::LogInterruptReason(
   return reason;
 }
 
-#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
 
 namespace {
 
