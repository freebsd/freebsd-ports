--- src/splashd.c.orig	Wed Nov 19 16:29:47 2003
+++ src/splashd.c	Wed Nov 19 16:30:28 2003
@@ -1,7 +1,10 @@
+# include <sys/param.h>
+# include <sys/types.h>
+# include <sys/socket.h>
+# include <netinet/in.h>
+# include <pthread.h>
 # include <glib.h>
 # include <stdio.h>
-# include <netinet/in.h>
-# include <sys/socket.h>
 # include <signal.h>
 # include <string.h>
 # include <time.h>
