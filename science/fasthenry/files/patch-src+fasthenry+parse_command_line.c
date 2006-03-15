--- src/fasthenry/parse_command_line.c.orig	Sat Feb 25 22:17:54 2006
+++ src/fasthenry/parse_command_line.c	Sat Feb 25 22:19:14 2006
@@ -38,6 +38,7 @@
 
 #include "induct.h"
 #include <string.h>
+#include <time.h>
 #ifdef SOLARIS
 #include <sys/systeminfo.h>
 #endif
@@ -558,7 +559,7 @@
 fix_and_print_opts(opts)
 ind_opts *opts;
 {
-  long clock;
+  time_t clock;
   char hostname[BUFSIZ];
 
   fprintf(stdout, "Running FastHenry %s (%s)\n", FHVERSION, FHDATE);
