--- iiimsf/src/segvlogger.c.orig	Sat Oct 16 10:28:13 2004
+++ iiimsf/src/segvlogger.c	Sun Feb 20 19:43:06 2005
@@ -19,6 +19,10 @@
 #include <time.h>
 #include <dirent.h>
 
+#ifdef __FreeBSD__
+#include <sys/syslimits.h>
+#endif
+
 int
 main(int argc, char **argv)
 {
@@ -43,8 +47,8 @@
 	exit(1);
     }
 
-    snprintf(buffer, 1024, "gdb --batch --quiet --command %s/gdbcmd --pid %d",
-	     DATADIR, ppid);
+    snprintf(buffer, 1024, "gdb -batch -q -x %s/gdbcmd %s/htt_server %d",
+	     DATADIR, IMBINDIR, ppid);
 
     if ((fpr = popen(buffer, "r")) != NULL) {
 	char logfile[PATH_MAX];
