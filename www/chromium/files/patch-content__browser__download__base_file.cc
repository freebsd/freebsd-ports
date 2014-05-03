--- ./content/browser/download/base_file.cc.orig	2014-04-24 22:35:46.000000000 +0200
+++ ./content/browser/download/base_file.cc	2014-04-24 23:23:44.000000000 +0200
@@ -216,7 +216,8 @@
 }
 
 // OS_WIN, OS_MACOSX and OS_LINUX have specialized implementations.
-#if !defined(OS_WIN) && !defined(OS_MACOSX) && !defined(OS_LINUX)
+#if !defined(OS_WIN) && !defined(OS_MACOSX) && !defined(OS_LINUX) && \
+    !defined(OS_BSD)
 DownloadInterruptReason BaseFile::AnnotateWithSourceInformation() {
   return DOWNLOAD_INTERRUPT_REASON_NONE;
 }
