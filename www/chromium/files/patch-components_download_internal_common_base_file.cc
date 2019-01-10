--- components/download/internal/common/base_file.cc.orig	2019-01-09 12:22:40.588572000 +0100
+++ components/download/internal/common/base_file.cc	2019-01-09 12:23:00.218681000 +0100
@@ -446,7 +446,7 @@
   return reason;
 }
 
-#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
 
 namespace {
 
