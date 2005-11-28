--- compat.c.orig	Wed Jan  5 17:01:51 2005
+++ compat.c	Mon Oct 31 09:55:12 2005
@@ -110,6 +110,7 @@
 #define __USE_BSD 1
 #include <stdarg.h>
 #include <stdio.h>
+#include <unistd.h>
 
 void my_setproctitle(int argc, char **argv, const char *format, ...) {
        char proctitle[64];
@@ -126,7 +127,6 @@
 }
 
 /* signal to pipe delivery implementation */
-#include <unistd.h>
 #include <fcntl.h>
 #include <signal.h>
 
