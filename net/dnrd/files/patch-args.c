--- args.c.orig	Sat Jan  6 14:54:15 2001
+++ args.c	Sat Jan  6 14:54:57 2001
@@ -25,6 +25,7 @@
 #include <stdarg.h>
 #include <stdio.h>
 #include <stdlib.h>
+#include <unistd.h>
 #if defined(__GNU_LIBRARY__)
 #   include <getopt.h>
 #endif
