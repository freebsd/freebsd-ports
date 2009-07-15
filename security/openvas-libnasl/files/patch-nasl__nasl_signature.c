--- ./nasl/nasl_signature.c.orig	2009-07-01 23:08:30.000000000 -0400
+++ ./nasl/nasl_signature.c	2009-07-01 23:09:42.000000000 -0400
@@ -131,6 +131,8 @@
   gpgme_data_t sig = NULL, text = NULL;
   char * gpghome = determine_gpghome();
 
+  gpgme_check_version (NULL);
+
   err = gpgme_engine_check_version(GPGME_PROTOCOL_OpenPGP);
   if (err)
     {
