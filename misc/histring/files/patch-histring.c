--- histring.c.orig	2014-12-20 19:35:27 UTC
+++ histring.c
@@ -15,6 +15,8 @@
 #  include <config.h>
 #endif
 
+#include <sys/types.h>
+
 #ifdef HAVE_GETOPT_H
 #  include <getopt.h>
 #endif
