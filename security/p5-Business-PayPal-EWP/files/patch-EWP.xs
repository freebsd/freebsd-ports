--- EWP.xs.old	Thu May 12 10:40:14 2005
+++ EWP.xs	Thu May 12 10:41:55 2005
@@ -126,8 +126,10 @@
 		PKCS7_free(p7);
 	if (bio)
 		BIO_free_all(bio);
+#if 0
 	if (memBio)
 		BIO_free_all(memBio);
+#endif
 	if (p7bio)
 		BIO_free_all(p7bio);
 	if (pkey)
