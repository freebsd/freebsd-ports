--- src/main.c	Sat Dec  1 09:05:19 2001
+++ src/main.c	Sun Dec  2 19:34:12 2001
@@ -30,12 +30,13 @@
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
+#include "config.h"
 
 #include "var.h"
 #include "display.h"
