--- agent/filter/io.c.orig	Wed Jul 29 02:41:11 1998
+++ agent/filter/io.c	Mon Aug 10 21:01:22 1998
@@ -120,6 +120,9 @@
 #ifdef I_SYS_IOCTL
 #include <sys/ioctl.h>
 #endif
+#ifdef I_SYS_PARAM
+#include <sys/param.h>
+#endif
 
 /*
  * The following should be defined in <sys/stat.h>.
@@ -713,7 +716,7 @@
 	 */
 	
 	char **envp;			/* Environment pointer */
-#ifdef UNION_WAIT
+#if defined(UNION_WAIT) && (!defined(BSD) || BSD < 199306)
 	union wait status;		/* Waiting status */
 #else
 	int status;				/* Status from command */
