--- cpuid_ia64.c.orig	2011-09-23 10:47:22.000000000 -0400
+++ cpuid_ia64.c	2011-09-23 10:48:08.000000000 -0400
@@ -38,7 +38,9 @@
 
 #include <stdio.h>
 #include <string.h>
+#ifdef linux
 #include <sys/sysinfo.h>
+#endif
 #include "cpuid.h"
 
 #ifdef __ECC
