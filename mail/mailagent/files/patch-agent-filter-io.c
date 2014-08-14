--- ./agent/filter/io.c.orig	2008-08-19 17:44:07.000000000 +0900
+++ ./agent/filter/io.c	2014-08-14 01:59:33.537704696 +0900
@@ -141,6 +141,9 @@
 #ifdef I_SYS_IOCTL
 #include <sys/ioctl.h>
 #endif
+#ifdef I_SYS_PARAM
+#include <sys/param.h>
+#endif
 
 /*
  * The following should be defined in <sys/stat.h>.
@@ -739,7 +742,7 @@
 	 */
 
 	char **envp;			/* Environment pointer */
-#ifdef UNION_WAIT
+#if defined(UNION_WAIT) && (!defined(BSD) || BSD < 199306)
 	union wait status;		/* Waiting status */
 #else
 	int status;				/* Status from command */
