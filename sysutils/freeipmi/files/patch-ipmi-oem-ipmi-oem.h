--- ipmi-oem/ipmi-oem.h.orig	2014-01-03 23:45:22 UTC
+++ ipmi-oem/ipmi-oem.h
@@ -20,6 +20,7 @@
 #define IPMI_OEM_H
 
 #include <freeipmi/freeipmi.h>
+#include <sys/limits.h>
 
 #include "tool-cmdline-common.h"
 #include "pstdout.h"
