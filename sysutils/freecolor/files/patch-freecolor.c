--- freecolor.c.bak	Wed May 19 22:43:41 2004
+++ freecolor.c	Wed May 19 22:44:50 2004
@@ -56,15 +56,13 @@
 #define PROC_MEMINFO "/proc/meminfo"
 #endif
 #else
+#define SG_ENABLE_DEPRECATED
 #include <statgrab.h>
 #endif
 #include <string.h>
 #include <unistd.h>
 #include <stdlib.h>
 #include <stdio.h>
-#ifndef NO_GETOPT
-#include <getopt.h>
-#endif
 #define BARLEN 35
 #define HEADERLEN 14
 #define VERSION "0.8.3"
