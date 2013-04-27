--- lib/xgethostname.c.orig	Tue Nov 20 20:26:31 2001
+++ lib/xgethostname.c	Tue Nov 20 20:26:03 2001
@@ -21,6 +21,7 @@
 # include <config.h>
 #endif
 
+#include <sys/param.h>
 #include <sys/types.h>
 
 #include <errno.h>
@@ -38,7 +39,7 @@
 int gethostname ();
 
 #ifndef INITIAL_HOSTNAME_LENGTH
-# define INITIAL_HOSTNAME_LENGTH 34
+# define INITIAL_HOSTNAME_LENGTH MAXHOSTNAMELEN
 #endif
 
 char *
