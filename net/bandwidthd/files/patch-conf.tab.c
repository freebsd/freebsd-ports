--- conf.tab.c.orig	Sun Sep 14 10:34:01 2003
+++ conf.tab.c	Sun Nov  2 12:21:17 2003
@@ -23,11 +23,15 @@
 #include <stdio.h>
 #include <string.h>
 #include <unistd.h>
+#ifdef FREEBSD
+#include <stdlib.h>
+#else
 #include <malloc.h>
+#endif
 #include <unistd.h>
 #include <sys/types.h>
 #include <signal.h>
-#include <wait.h>
+#include <sys/wait.h>
 #include <sys/socket.h>
 #include <netinet/in.h>
 #include <arpa/inet.h>
