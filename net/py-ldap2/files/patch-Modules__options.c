--- ./Modules/options.c.orig	2009-10-30 06:20:47.000000000 -0700
+++ ./Modules/options.c	2009-11-24 11:36:43.305856626 -0800
@@ -1,5 +1,5 @@
 /* See http://www.python-ldap.org/ for details.
- * $Id: options.c,v 1.33 2009/10/23 09:09:37 stroeder Exp $ */
+ * $Id: options.c,v 1.35 2009/11/13 08:45:50 stroeder Exp $ */
 
 #include "common.h"
 #include "errors.h"
@@ -79,8 +79,10 @@
 #ifdef HAVE_TLS
     case LDAP_OPT_X_TLS:
     case LDAP_OPT_X_TLS_REQUIRE_CERT:
+#ifdef LDAP_OPT_X_TLS_NEWCTX
     case LDAP_OPT_X_TLS_NEWCTX:
-#ifdef OPT_X_TLS_PROTOCOL_MIN
+#endif
+#ifdef LDAP_OPT_X_TLS_PROTOCOL_MIN
     case LDAP_OPT_X_TLS_PROTOCOL_MIN:
 #endif
 #endif
@@ -218,7 +220,7 @@
 #ifdef HAVE_TLS
     case LDAP_OPT_X_TLS:
     case LDAP_OPT_X_TLS_REQUIRE_CERT:
-#ifdef OPT_X_TLS_PROTOCOL_MIN
+#ifdef LDAP_OPT_X_TLS_PROTOCOL_MIN
     case LDAP_OPT_X_TLS_PROTOCOL_MIN:
 #endif
 #endif
