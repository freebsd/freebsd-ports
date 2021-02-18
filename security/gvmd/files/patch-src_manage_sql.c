--- src/manage_sql.c	2021-02-02 09:44:09.000000000 -0500
+++ src/manage_sql.c	2021-02-18 13:49:16.256262000 -0500
@@ -52,7 +52,6 @@
 #include <errno.h>
 #include <glib/gstdio.h>
 #include <gnutls/x509.h>
-#include <malloc.h>
 #include <pwd.h>
 #include <stdlib.h>
 #include <sys/socket.h>
@@ -15277,8 +15276,6 @@
     }
 
   cleanup_iterator (&nvts);
-
-  malloc_trim (0);
 }
 
 /**
