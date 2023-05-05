--- agent/filter/io.c.orig	2020-04-09 14:16:46 UTC
+++ agent/filter/io.c
@@ -100,6 +100,7 @@
 #include <stdio.h>
 #include <errno.h>
 #include <sys/stat.h>
+#include <signal.h>
 
 #ifdef I_UNISTD
 #include <unistd.h>		/* R_OK and friends */
@@ -141,6 +142,9 @@ extern char *malloc();				/* Memory allocation */
 #ifdef I_SYS_IOCTL
 #include <sys/ioctl.h>
 #endif
+#ifdef I_SYS_PARAM
+#include <sys/param.h>
+#endif
 
 /*
  * The following should be defined in <sys/stat.h>.
@@ -739,7 +743,7 @@ char *location;
 	 */
 
 	char **envp;			/* Environment pointer */
-#ifdef UNION_WAIT
+#if defined(UNION_WAIT) && (!defined(BSD) || BSD < 199306)
 	union wait status;		/* Waiting status */
 #else
 	int status;				/* Status from command */
