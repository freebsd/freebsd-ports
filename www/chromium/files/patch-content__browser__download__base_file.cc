--- content/browser/download/base_file.cc.orig	2014-10-10 08:54:14 UTC
+++ content/browser/download/base_file.cc
@@ -208,7 +208,8 @@
 }
 
 // OS_WIN, OS_MACOSX and OS_LINUX have specialized implementations.
-#if !defined(OS_WIN) && !defined(OS_MACOSX) && !defined(OS_LINUX)
+#if !defined(OS_WIN) && !defined(OS_MACOSX) && !defined(OS_LINUX) && \
+    !defined(OS_BSD)
 DownloadInterruptReason BaseFile::AnnotateWithSourceInformation() {
   return DOWNLOAD_INTERRUPT_REASON_NONE;
 }
