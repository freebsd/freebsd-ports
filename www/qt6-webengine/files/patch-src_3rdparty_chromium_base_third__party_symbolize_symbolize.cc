--- src/3rdparty/chromium/base/third_party/symbolize/symbolize.cc.orig	2022-09-26 10:05:50 UTC
+++ src/3rdparty/chromium/base/third_party/symbolize/symbolize.cc
@@ -114,7 +114,7 @@ _END_GOOGLE_NAMESPACE_
 #if defined(HAVE_DLFCN_H)
 #include <dlfcn.h>
 #endif
-#if BUILDFLAG(IS_OPENBSD)
+#if defined(__OpenBSD__)
 #include <sys/exec_elf.h>
 #else
 #include <elf.h>
