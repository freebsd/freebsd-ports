--- traceroute.c	2011-06-12 18:10:52.000000000 -0400
+++ traceroute.c	2011-06-12 18:11:00.000000000 -0400
@@ -2,6 +2,7 @@
 /*
  *  STILL BROKEN: traceroute -g on linux (LSRR)
  */
+#include <string.h>
 #define TRACE_TOS 1
 #define SPRAY
 #define FIXT
