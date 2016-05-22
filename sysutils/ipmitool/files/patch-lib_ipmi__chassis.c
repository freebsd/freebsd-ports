--- lib/ipmi_chassis.c.orig	2016-05-06 14:48:54 UTC
+++ lib/ipmi_chassis.c
@@ -44,6 +44,7 @@
 #include <ipmitool/ipmi_intf.h>
 #include <ipmitool/ipmi_strings.h>
 #include <ipmitool/ipmi_chassis.h>
+#include <ipmitool/bswap.h>
 
 extern int verbose;
 
