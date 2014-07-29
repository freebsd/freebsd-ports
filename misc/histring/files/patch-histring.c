--- histring.c	2000/10/18 13:39:37	1.1
+++ histring.c	2000/10/18 13:44:11	1.2
@@ -15,6 +15,8 @@
 #  include <config.h>
 #endif
 
+#include <sys/types.h>
+
 #ifdef HAVE_GETOPT_H
 #  include <getopt.h>
 #endif
