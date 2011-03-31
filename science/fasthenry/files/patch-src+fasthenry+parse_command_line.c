--- src/fasthenry/parse_command_line.c.orig	2009-01-11 14:21:26.000000000 -0500
+++ src/fasthenry/parse_command_line.c	2011-03-31 10:56:27.000000000 -0400
@@ -4,6 +4,7 @@
 
 #include "induct.h"
 #include <string.h>
+#include <time.h>
 #ifdef SOLARIS
 #include <sys/systeminfo.h>
 #endif
