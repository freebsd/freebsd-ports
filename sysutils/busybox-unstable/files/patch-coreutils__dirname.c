--- ./coreutils/dirname.c.orig	2012-06-26 13:35:45.000000000 +0000
+++ ./coreutils/dirname.c	2012-07-17 02:08:37.000000000 +0000
@@ -23,6 +23,8 @@
 
 #include "libbb.h"
 
+#include <libgen.h>
+
 /* This is a NOFORK applet. Be very careful! */
 
 int dirname_main(int argc, char **argv) MAIN_EXTERNALLY_VISIBLE;
