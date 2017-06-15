--- src/env.c.orig	2014-05-17 20:26:43 UTC
+++ src/env.c
@@ -30,7 +30,7 @@
 #ifdef HAVE_PAM
 pam_handle_t *pamh;
 static struct pam_conv conv = {
-  misc_conv,
+  openpam_ttyconv,
   NULL
 };
 #endif /* HAVE_PAM */
