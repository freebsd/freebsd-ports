--- aeron-client/src/main/cpp/util/Platform.h.orig	2026-06-08 19:08:57 UTC
+++ aeron-client/src/main/cpp/util/Platform.h
@@ -48,6 +48,10 @@
         #endif
     #endif
 
+    #if defined(__powerpc64__)
+        #define AERON_CPU_PPC64 1
+    #endif
+
 #else
     #error Unsupported compiler!
 #endif
