--- libgksu/libgksu.c.orig	2009-03-04 18:53:02.000000000 +0000
+++ libgksu/libgksu.c	2011-04-12 16:45:53.000000000 +0000
@@ -23,13 +23,15 @@
 #include <unistd.h>
 #include <string.h>
 #include <fcntl.h>
-#include <pty.h>
 #include <pwd.h>
+#include <sys/ioctl.h>
 #include <sys/types.h>
 #include <sys/wait.h>
 #include <sys/stat.h>
 #include <sys/select.h>
 #include <errno.h>
+#include <termios.h>
+#include <libutil.h>
 
 #include <glibtop.h>
 #include <glibtop/procstate.h>
@@ -2190,8 +2192,6 @@
 	      write (fdpty, line, strlen(line));
 	      g_free (line);
 
-	      tcdrain (fdpty);
-
 	      bzero (buf, 256);
 	      read (fdpty, buf, 255);
 
