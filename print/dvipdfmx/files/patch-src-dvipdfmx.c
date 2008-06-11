--- src/dvipdfmx.c.orig	2008-05-29 19:40:29.000000000 +0900
+++ src/dvipdfmx.c	2008-06-11 00:50:55.000000000 +0900
@@ -30,6 +30,7 @@
 #include <string.h>
 #include <limits.h>
 #include <ctype.h>
+#include <libgen.h>

 #include "system.h"
 #include "mem.h"
@@ -773,10 +774,13 @@
 main (int argc, char *argv[])
 {
   double dvi2pts;
+  char *bn = basename(argv[0]);

-  if (strcmp(argv[0], "ebb") == 0)
+  if (strcmp(bn, "ebb") == 0)
     return extractbb(argc, argv, EBB_OUTPUT);
-  else if (strcmp(argv[0], "xbb") == 0 || strcmp(argv[0], "extractbb") == 0)
+  else if (strcmp(bn, "ebb-dvipdfmx") == 0)
+    return extractbb(argc, argv, EBB_OUTPUT);
+  else if (strcmp(bn, "xbb") == 0 || strcmp(bn, "extractbb") == 0)
     return extractbb(argc, argv, XBB_OUTPUT);

   mem_debug_init();
