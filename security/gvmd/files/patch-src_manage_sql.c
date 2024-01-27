--- src/manage_sql.c	2024-01-12 03:14:29.000000000 -0500
+++ src/manage_sql.c	2024-01-26 16:42:23.043251000 -0500
@@ -54,7 +54,6 @@
 #include <errno.h>
 #include <glib/gstdio.h>
 #include <gnutls/x509.h>
-#include <malloc.h>
 #include <pwd.h>
 #include <stdlib.h>
 #include <sys/socket.h>
@@ -71,7 +70,6 @@
 #include <gvm/base/hosts.h>
 #include <gvm/base/pwpolicy.h>
 #include <gvm/base/logging.h>
-#include <bsd/unistd.h>
 #include <gvm/util/fileutils.h>
 #include <gvm/util/gpgmeutils.h>
 #include <gvm/util/serverutils.h>
@@ -9431,7 +9429,7 @@
   g_debug ("   HTTP_GET %s", url);
 
   cmd = (gchar **) g_malloc (5 * sizeof (gchar *));
-  cmd[0] = g_strdup ("/usr/bin/wget");
+  cmd[0] = g_strdup ("/usr/local/bin/wget");
   cmd[1] = g_strdup ("-O");
   cmd[2] = g_strdup ("-");
   cmd[3] = g_strdup (url);
@@ -15775,8 +15773,6 @@
 
   cleanup_iterator (&nvts);
   cleanup_iterator (&prefs);
-
-  malloc_trim (0);
 }
 
 /**
