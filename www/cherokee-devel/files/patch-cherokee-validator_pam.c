--- cherokee/validator_pam.c.orig	Wed Mar 30 02:15:14 2005
+++ cherokee/validator_pam.c	Fri Apr  1 14:51:10 2005
@@ -27,6 +27,9 @@
 
 #include <security/pam_appl.h>
 
+#include "connection.h"
+#include "connection-protected.h"
+
 
 cherokee_module_info_t cherokee_pam_info = {
 	cherokee_validator,           /* type     */
