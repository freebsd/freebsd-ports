--- src/utils.c.orig    2010-10-26 20:54:31.000000000 +0200
+++ src/utils.c 2010-10-26 20:55:09.000000000 +0200
@@ -27,7 +27,7 @@
 #include <sys/wait.h>
 #include <stdlib.h>
 #include <glib/gstdio.h>
-
+#include <unistd.h>
 #include "icon-theme.h"

 static void on_pid_exit(GPid pid, gint status, gpointer user_data)
