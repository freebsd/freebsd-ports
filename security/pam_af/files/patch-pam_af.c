--- pam_af.c.orig	2008-08-02 20:34:30.000000000 +0400
+++ pam_af.c	2008-08-02 20:34:36.000000000 +0400
@@ -53,7 +53,7 @@
 
 #include <security/pam_appl.h>
 #include <security/pam_modules.h>
-#ifdef _OPENPAM
+#ifdef OPENPAM
 # include <security/openpam.h>
 # include <security/pam_mod_misc.h>
 #endif
