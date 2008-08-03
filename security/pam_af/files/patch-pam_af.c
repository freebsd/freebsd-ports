--- pam_af.c.orig	2006-11-07 03:05:53.000000000 +0300
+++ pam_af.c	2008-08-03 12:03:49.000000000 +0400
@@ -53,7 +53,7 @@
 
 #include <security/pam_appl.h>
 #include <security/pam_modules.h>
-#ifdef _OPENPAM
+#if defined(OPENPAM) || defined(_OPENPAM)
 # include <security/openpam.h>
 # include <security/pam_mod_misc.h>
 #endif
