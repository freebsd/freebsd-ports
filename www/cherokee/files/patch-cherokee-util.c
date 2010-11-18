--- cherokee/util.c-orig	2010-11-15 17:53:34.000000000 -0300
+++ cherokee/util.c	2010-11-15 17:56:46.000000000 -0300
@@ -38,6 +38,11 @@
 #include <errno.h>
 #include <fcntl.h>
 
+ 
+#ifdef HAVE_SYS_WAIT_H
+# include <sys/wait.h>
+#endif
+
 #ifdef HAVE_SYS_TIME_H
 # include <sys/time.h>
 #else
