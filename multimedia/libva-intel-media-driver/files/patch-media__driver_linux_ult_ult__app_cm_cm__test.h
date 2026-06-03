--- media_driver/linux/ult/ult_app/cm/cm_test.h.orig	2026-03-19 10:15:05 UTC
+++ media_driver/linux/ult/ult_app/cm/cm_test.h
@@ -23,7 +23,6 @@
 #ifndef MEDIADRIVER_LINUX_CODECHAL_ULT_ULTAPP_CMTEST_H_
 #define MEDIADRIVER_LINUX_CODECHAL_ULT_ULTAPP_CMTEST_H_
 
-#include <malloc.h>
 #include "gtest/gtest.h"
 #include "mock_device.h"
 #include "../memory_leak_detector.h"
@@ -34,7 +33,7 @@ class CmTest: public testing::Test (public)
 {
 public:
     static void* AllocateAlignedMemory(size_t size, size_t alignment)
-    { return memalign(alignment, size); }
+    { return aligned_alloc(alignment, size); }
 
     static void FreeAlignedMemory(void *memory) { free(memory); }
 
