--- util/main.c.orig	Wed Oct 24 19:46:49 2001
+++ util/main.c	Sun Nov 23 12:15:53 2003
@@ -34,9 +34,6 @@
 #include <stdlib.h>
 #include <string.h>
 #include <fcntl.h>
-#ifdef HAVE_SYS_LOCK_H
-#  include <sys/lock.h>
-#endif
 #include <errno.h>
 #include <signal.h>
 #include <unistd.h>
@@ -44,6 +41,9 @@
 #include <sys/time.h>
 #include <sys/resource.h>
 #include <sys/stat.h>
+#ifdef HAVE_SYS_LOCK_H
+#  include <sys/lock.h>
+#endif
 
 char cc[1000];
 int Argc;
