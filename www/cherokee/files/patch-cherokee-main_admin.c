--- cherokee/main_admin.c-orig	2010-10-29 07:11:18.000000000 -0300
+++ cherokee/main_admin.c	2010-11-15 16:56:39.000000000 -0300
@@ -35,6 +35,10 @@
 #include "server-protected.h"
 #include "util.h"
 
+#ifdef HAVE_SYS_WAIT_H
+# include <sys/wait.h>
+#endif
+
 #ifdef HAVE_GETOPT_LONG
 # include <getopt.h>
 #else
