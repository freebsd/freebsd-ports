--- src/3rdparty/chromium/base/threading/platform_thread_internal_posix.cc.orig	2023-09-13 12:11:42 UTC
+++ src/3rdparty/chromium/base/threading/platform_thread_internal_posix.cc
@@ -41,7 +41,7 @@ ThreadPriorityForTest NiceValueToThreadPriorityForTest
 }
 
 int GetCurrentThreadNiceValue() {
-#if BUILDFLAG(IS_NACL)
+#if BUILDFLAG(IS_NACL) || BUILDFLAG(IS_BSD)
   NOTIMPLEMENTED();
   return 0;
 #else
