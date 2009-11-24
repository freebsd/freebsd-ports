--- ./Modules/constants.c.orig	2009-10-30 06:20:47.000000000 -0700
+++ ./Modules/constants.c	2009-11-24 11:36:43.304856749 -0800
@@ -1,6 +1,6 @@
 /* constants defined for LDAP
  * See http://www.python-ldap.org/ for details.
- * $Id: constants.c,v 1.43 2009/10/23 09:09:37 stroeder Exp $ */
+ * $Id: constants.c,v 1.45 2009/11/13 08:44:07 stroeder Exp $ */
 
 #include "common.h"
 #include "constants.h"
@@ -162,7 +162,9 @@
 	add_int(d,OPT_URI);
 #ifdef HAVE_TLS
 	add_int(d,OPT_X_TLS);
+#ifdef LDAP_OPT_X_TLS_NEWCTX
 	add_int(d,OPT_X_TLS_CTX);
+#endif
 	add_int(d,OPT_X_TLS_CACERTFILE);
 	add_int(d,OPT_X_TLS_CACERTDIR);
 	add_int(d,OPT_X_TLS_CERTFILE);
@@ -181,8 +183,10 @@
 	add_int(d,OPT_X_TLS_CRL_NONE);
 	add_int(d,OPT_X_TLS_CRL_PEER);
 	add_int(d,OPT_X_TLS_CRL_ALL);
+#ifdef LDAP_OPT_X_TLS_NEWCTX
 	add_int(d,OPT_X_TLS_NEWCTX);
-#ifdef OPT_X_TLS_PROTOCOL_MIN
+#endif
+#ifdef LDAP_OPT_X_TLS_PROTOCOL_MIN
 	add_int(d,OPT_X_TLS_PROTOCOL_MIN);
 #endif
 #endif
