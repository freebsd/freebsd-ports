- Implement runtime detection on FreeBSD

--- aom_ports/riscv_cpudetect.c.orig	2025-09-05 22:10:37 UTC
+++ aom_ports/riscv_cpudetect.c
@@ -23,6 +23,20 @@
 
 #define HWCAP_RVV (1 << ('v' - 'a'))
 
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
 int riscv_simd_caps(void) {
   int flags = 0;
 #if HAVE_RVV
