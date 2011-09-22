--- ./coreutils/dirname.c.orig	2011-08-22 04:57:49.000000000 +0200
+++ ./coreutils/dirname.c	2011-09-22 23:05:09.000000000 +0200
@@ -23,6 +23,8 @@
 
 #include "libbb.h"
 
+#include <libgen.h>
+
 /* This is a NOFORK applet. Be very careful! */
 
 int dirname_main(int argc, char **argv) MAIN_EXTERNALLY_VISIBLE;
