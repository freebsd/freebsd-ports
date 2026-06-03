--- src/manage_alerts.c	2026-03-09 06:35:01.000000000 -0700
+++ src/manage_alerts.c	2026-03-16 18:50:11.576127000 -0700
@@ -23,12 +23,12 @@
 #include "manage_tickets.h"
 #include "manage_users.h"
 
-#include <bsd/unistd.h>
 #include <glib/gstdio.h>
 #include <grp.h>
 #include <pwd.h>
 #include <sys/types.h>
 #include <sys/wait.h>
+#include <unistd.h>
 
 #include <gvm/gmp/gmp.h>
 #include <gvm/util/fileutils.h>
@@ -1040,7 +1040,7 @@
     }
 
   cmd = (gchar **) g_malloc (6 * sizeof (gchar *));
-  cmd[0] = g_strdup ("/usr/bin/wget");
+  cmd[0] = g_strdup ("/usr/local/bin/wget");
   cmd[1] = g_strdup ("-O");
   cmd[2] = g_strdup ("-");
   cmd[3] = g_strdup ("--");
