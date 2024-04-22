--- src/3rdparty/chromium/v8/src/codegen/arm/cpu-arm.cc.orig	2023-11-20 16:08:07 UTC
+++ src/3rdparty/chromium/v8/src/codegen/arm/cpu-arm.cc
@@ -3,6 +3,10 @@
 // found in the LICENSE file.
 
 // CPU specific code for arm independent of OS goes here.
+#if V8_TARGET_ARCH_ARM
+
+#include "src/codegen/cpu-features.h"
+
 #ifdef __arm__
 #ifdef __QNXNTO__
 #include <sys/mman.h>  // for cache flushing.
@@ -16,10 +20,6 @@
 #include <sys/syscall.h>  // for cache flushing.
 #endif
 #endif
-
-#if V8_TARGET_ARCH_ARM
-
-#include "src/codegen/cpu-features.h"
 
 namespace v8 {
 namespace internal {
