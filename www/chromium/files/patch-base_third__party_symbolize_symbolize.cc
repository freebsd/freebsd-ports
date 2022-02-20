--- base/third_party/symbolize/symbolize.cc.orig	2022-02-07 13:39:41 UTC
+++ base/third_party/symbolize/symbolize.cc
@@ -113,7 +113,7 @@ _END_GOOGLE_NAMESPACE_
 #if defined(HAVE_DLFCN_H)
 #include <dlfcn.h>
 #endif
-#if defined(OS_OPENBSD)
+#if defined(__OpenBSD__)
 #include <sys/exec_elf.h>
 #else
 #include <elf.h>
