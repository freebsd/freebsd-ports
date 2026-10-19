See patch-auxil_spicy_3rdparty_fiber_CMakeLists.txt.

--- auxil/spicy/3rdparty/fiber/include/fiber/fiber_mach.h.orig	2026-10-18 17:10:38 UTC
+++ auxil/spicy/3rdparty/fiber/include/fiber/fiber_mach.h
@@ -104,8 +104,8 @@
         void *s[12];                                                           \
         double fs[12]
 
-#elif HU_ARCH_PPC_P && HU_BITS_64_P && HU_LITTLE_ENDIAN_P && HU_OBJFMT_ELF_P
-#    define FIBER_TARGET_PPC64LE_ELF 1
+#elif HU_ARCH_PPC_P && HU_BITS_64_P && HU_OBJFMT_ELF_P
+#    define FIBER_TARGET_PPC64_ELF 1
 #    define FIBER_DEFAULT_STACK_ALIGNMENT 16
 #    if !defined(_CALL_ELF) || _CALL_ELF != 2
 #        error "this PowerPC ABI is not supported, use -mabi=elfv2"
