--- third_party/glog/src/stacktrace_powerpc-inl.h.orig	2026-06-20 03:41:08 UTC
+++ third_party/glog/src/stacktrace_powerpc-inl.h
@@ -117,6 +117,8 @@
 #elif defined(__linux)
       // This check is in case the compiler doesn't define _CALL_SYSV.
       result[n++] = *(sp+1);
+#elif defined(_CALL_ELF)
+      result[n++] = *(sp+2);
 #else
 #error Need to specify the PPC ABI for your archiecture.
 #endif
