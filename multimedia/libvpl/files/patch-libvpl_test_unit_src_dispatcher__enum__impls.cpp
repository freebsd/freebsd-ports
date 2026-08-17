--- libvpl/test/unit/src/dispatcher_enum_impls.cpp.orig	2025-04-18 15:44:33 UTC
+++ libvpl/test/unit/src/dispatcher_enum_impls.cpp
@@ -30,7 +30,7 @@ typedef enum {
             #define STUB_RT "libvplstubrt64.dll"
         #endif
     #endif
-#elif defined(__linux__)
+#elif defined(__unix__)
     #define STUB_RT "libvplstubrt1x64.so"
 #endif
 
