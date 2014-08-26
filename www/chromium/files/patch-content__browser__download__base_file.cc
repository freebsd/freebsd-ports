--- ./content/browser/download/base_file.cc.orig	2014-08-20 21:02:49.000000000 +0200
+++ ./content/browser/download/base_file.cc	2014-08-22 15:06:25.000000000 +0200
@@ -205,7 +205,8 @@
 }
 
 // OS_WIN, OS_MACOSX and OS_LINUX have specialized implementations.
-#if !defined(OS_WIN) && !defined(OS_MACOSX) && !defined(OS_LINUX)
+#if !defined(OS_WIN) && !defined(OS_MACOSX) && !defined(OS_LINUX) && \
+    !defined(OS_BSD)
 DownloadInterruptReason BaseFile::AnnotateWithSourceInformation() {
   return DOWNLOAD_INTERRUPT_REASON_NONE;
 }
