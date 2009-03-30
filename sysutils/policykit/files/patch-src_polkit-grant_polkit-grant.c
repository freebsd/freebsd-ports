--- src/polkit-grant/polkit-grant.c.orig	2009-03-29 20:12:16.000000000 -0400
+++ src/polkit-grant/polkit-grant.c	2009-03-29 20:13:15.000000000 -0400
@@ -303,7 +303,7 @@ polkit_grant_io_func (PolKitGrant *polki
         g_return_if_fail (polkit_grant != NULL);
         g_return_if_fail (polkit_grant->helper_is_running);
 
-        while (kit_getline (&line, &line_len, polkit_grant->child_stdout_f) != -1) {
+        while (kit_getline (&line, &line_len, polkit_grant->child_stdout_f) != -1 && !feof (polkit_grant->child_stdout_f)) {
                 if (strlen (line) > 0 &&
                     line[strlen (line) - 1] == '\n')
                         line[strlen (line) - 1] = '\0';
