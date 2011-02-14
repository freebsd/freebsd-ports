--- ./src/env.c.orig	2008-12-16 16:44:38.000000000 -0500
+++ ./src/env.c	2011-02-09 20:52:34.000000000 -0500
@@ -32,7 +32,7 @@
 #ifdef HAVE_PAM
 pam_handle_t *pamh;
 static struct pam_conv conv = {
-  misc_conv,
+  openpam_ttyconv,
   NULL
 };
 #endif /* HAVE_PAM */
