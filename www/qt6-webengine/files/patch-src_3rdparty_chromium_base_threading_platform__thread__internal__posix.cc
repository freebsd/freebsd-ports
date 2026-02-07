--- src/3rdparty/chromium/base/threading/platform_thread_internal_posix.cc.orig	2025-08-15 18:30:00 UTC
+++ src/3rdparty/chromium/base/threading/platform_thread_internal_posix.cc
@@ -41,7 +41,7 @@ int GetCurrentThreadNiceValue() {
 }
 
 int GetCurrentThreadNiceValue() {
-#if BUILDFLAG(IS_NACL)
+#if BUILDFLAG(IS_NACL) || BUILDFLAG(IS_BSD)
   NOTIMPLEMENTED();
   return 0;
 #else
