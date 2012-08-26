--- cpuid_ia64.c.orig	2012-02-05 16:28:01.000000000 +0900
+++ cpuid_ia64.c	2012-02-05 16:28:41.000000000 +0900
@@ -38,7 +38,9 @@
 
 #include <stdio.h>
 #include <string.h>
+#ifdef linux
 #include <sys/sysinfo.h>
+#endif
 #include "cpuid.h"
 
 #ifdef __ECC
