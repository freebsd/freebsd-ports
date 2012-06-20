--- sys/fs/pefs/pefs_aesni.h.orig
+++ sys/fs/pefs/pefs_aesni.h
@@ -26,6 +26,8 @@
  * $FreeBSD$
  */
 
+#ifdef PEFS_AESNI
+
 #include <crypto/aesni/aesni.h>
 
 struct pefs_aesni_ctx {
@@ -41,3 +43,5 @@
 	u_int			fpu_cpuid;
 	int			fpu_saved;
 };
+
+#endif
