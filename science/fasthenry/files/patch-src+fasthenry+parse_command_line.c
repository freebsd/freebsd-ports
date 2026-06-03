--- src/fasthenry/parse_command_line.c.orig	2009-01-11 14:21:26 UTC
+++ src/fasthenry/parse_command_line.c
@@ -4,6 +4,7 @@
 
 #include "induct.h"
 #include <string.h>
+#include <time.h>
 #ifdef SOLARIS
 #include <sys/systeminfo.h>
 #endif
