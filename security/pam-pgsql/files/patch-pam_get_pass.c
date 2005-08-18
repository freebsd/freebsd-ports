--- pam_get_pass.c.orig	Wed May 25 21:02:56 2005
+++ pam_get_pass.c	Thu Aug 18 21:25:11 2005
@@ -34,7 +34,16 @@
 #include <stdlib.h>
 #include <string.h>
 #include <security/pam_modules.h>
+#include <security/pam_appl.h>
 #include "pam_mod_misc.h"
+
+#ifdef __FreeBSD__
+#include <sys/param.h>
+#endif
+
+#if (defined(__FreeBSD__) && __FreeBSD_version > 500000)
+#define PAM_AUTHTOK_RECOVER_ERR PAM_AUTHTOK_RECOVERY_ERR
+#endif
 
 static int
 pam_conv_pass(pam_handle_t *pamh, int pam_item, const char *prompt, int options)
