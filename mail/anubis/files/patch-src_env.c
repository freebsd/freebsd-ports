--- src/env.c.orig	2024-01-05 16:10:48 UTC
+++ src/env.c
@@ -31,7 +31,7 @@ static struct pam_conv conv = {
 # define USE_PAM 1
 pam_handle_t *pamh;
 static struct pam_conv conv = {
-  misc_conv,
+  openpam_ttyconv,
   NULL
 };
 #else
