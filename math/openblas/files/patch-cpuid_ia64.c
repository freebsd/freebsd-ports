--- cpuid_ia64.c.orig	2015-10-27 20:44:50 UTC
+++ cpuid_ia64.c
@@ -38,7 +38,9 @@
 
 #include <stdio.h>
 #include <string.h>
+#ifdef linux
 #include <sys/sysinfo.h>
+#endif
 #include "cpuid.h"
 
 #ifdef __ECC
