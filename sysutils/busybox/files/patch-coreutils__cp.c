--- ./coreutils/cp.c.orig	2011-08-22 04:57:49.000000000 +0200
+++ ./coreutils/cp.c	2011-09-22 23:05:23.000000000 +0200
@@ -35,6 +35,8 @@
 #include "libbb.h"
 #include "libcoreutils/coreutils.h"
 
+#include <libgen.h>
+
 /* This is a NOEXEC applet. Be very careful! */
 
 int cp_main(int argc, char **argv) MAIN_EXTERNALLY_VISIBLE;
