--- src/3rdparty/chromium/third_party/dav1d/libdav1d/src/arm/cpu.c.orig	2025-04-26 20:32:56 UTC
+++ src/3rdparty/chromium/third_party/dav1d/libdav1d/src/arm/cpu.c
@@ -84,10 +84,7 @@ COLD unsigned dav1d_get_cpu_flags_arm(void) {
     unsigned flags = 0;
 #if defined(__ARM_NEON) || defined(__APPLE__) || defined(_WIN32) || ARCH_AARCH64
     flags |= DAV1D_ARM_CPU_FLAG_NEON;
-#elif defined(HAVE_GETAUXVAL) && ARCH_ARM
-    unsigned long hw_cap = getauxval(AT_HWCAP);
-    flags |= (hw_cap & NEON_HWCAP) ? DAV1D_ARM_CPU_FLAG_NEON : 0;
-#elif defined(HAVE_ELF_AUX_INFO) && ARCH_ARM
+#elif defined(__FreeBSD__) && ARCH_ARM
     unsigned long hw_cap = 0;
     elf_aux_info(AT_HWCAP, &hw_cap, sizeof(hw_cap));
     flags |= (hw_cap & NEON_HWCAP) ? DAV1D_ARM_CPU_FLAG_NEON : 0;
