--- src/docsis_snmp.c.orig	2015-10-18 20:28:25 UTC
+++ src/docsis_snmp.c
@@ -21,6 +21,8 @@
  *  DOCSIS is a registered trademark of Cablelabs, http://www.cablelabs.com
  */
 
+#include <string.h>
+
 #include "docsis_snmp.h"
 #include "docsis_decode.h"
 
