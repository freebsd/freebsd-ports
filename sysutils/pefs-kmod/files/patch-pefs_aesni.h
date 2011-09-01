--- sys/fs/pefs/pefs_aesni.h.orig
+++ sys/fs/pefs/pefs_aesni.h
@@ -26,6 +26,8 @@
  * $FreeBSD$
  */
 
+#ifdef PEFS_AESNI
+
 #include <crypto/aesni/aesni.h>
 
 struct pefs_aesni_ctx {
@@ -41,3 +43,5 @@ struct pefs_aesni_ses {
 };
 
 algop_init_t	pefs_aesni_init;
+
+#endif
