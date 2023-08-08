--- third_party/fbgemm/third_party/asmjit/src/asmjit/core/virtmem.cpp.orig	2022-12-16 00:23:48 UTC
+++ third_party/fbgemm/third_party/asmjit/src/asmjit/core/virtmem.cpp
@@ -45,6 +45,7 @@
 #endif
 
 #include <atomic>
+#include <sys/stat.h>
 
 #if defined(__APPLE__) || defined(__BIONIC__)
   #define ASMJIT_VM_SHM_DETECT 0
