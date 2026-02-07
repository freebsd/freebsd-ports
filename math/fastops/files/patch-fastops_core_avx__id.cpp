--- fastops/core/avx_id.cpp.orig	2020-05-06 07:23:43 UTC
+++ fastops/core/avx_id.cpp
@@ -36,23 +36,23 @@ namespace NFastOps {
         // This in EBX of cpuid(7)
         static constexpr uint32_t AVX2_BIT    = 0x00000020;
 
-        static void CpuId(int32_t op, int32_t* res) noexcept {
+        static void CpuId(int32_t op, int32_t sub, int32_t* res) noexcept {
 #if defined(_MSC_VER) && !defined(__clang__)
-            __cpuid((int*)res, op);
+            __cpuidex((int*)res, op, sub);
 #else
-            __cpuid(op, res[EAX], res[EBX], res[ECX], res[EDX]);
+            __cpuid_count(op, sub, res[EAX], res[EBX], res[ECX], res[EDX]);
 #endif
         }
 
         bool IsAVXEnabled() noexcept {
             int32_t info[NREGS];
-            CpuId(1, info);
+            CpuId(1, 0, info);
             return (info[ECX] & OSXSAVE_BIT) && IsYMMSaveEnabled() && (info[ECX] & AVX_BIT);
         }
 
         bool IsAVX2Enabled() noexcept {
             int32_t info[NREGS];
-            CpuId(7, info);
+            CpuId(7, 0, info);
             return info[EBX] & AVX2_BIT;
         }
     }
