--- src/docsis.c.orig	2015-10-18 20:28:25 UTC
+++ src/docsis.c
@@ -21,10 +21,6 @@
  *  DOCSIS is a registered trademark of Cablelabs, http://www.cablelabs.com
  */
 
-#ifdef HAVE_CONFIG_H
-#include "config.h"
-#endif /* HAVE_CONFIG_H  */
-
 #include <errno.h>
 #include <string.h>
 #include <sys/types.h>
@@ -37,6 +33,16 @@
 #include <net-snmp/output_api.h>
 #include <net-snmp/mib_api.h>
 
+#undef PACKAGE_BUGREPORT
+#undef PACKAGE_NAME
+#undef PACKAGE_STRING
+#undef PACKAGE_TARNAME
+#undef PACKAGE_VERSION
+
+#ifdef HAVE_CONFIG_H
+#include "config.h"
+#endif /* HAVE_CONFIG_H  */
+
 #include "docsis.h"
 #include "docsis_globals.h"
 #include "docsis_symtable.h"
