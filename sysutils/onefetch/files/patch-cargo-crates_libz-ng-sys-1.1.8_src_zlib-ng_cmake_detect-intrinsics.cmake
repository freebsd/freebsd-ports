--- cargo-crates/libz-ng-sys-1.1.8/src/zlib-ng/cmake/detect-intrinsics.cmake.orig	1973-11-29 21:33:09 UTC
+++ cargo-crates/libz-ng-sys-1.1.8/src/zlib-ng/cmake/detect-intrinsics.cmake
@@ -280,8 +280,17 @@ macro(check_ppc_intrinsics)
     set(CMAKE_REQUIRED_FLAGS "${PPCFLAGS} ${NATIVEFLAG}")
     check_c_source_compiles(
         "#include <sys/auxv.h>
+        #ifdef __FreeBSD__
+        #include <machine/cpu.h>
+        #endif
         int main() {
+        #ifdef __FreeBSD__
+            unsigned long hwcap;
+            elf_aux_info(AT_HWCAP, &hwcap, sizeof(hwcap));
+            return (hwcap & PPC_FEATURE_HAS_ALTIVEC);
+        #else
             return (getauxval(AT_HWCAP) & PPC_FEATURE_HAS_ALTIVEC);
+        #endif
         }"
         HAVE_VMX
     )
@@ -298,8 +307,17 @@ macro(check_power8_intrinsics)
     set(CMAKE_REQUIRED_FLAGS "${POWER8FLAG} ${NATIVEFLAG}")
     check_c_source_compiles(
         "#include <sys/auxv.h>
+        #ifdef __FreeBSD__
+        #include <machine/cpu.h>
+        #endif
         int main() {
+        #ifdef __FreeBSD__
+            unsigned long hwcap;
+            elf_aux_info(AT_HWCAP2, &hwcap, sizeof(hwcap));
+            return (hwcap & PPC_FEATURE2_ARCH_2_07);
+        #else
             return (getauxval(AT_HWCAP2) & PPC_FEATURE2_ARCH_2_07);
+        #endif
         }"
         HAVE_POWER8_INTRIN
     )
