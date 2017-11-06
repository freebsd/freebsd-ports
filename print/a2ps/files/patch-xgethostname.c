--- lib/xgethostname.c.orig	1999-08-28 17:11:35 UTC
+++ lib/xgethostname.c
@@ -21,6 +21,7 @@
 # include <config.h>
 #endif
 
+#include <sys/param.h>
 #include <sys/types.h>
 
 #include <errno.h>
@@ -38,7 +39,7 @@ extern int errno;
 int gethostname ();
 
 #ifndef INITIAL_HOSTNAME_LENGTH
-# define INITIAL_HOSTNAME_LENGTH 34
+# define INITIAL_HOSTNAME_LENGTH MAXHOSTNAMELEN
 #endif
 
 char *
@@ -63,7 +64,7 @@ xgethostname ()
       if (err == 0 && hostname[k] == '\0')
 	break;
 #ifdef ENAMETOOLONG
-      else if (err != 0 && errno != ENAMETOOLONG && errno != 0)
+      else if (err != 0 && errno != ENAMETOOLONG && errno != ENOMEM && errno != 0)
 	error (EXIT_FAILURE, errno, "gethostname");
 #endif
       size *= 2;
