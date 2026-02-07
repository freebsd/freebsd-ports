--- src/configuration.c.orig	2023-10-10 16:16:06 UTC
+++ src/configuration.c
@@ -8,7 +8,9 @@
 
 #include <sys/types.h>
 #include <sys/stat.h>
+#ifndef __FreeBSD__
 #include <sys/sysinfo.h>
+#endif
 
 #include <stdio.h>
 #include <string.h>
