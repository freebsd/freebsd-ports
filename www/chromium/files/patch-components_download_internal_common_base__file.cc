--- components/download/internal/common/base_file.cc.orig	2019-07-24 18:58:19 UTC
+++ components/download/internal/common/base_file.cc
@@ -516,7 +516,7 @@ DownloadInterruptReason BaseFile::PublishDownload() {
 }
 #endif  // defined(OS_ANDROID)
 
-#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
 
 namespace {
 
@@ -600,7 +600,7 @@ DownloadInterruptReason BaseFile::AnnotateWithSourceIn
   }
   return DOWNLOAD_INTERRUPT_REASON_FILE_FAILED;
 }
-#else  // !OS_WIN && !OS_MACOSX && !OS_LINUX
+#else  // !OS_WIN && !OS_MACOSX && !OS_LINUX && !OS_BSD
 DownloadInterruptReason BaseFile::AnnotateWithSourceInformation(
     const std::string& client_guid,
     const GURL& source_url,
