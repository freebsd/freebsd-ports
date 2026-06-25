--- airframe/src/filedaemon.c.orig	2026-03-19 20:13:51 UTC
+++ airframe/src/filedaemon.c
@@ -43,6 +43,10 @@
 #include <airframe/airopt.h>
 #include <airframe/logconfig.h>
 
+#ifdef G_OS_UNIX
+#include <sys/wait.h>
+#endif
+
 static char          *fd_inspec          = NULL;
 static char          *fd_outspec         = NULL;
 static char          *fd_nextdir         = NULL;
