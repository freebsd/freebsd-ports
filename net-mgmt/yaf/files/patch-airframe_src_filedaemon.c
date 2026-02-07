--- airframe/src/filedaemon.c.orig	2023-02-08 18:37:15 UTC
+++ airframe/src/filedaemon.c
@@ -17,6 +17,10 @@
 #include <airframe/airopt.h>
 #include <airframe/logconfig.h>
 
+#ifdef G_OS_UNIX
+#include <sys/wait.h>
+#endif
+
 static char          *fd_inspec          = NULL;
 static char          *fd_outspec         = NULL;
 static char          *fd_nextdir         = NULL;
