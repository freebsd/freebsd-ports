--- ipmi-oem/ipmi-oem.h.orig	2014-03-04 03:36:03.000000000 +0800
+++ ipmi-oem/ipmi-oem.h	2014-03-06 04:16:04.700980190 +0800
@@ -20,6 +20,7 @@
 #define IPMI_OEM_H
 
 #include <freeipmi/freeipmi.h>
+#include <sys/limits.h>
 
 #include "tool-cmdline-common.h"
 #include "pstdout.h"
