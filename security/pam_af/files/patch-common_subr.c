--- common/subr.c.orig	2008-08-02 20:33:51.000000000 +0400
+++ common/subr.c	2008-08-02 20:34:25.000000000 +0400
@@ -66,7 +66,7 @@
 # define LOGERR(...) warnx(__VA_ARGS__)
 #else /* !PAM_AF_DEFS */
 # include <security/pam_appl.h>
-# ifdef _OPENPAM
+# ifdef OPENPAM
 #  include <security/pam_mod_misc.h>
 #  include <security/openpam.h>
 # endif
