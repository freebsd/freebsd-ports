--- src/3rdparty/chromium/third_party/dav1d/libdav1d/src/cpu.c.orig	2025-12-22 23:24:20 UTC
+++ src/3rdparty/chromium/third_party/dav1d/libdav1d/src/cpu.c
@@ -115,7 +115,18 @@ COLD unsigned long dav1d_getauxval(unsigned long type)
 
 COLD unsigned long dav1d_getauxval(unsigned long type) {
 #if HAVE_GETAUXVAL
+#if defined(__FreeBSD__) && (ARCH_AARCH64 || ARCH_ARM)
+    /* Only AT_HWCAP* return unsigned long */
+    if (type != AT_HWCAP && type != AT_HWCAP2) {
+        return 0;
+    }
+
+    unsigned long ret = 0;
+    elf_aux_info(type, &ret, sizeof(ret));
+    return ret;
+#else
     return getauxval(type);
+#endif
 #elif HAVE_ELF_AUX_INFO
     unsigned long aux = 0;
     int ret = elf_aux_info(type, &aux, sizeof(aux));
