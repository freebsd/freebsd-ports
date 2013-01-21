--- ./coreutils/cp.c.orig	2012-06-26 13:35:45.000000000 +0000
+++ ./coreutils/cp.c	2012-07-17 02:08:37.000000000 +0000
@@ -35,6 +35,8 @@
 #include "libbb.h"
 #include "libcoreutils/coreutils.h"
 
+#include <libgen.h>
+
 /* This is a NOEXEC applet. Be very careful! */
 
 int cp_main(int argc, char **argv) MAIN_EXTERNALLY_VISIBLE;
