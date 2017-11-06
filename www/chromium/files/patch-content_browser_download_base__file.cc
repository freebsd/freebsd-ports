--- content/browser/download/base_file.cc.orig	2017-06-05 19:03:06 UTC
+++ content/browser/download/base_file.cc
@@ -387,7 +387,7 @@ DownloadInterruptReason BaseFile::LogInterruptReason(
   return reason;
 }
 
-#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
 
 namespace {
 
@@ -470,7 +470,7 @@ DownloadInterruptReason BaseFile::AnnotateWithSourceIn
   }
   return DOWNLOAD_INTERRUPT_REASON_FILE_FAILED;
 }
-#else  // !OS_WIN && !OS_MACOSX && !OS_LINUX
+#else  // !OS_WIN && !OS_MACOSX && !OS_LINUX && !OS_BSD
 DownloadInterruptReason BaseFile::AnnotateWithSourceInformation(
     const std::string& client_guid,
     const GURL& source_url,
