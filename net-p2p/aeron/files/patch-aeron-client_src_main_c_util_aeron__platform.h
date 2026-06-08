--- aeron-client/src/main/c/util/aeron_platform.h.orig	2025-11-24 19:20:55 UTC
+++ aeron-client/src/main/c/util/aeron_platform.h
@@ -48,6 +48,13 @@
         #endif
     #endif
 
+    #if defined(__powerpc64__)
+        #define AERON_CPU_PPC64 1
+        #if defined(__STDC_NO_ATOMICS__)
+            #error C11 atomics are required to compile for powerpc64!
+        #endif
+    #endif
+
 #else
     #error Unsupported compiler!
 #endif
