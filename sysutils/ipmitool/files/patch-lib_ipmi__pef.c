--- lib/ipmi_pef.c.orig	2016-05-06 14:48:54 UTC
+++ lib/ipmi_pef.c
@@ -40,6 +40,7 @@
 #include <ipmitool/ipmi.h>
 #include <ipmitool/ipmi_intf.h>
 #include <ipmitool/ipmi_pef.h>
+#include <ipmitool/bswap.h>
 
 extern int verbose;
 /*
