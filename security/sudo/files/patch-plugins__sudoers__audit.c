--- ./plugins/sudoers/audit.c.orig	2013-06-04 11:48:28.000000000 +0200
+++ ./plugins/sudoers/audit.c	2013-07-05 13:10:01.000000000 +0200
@@ -39,6 +39,7 @@
 
 #ifdef HAVE_BSM_AUDIT
 # include "bsm_audit.h"
+# include "gettext.h"
 #endif
 #ifdef HAVE_LINUX_AUDIT
 # include "linux_audit.h"
