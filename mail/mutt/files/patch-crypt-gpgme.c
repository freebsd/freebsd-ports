--- ./crypt-gpgme.c.orig	2009-07-01 21:28:51.000000000 -0400
+++ ./crypt-gpgme.c	2009-07-01 21:31:52.000000000 -0400
@@ -342,6 +342,7 @@
   gpgme_error_t err;
   gpgme_ctx_t ctx;
 
+  gpgme_check_version (NULL);
   if (!GpgmeLocaleSet)
   {
     gpgme_set_locale (NULL, LC_CTYPE, setlocale (LC_CTYPE, NULL));
