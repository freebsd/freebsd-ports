# $FreeBSD$
--- src/docsis.c.orig	Mon Aug 15 14:19:04 2005
+++ src/docsis.c	Sun Jun 10 18:14:07 2007
@@ -20,10 +20,6 @@
  *  DOCSIS is a registered trademark of Cablelabs, http://www.cablelabs.com
  */
 
-#ifdef HAVE_CONFIG_H
-#include "config.h"
-#endif /* HAVE_CONFIG_H  */
-
 #include <errno.h>
 #include <string.h>
 #include <sys/types.h>
@@ -35,6 +31,16 @@
 #include <net-snmp/config_api.h>
 #include <net-snmp/output_api.h>
 #include <net-snmp/mib_api.h>
+
+#undef PACKAGE_BUGREPORT
+#undef PACKAGE_NAME
+#undef PACKAGE_STRING
+#undef PACKAGE_TARNAME
+#undef PACKAGE_VERSION
+
+#ifdef HAVE_CONFIG_H
+#include "config.h"
+#endif /* HAVE_CONFIG_H  */
 
 #include "docsis.h"
 #include "docsis_symtable.h"
