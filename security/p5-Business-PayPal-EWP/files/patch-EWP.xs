--- EWP.xs.orig	2004-12-07 07:42:37.000000000 -0800
+++ EWP.xs	2008-02-28 21:56:45.000000000 -0800
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
