--- base/threading/platform_thread_internal_posix.cc.orig	2024-10-22 08:31:56 UTC
+++ base/threading/platform_thread_internal_posix.cc
@@ -41,7 +41,7 @@ ThreadPriorityForTest NiceValueToThreadPriorityForTest
 }
 
 int GetCurrentThreadNiceValue() {
-#if BUILDFLAG(IS_NACL)
+#if BUILDFLAG(IS_NACL) || BUILDFLAG(IS_BSD)
   NOTIMPLEMENTED();
   return 0;
 #else
