--- cmake/modules/Architecture.cmake.orig	2022-02-26 20:04:54 UTC
+++ cmake/modules/Architecture.cmake
@@ -1,7 +1,7 @@
 # Setup
 set(ARCH_INSTR_32 "i386;i686;x86;arm;ARM")
-set(ARCH_INSTR_64 "x86_64;AMD64;IA64;arm64;ARM64")
-set(ARCH_INSTR_X86 "i386;i686;x86;x86_64;AMD64")
+set(ARCH_INSTR_64 "x86_64;amd64;AMD64;IA64;arm64;ARM64")
+set(ARCH_INSTR_X86 "i386;i686;x86;x86_64;amd64;AMD64")
 set(ARCH_INSTR_ARM "arm;ARM;arm64;ARM64")
 set(ARCH_INSTR_ITANIUM "IA64")
 set(ARCH_BITS 0)
