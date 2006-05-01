--- src/exec.c.orig	Thu Feb  9 21:22:24 2006
+++ src/exec.c	Thu Feb  9 21:22:50 2006
@@ -23,6 +23,9 @@
 #include <sys/wait.h>
 #include "gbcommon.h"
 
+#if defined (__FreeBSD__)
+#include <signal.h>
+#endif
 
 static gint child_child_pipe[2];
 
