--- src/main.c.orig	Sun Aug  4 10:58:23 2002
+++ src/main.c	Sun Aug  4 11:00:57 2002
@@ -34,7 +34,12 @@
 #include <sys/param.h>
 #include <sys/utsname.h>
 #include <sys/un.h>
+#if !(defined(BSD) && (BSD >= 199103))
 #include <linux/sem.h>     /* for the value of SEMVMX */
+#else
+#include <sys/ipc.h>
+#include <sys/sem.h>	/* for the value of SEMVMX */
+#endif
 #include <errno.h>
 #include <getopt.h>
 #include <string.h>
@@ -1253,6 +1258,7 @@
 
 	char *virtual_share_path=NULL;
 
+	hide_absolute=1;
 	disp_msg(INFO_MSG,NULL,"Direct Connect Text Client v" VERSION ,NULL);
 
 	if(argc==1)
