--- lib/ipmi_chassis.c.orig	2012-10-15 07:38:19.000000000 +0000
+++ lib/ipmi_chassis.c	2012-10-15 07:38:46.000000000 +0000
@@ -41,6 +41,7 @@
 #include <ipmitool/ipmi_intf.h>
 #include <ipmitool/ipmi_strings.h>
 #include <ipmitool/ipmi_chassis.h>
+#include <ipmitool/bswap.h>
 
 extern int verbose;
 
