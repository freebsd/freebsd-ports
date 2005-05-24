--- iiimsf/src/segvlogger.c.orig	Mon May  9 17:50:07 2005
+++ iiimsf/src/segvlogger.c	Mon May  9 17:52:09 2005
@@ -63,8 +63,13 @@
 	}
 	exit(1);
     }
+#ifndef __FreeBSD__
     snprintf(buffer, 1024, "gdb --batch --quiet --command %s/gdbcmd --pid %d",
 	     DATADIR, ppid);
+#else
+    snprintf(buffer, 1024, "gdb -batch -q -x %s/gdbcmd %s/bin/iiimd %d",
+	     DATADIR, PREFIX, ppid);
+#endif
 
     if ((fpr = popen(buffer, "r")) != NULL) {
 	char logfile[PATH_MAX];
