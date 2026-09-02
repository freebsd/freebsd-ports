--- third_party/xla/xla/backends/cpu/codegen/builtin_fp16.h.orig	2026-03-04 22:33:50 UTC
+++ third_party/xla/xla/backends/cpu/codegen/builtin_fp16.h
@@ -16,6 +16,8 @@
 #ifndef XLA_BACKENDS_CPU_CODEGEN_BUILTIN_FP16_H_
 #define XLA_BACKENDS_CPU_CODEGEN_BUILTIN_FP16_H_
 
+#include <cstdint>
+
 // _Float16 always gets us the correct ABI type, so use that if available.
 // AArch64 GCC defines __FLT16_MANT_DIG__ even when _Float16 is not available.
 #if defined(__FLT16_MANT_DIG__) && \
