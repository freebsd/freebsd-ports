--- base/threading/platform_thread_internal_posix.cc.orig	2024-03-22 08:19:40 UTC
+++ base/threading/platform_thread_internal_posix.cc
@@ -42,7 +42,7 @@ ThreadPriorityForTest NiceValueToThreadPriorityForTest
 }
 
 int GetCurrentThreadNiceValue() {
-#if BUILDFLAG(IS_NACL)
+#if BUILDFLAG(IS_NACL) || BUILDFLAG(IS_BSD)
   NOTIMPLEMENTED();
   return 0;
 #else
