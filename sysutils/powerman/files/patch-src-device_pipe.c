$FreeBSD$

--- src/device_pipe.c.orig	Mon Mar 29 22:02:27 2004
+++ src/device_pipe.c	Mon Mar 29 22:02:48 2004
@@ -38,7 +38,10 @@
 #include <ctype.h>
 #include <sys/types.h>
 #include <sys/wait.h>
+#include <signal.h>
+#ifdef __linux__
 #include <pty.h>
+#endif
 
 
 #include "powerman.h"
