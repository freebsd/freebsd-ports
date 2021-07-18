--- src/manage_sql.c	2021-04-16 02:27:18.000000000 -0500
+++ src/manage_sql.c	2021-06-14 19:33:56.599632000 -0500
@@ -52,7 +52,6 @@
 #include <errno.h>
 #include <glib/gstdio.h>
 #include <gnutls/x509.h>
-#include <malloc.h>
 #include <pwd.h>
 #include <stdlib.h>
 #include <sys/socket.h>
@@ -9075,7 +9074,7 @@
   g_debug ("   HTTP_GET %s", url);
 
   cmd = (gchar **) g_malloc (5 * sizeof (gchar *));
-  cmd[0] = g_strdup ("/usr/bin/wget");
+  cmd[0] = g_strdup ("%%LOCALBASE%%/bin/wget");
   cmd[1] = g_strdup ("-O");
   cmd[2] = g_strdup ("-");
   cmd[3] = g_strdup (url);
@@ -15262,8 +15261,6 @@
     }
 
   cleanup_iterator (&nvts);
-
-  malloc_trim (0);
 }
 
 /**
