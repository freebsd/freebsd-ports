--- content/browser/download/base_file.cc.orig	2016-05-25 15:01:01.000000000 -0400
+++ content/browser/download/base_file.cc	2016-05-27 10:51:20.693194000 -0400
@@ -186,7 +186,8 @@
 }
 
 // OS_WIN, OS_MACOSX and OS_LINUX have specialized implementations.
-#if !defined(OS_WIN) && !defined(OS_MACOSX) && !defined(OS_LINUX)
+#if !defined(OS_WIN) && !defined(OS_MACOSX) && !defined(OS_LINUX) && \
+    !defined(OS_BSD)
 DownloadInterruptReason BaseFile::AnnotateWithSourceInformation(
     const std::string& client_guid,
     const GURL& source_url,
