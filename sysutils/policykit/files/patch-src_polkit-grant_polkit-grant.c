--- src/polkit-grant/polkit-grant.c.orig	2007-11-28 16:29:25.000000000 -0500
+++ src/polkit-grant/polkit-grant.c	2007-12-23 01:25:08.000000000 -0500
@@ -38,6 +38,7 @@
 #include <sys/types.h>
 #include <unistd.h>
 #include <sys/wait.h>
+#include <signal.h>
 
 #include <glib.h>
 #include "polkit-grant.h"
@@ -301,7 +302,7 @@ polkit_grant_io_func (PolKitGrant *polki
         g_return_if_fail (polkit_grant != NULL);
         g_return_if_fail (polkit_grant->helper_is_running);
 
-        while (getline (&line, &line_len, polkit_grant->child_stdout_f) != -1) {
+        while (polkit_sysdeps_getline (&line, &line_len, polkit_grant->child_stdout_f) != -1) {
                 if (strlen (line) > 0 &&
                     line[strlen (line) - 1] == '\n')
                         line[strlen (line) - 1] = '\0';
