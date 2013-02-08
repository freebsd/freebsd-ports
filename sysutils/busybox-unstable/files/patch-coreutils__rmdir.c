--- ./coreutils/rmdir.c.orig	2012-07-02 14:08:25.000000000 +0000
+++ ./coreutils/rmdir.c	2012-07-17 02:08:37.000000000 +0000
@@ -27,6 +27,8 @@
 
 #include "libbb.h"
 
+#include <libgen.h>
+
 /* This is a NOFORK applet. Be very careful! */
 
 
