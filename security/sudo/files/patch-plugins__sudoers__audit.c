--- plugins/sudoers/audit.c.orig	2014-09-24 01:40:15.000000000 +0900
+++ plugins/sudoers/audit.c	2014-10-10 07:24:43.000000000 +0900
@@ -42,6 +42,7 @@
 
 #ifdef HAVE_BSM_AUDIT
 # include "bsm_audit.h"
+# include "sudo_gettext.h"
 #endif
 #ifdef HAVE_LINUX_AUDIT
 # include "linux_audit.h"
