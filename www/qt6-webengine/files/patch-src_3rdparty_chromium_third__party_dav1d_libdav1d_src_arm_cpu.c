--- src/3rdparty/chromium/third_party/dav1d/libdav1d/src/arm/cpu.c.orig	2025-05-29 01:27:28 UTC
+++ src/3rdparty/chromium/third_party/dav1d/libdav1d/src/arm/cpu.c
@@ -35,6 +35,20 @@
 #if defined(HAVE_GETAUXVAL) || defined(HAVE_ELF_AUX_INFO)
 #include <sys/auxv.h>
 
+#if defined(__FreeBSD__)
+static unsigned long getauxval(unsigned long type)
+{
+    /* Only AT_HWCAP* return unsigned long */
+    if (type != AT_HWCAP && type != AT_HWCAP2) {
+        return 0;
+    }
+
+    unsigned long ret = 0;
+    elf_aux_info(type, &ret, sizeof(ret));
+    return ret;
+}
+#endif
+
 #if ARCH_AARCH64
 
 #define HWCAP_AARCH64_ASIMDDP (1 << 20)
