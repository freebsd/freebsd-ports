--- ipmi-oem/src/ipmi-oem.h.orig	2011-01-21 05:38:30.000000000 +0800
+++ ipmi-oem/src/ipmi-oem.h	2011-01-24 12:06:25.000000000 +0800
@@ -20,6 +20,7 @@
 #define _IPMI_OEM_H
 
 #include <freeipmi/freeipmi.h>
+#include <sys/limits.h>
 
 #include "tool-cmdline-common.h"
 #include "pstdout.h"
