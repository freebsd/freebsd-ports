--- Config-staff.cc.orig	Fri Feb 21 10:27:31 2003
+++ Config-staff.cc	Fri Feb 21 10:27:47 2003
@@ -342,7 +342,7 @@
   PUTERR(1, ("Generating a %d bit RSA private key\n", bits));
 
   EVP_PKEY *pkey = 0;
-  EVP_MD   *digest = EVP_md5();
+  const EVP_MD   *digest = EVP_md5();
   X509 *x509 = 0;
   X509_NAME *n = 0;
   X509_NAME_ENTRY *ne = 0;
