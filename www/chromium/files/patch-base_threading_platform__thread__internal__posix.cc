--- base/threading/platform_thread_internal_posix.cc.orig	2025-08-07 06:57:29 UTC
+++ base/threading/platform_thread_internal_posix.cc
@@ -31,7 +31,7 @@ ThreadPriorityForTest NiceValueToThreadPriorityForTest
 }
 
 int GetCurrentThreadNiceValue() {
-#if BUILDFLAG(IS_NACL)
+#if BUILDFLAG(IS_NACL) || BUILDFLAG(IS_BSD)
   NOTIMPLEMENTED();
   return 0;
 #else
