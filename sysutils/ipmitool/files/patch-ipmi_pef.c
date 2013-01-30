--- lib/ipmi_pef.c.orig	2012-10-15 07:41:07.000000000 +0000
+++ lib/ipmi_pef.c	2012-10-15 07:41:36.000000000 +0000
@@ -39,6 +39,7 @@
 #include <ipmitool/ipmi.h>
 #include <ipmitool/ipmi_intf.h>
 #include <ipmitool/ipmi_pef.h>
+#include <ipmitool/bswap.h>
 
 extern int verbose;
 /*