--- content/browser/download/base_file.cc.orig	2017-03-09 20:04:32 UTC
+++ content/browser/download/base_file.cc
@@ -370,7 +370,7 @@ DownloadInterruptReason BaseFile::LogInt
   return reason;
 }
 
-#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
 
 namespace {
 
@@ -453,7 +453,7 @@ DownloadInterruptReason BaseFile::Annota
   }
   return DOWNLOAD_INTERRUPT_REASON_FILE_FAILED;
 }
-#else  // !OS_WIN && !OS_MACOSX && !OS_LINUX
+#else  // !OS_WIN && !OS_MACOSX && !OS_LINUX && !OS_BSD
 DownloadInterruptReason BaseFile::AnnotateWithSourceInformation(
     const std::string& client_guid,
     const GURL& source_url,
