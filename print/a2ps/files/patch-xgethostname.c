--- lib/xgethostname.c	Tue Sep  4 00:51:26 2001
+++ lib/xgethostname.c.new	Tue Sep  4 00:55:39 2001
@@ -63,7 +63,7 @@
       if (err == 0 && hostname[k] == '\0')
 	break;
 #ifdef ENAMETOOLONG
-      else if (err != 0 && errno != ENAMETOOLONG && errno != 0)
+      else if (err != 0 && errno != ENAMETOOLONG && errno != ENOMEM && errno != 0)
 	error (EXIT_FAILURE, errno, "gethostname");
 #endif
       size *= 2;

