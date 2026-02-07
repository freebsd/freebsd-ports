--- src/manage_alerts.c	2025-09-05 02:59:51.000000000 -0700
+++ src/manage_alerts.c	2025-10-07 22:40:51.468412000 -0700
@@ -33,12 +33,12 @@
 #include "manage_sql_tickets.h"
 #include "manage_tickets.h"
 
-#include <bsd/unistd.h>
 #include <glib/gstdio.h>
 #include <grp.h>
 #include <pwd.h>
 #include <sys/types.h>
 #include <sys/wait.h>
+#include <unistd.h>
 
 #include <gvm/gmp/gmp.h>
 #include <gvm/util/fileutils.h>
@@ -1043,7 +1043,7 @@
   g_debug ("   HTTP_GET %s", url);
 
   cmd = (gchar **) g_malloc (5 * sizeof (gchar *));
-  cmd[0] = g_strdup ("/usr/bin/wget");
+  cmd[0] = g_strdup ("/usr/local/bin/wget");
   cmd[1] = g_strdup ("-O");
   cmd[2] = g_strdup ("-");
   cmd[3] = g_strdup (url);
