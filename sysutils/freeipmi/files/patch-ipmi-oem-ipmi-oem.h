--- ipmi-oem/ipmi-oem.h.orig	2012-01-03 03:26:10.000000000 +0800
+++ ipmi-oem/ipmi-oem.h	2012-01-06 04:36:44.994004384 +0800
@@ -20,6 +20,7 @@
 #define _IPMI_OEM_H
 
 #include <freeipmi/freeipmi.h>
+#include <sys/limits.h>
 
 #include "tool-cmdline-common.h"
 #include "pstdout.h"
