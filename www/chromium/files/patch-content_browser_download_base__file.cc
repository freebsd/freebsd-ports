--- content/browser/download/base_file.cc.orig	2016-12-12 21:09:50 UTC
+++ content/browser/download/base_file.cc
@@ -373,7 +373,7 @@ DownloadInterruptReason BaseFile::LogInt
   return reason;
 }
 
-#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
 
 namespace {
 
@@ -456,7 +456,7 @@ DownloadInterruptReason BaseFile::Annota
   }
   return DOWNLOAD_INTERRUPT_REASON_FILE_FAILED;
 }
-#else  // !OS_WIN && !OS_MACOSX && !OS_LINUX
+#else  // !OS_WIN && !OS_MACOSX && !OS_LINUX && !OS_BSD
 DownloadInterruptReason BaseFile::AnnotateWithSourceInformation(
     const std::string& client_guid,
     const GURL& source_url,
