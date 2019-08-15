--- base/cpu.cc.orig	2019-07-29 18:05:46 UTC
+++ base/cpu.cc
@@ -15,7 +15,7 @@
 #include "base/stl_util.h"
 #include "build/build_config.h"
 
-#if defined(ARCH_CPU_ARM_FAMILY) && (defined(OS_ANDROID) || defined(OS_LINUX))
+#if defined(ARCH_CPU_ARM_FAMILY) && (defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_BSD))
 #include "base/files/file_util.h"
 #endif
 
@@ -97,7 +97,7 @@ uint64_t xgetbv(uint32_t xcr) {
 
 #endif  // ARCH_CPU_X86_FAMILY
 
-#if defined(ARCH_CPU_ARM_FAMILY) && (defined(OS_ANDROID) || defined(OS_LINUX))
+#if defined(ARCH_CPU_ARM_FAMILY) && (defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_BSD))
 std::string* CpuInfoBrand() {
   static std::string* brand = []() {
     // This function finds the value from /proc/cpuinfo under the key "model
@@ -127,7 +127,7 @@ std::string* CpuInfoBrand() {
   return brand;
 }
 #endif  // defined(ARCH_CPU_ARM_FAMILY) && (defined(OS_ANDROID) ||
-        // defined(OS_LINUX))
+        // defined(OS_LINUX) || defined(OS_BSD))
 
 }  // namespace
 
@@ -252,7 +252,7 @@ void CPU::Initialize() {
     }
   }
 #elif defined(ARCH_CPU_ARM_FAMILY)
-#if (defined(OS_ANDROID) || defined(OS_LINUX))
+#if (defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_BSD))
   cpu_brand_ = *CpuInfoBrand();
 #elif defined(OS_WIN)
   // Windows makes high-resolution thread timing information available in
