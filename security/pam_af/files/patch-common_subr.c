--- common/subr.c.orig	2006-11-07 03:22:37.000000000 +0300
+++ common/subr.c	2008-08-03 12:00:42.000000000 +0400
@@ -66,7 +66,7 @@
 # define LOGERR(...) warnx(__VA_ARGS__)
 #else /* !PAM_AF_DEFS */
 # include <security/pam_appl.h>
-# ifdef _OPENPAM
+# if defined(OPENPAM) || defined(_OPENPAM)
 #  include <security/pam_mod_misc.h>
 #  include <security/openpam.h>
 # endif
