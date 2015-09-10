--- src/splashd.c.orig	2003-02-23 03:09:46 UTC
+++ src/splashd.c
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
