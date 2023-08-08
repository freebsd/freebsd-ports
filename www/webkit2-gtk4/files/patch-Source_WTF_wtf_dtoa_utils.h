Index: Source/WTF/wtf/dtoa/utils.h
--- Source/WTF/wtf/dtoa/utils.h.orig
+++ Source/WTF/wtf/dtoa/utils.h
@@ -87,7 +87,7 @@ int main(int argc, char** argv) {
     defined(__powerpc__) || defined(__ppc__) || defined(__ppc64__) || \
     defined(_POWER) || defined(_ARCH_PPC) || defined(_ARCH_PPC64) || \
     defined(__sparc__) || defined(__sparc) || defined(__s390__) || \
-    defined(__SH4__) || defined(__alpha__) || \
+    defined(__SH4__) || defined(__alpha__) || defined(__sparc64__) || \
     defined(_MIPS_ARCH_MIPS32R2) || \
     defined(__AARCH64EL__) || defined(__aarch64__) || defined(__AARCH64EB__) || \
     defined(__riscv) || \
