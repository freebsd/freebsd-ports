--- ./content/browser/download/base_file.cc.orig	2014-08-12 21:01:23.000000000 +0200
+++ ./content/browser/download/base_file.cc	2014-08-13 09:56:57.000000000 +0200
@@ -204,7 +204,8 @@
 }
 
 // OS_WIN, OS_MACOSX and OS_LINUX have specialized implementations.
-#if !defined(OS_WIN) && !defined(OS_MACOSX) && !defined(OS_LINUX)
+#if !defined(OS_WIN) && !defined(OS_MACOSX) && !defined(OS_LINUX) && \
+    !defined(OS_BSD)
 DownloadInterruptReason BaseFile::AnnotateWithSourceInformation() {
   return DOWNLOAD_INTERRUPT_REASON_NONE;
 }
