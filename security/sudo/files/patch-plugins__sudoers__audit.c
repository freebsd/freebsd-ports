--- plugins/sudoers/audit.c.orig	2015-07-15 18:44:07 UTC
+++ plugins/sudoers/audit.c
@@ -24,6 +24,7 @@
 
 #ifdef HAVE_BSM_AUDIT
 # include "bsm_audit.h"
+# include "sudo_gettext.h"
 #endif
 #ifdef HAVE_LINUX_AUDIT
 # include "linux_audit.h"
