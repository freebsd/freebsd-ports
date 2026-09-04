--- auxil/spicy/3rdparty/fiber/include/fiber/fiber_mach.h.orig	2026-09-04 12:06:27 UTC
+++ auxil/spicy/3rdparty/fiber/include/fiber/fiber_mach.h	2026-09-04 12:06:27 UTC
@@ -104,7 +104,7 @@
         void *s[12];                                                           \
         double fs[12]
 
-#elif HU_ARCH_PPC_P && HU_BITS_64_P && HU_LITTLE_ENDIAN_P && HU_OBJFMT_ELF_P
+#elif HU_ARCH_PPC_P && HU_BITS_64_P && HU_OBJFMT_ELF_P
 #    define FIBER_TARGET_PPC64LE_ELF 1
 #    define FIBER_DEFAULT_STACK_ALIGNMENT 16
 #    if !defined(_CALL_ELF) || _CALL_ELF != 2
