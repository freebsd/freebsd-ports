--- aeron-client/src/main/cpp_wrapper/util/Platform.h.orig	2025-11-24 19:20:55 UTC
+++ aeron-client/src/main/cpp_wrapper/util/Platform.h
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
