--- ./coreutils/rmdir.c.orig	2011-08-22 04:57:49.000000000 +0200
+++ ./coreutils/rmdir.c	2011-09-22 23:05:09.000000000 +0200
@@ -27,6 +27,8 @@
 
 #include "libbb.h"
 
+#include <libgen.h>
+
 /* This is a NOFORK applet. Be very careful! */
 
 
