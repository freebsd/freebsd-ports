--- src/main.c.orig	Sat Nov 24 13:22:57 2001
+++ src/main.c	Sat Nov 24 13:25:24 2001
@@ -30,12 +30,23 @@
 #include <sys/param.h>
 #include <sys/utsname.h>
 #include <sys/un.h>
-#include <linux/sem.h>     /* for the value of SEMVMX */
 #include <errno.h>
 #include <getopt.h>
 #include <string.h>
 #include <glib.h>
 #include <pthread.h>
+
+#if (defined(__unix__) || defined(unix)) && !defined(USG)
+#include <sys/param.h>
+#endif
+
+#if (defined(BSD) && (BSD >= 199103))
+# include <sys/ipc.h>
+# include <sys/sem.h>
+#else
+/* For linux */
+# include <linux/sem.h>     /* for the value of SEMVMX */
+#endif
 
 #include "var.h"
 #include "display.h"
