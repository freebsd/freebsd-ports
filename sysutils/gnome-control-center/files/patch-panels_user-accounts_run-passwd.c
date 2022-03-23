Index: panels/user-accounts/run-passwd.c
--- panels/user-accounts/run-passwd.c.orig
+++ panels/user-accounts/run-passwd.c
@@ -139,6 +139,9 @@ static void
 ignore_sigpipe (gpointer data)
 {
         signal (SIGPIPE, SIG_IGN);
+#if defined(__OpenBSD__)
+        setsid();
+#endif
 }
 
 /* Spawn passwd backend
@@ -366,6 +369,7 @@ io_watch_stdout (GIOChannel *source, GIOCondition cond
 {
         static GString *str = NULL;     /* Persistent buffer */
 
+        gint            ret;
         gchar           buf[BUFSIZE];           /* Temporary buffer */
         gsize           bytes_read;
         g_autoptr(GError) gio_error = NULL;
@@ -377,8 +381,8 @@ io_watch_stdout (GIOChannel *source, GIOCondition cond
                 str = g_string_new ("");
         }
 
-        if (g_io_channel_read_chars (source, buf, BUFSIZE, &bytes_read, &gio_error)
-            != G_IO_STATUS_NORMAL) {
+        ret = g_io_channel_read_chars (source, buf, BUFSIZE, &bytes_read, &gio_error);
+        if (ret != G_IO_STATUS_NORMAL && ret != G_IO_STATUS_EOF) {
                 g_warning ("IO Channel read error: %s", gio_error->message);
                 return TRUE;
         }
@@ -390,11 +394,13 @@ io_watch_stdout (GIOChannel *source, GIOCondition cond
                 case PASSWD_STATE_AUTH:
                         /* Passwd is asking for our current password */
 
-                        if (is_string_complete (str->str, "assword: ", "failure", "wrong", "error", NULL)) {
+                        if (is_string_complete (str->str, "assword:","failure", "wrong", "error", "denied", "unchanged", NULL)) {
 
-                                if (strstr (str->str, "assword: ") != NULL &&
+                                if (strstr (str->str, "assword:") != NULL &&
                                     strstr (str->str, "incorrect") == NULL &&
-                                    strstr (str->str, "urrent") == NULL) {
+                                    strstr (str->str, "urrent") == NULL &&
+                                    strstr (str->str, "unchanged") == NULL &&
+                                    strstr (str->str, "denied") == NULL) {
                                         /* Authentication successful */
 
                                         passwd_handler->backend_state = PASSWD_STATE_NEW;
@@ -432,7 +438,7 @@ io_watch_stdout (GIOChannel *source, GIOCondition cond
                 case PASSWD_STATE_NEW:
                         /* Passwd is asking for our new password */
 
-                        if (is_string_complete (str->str, "assword: ", NULL)) {
+                        if (is_string_complete (str->str, "assword:", NULL)) {
                                 /* Advance to next state */
                                 passwd_handler->backend_state = PASSWD_STATE_RETYPE;
 
@@ -465,6 +471,7 @@ io_watch_stdout (GIOChannel *source, GIOCondition cond
                                                 "failure",
                                                 "DIFFERENT",
                                                 "BAD PASSWORD",
+                                                "another",
                                                 NULL)) {
 
                                 if (strstr (str->str, "successfully") != NULL) {
@@ -481,7 +488,8 @@ io_watch_stdout (GIOChannel *source, GIOCondition cond
                                         /* Ohnoes! */
                                         g_autoptr(GError) error = NULL;
 
-                                        if (strstr (str->str, "recovered") != NULL) {
+                                        if (strstr (str->str, "recovered") != NULL ||
+                                            strstr (str->str, "another") != NULL) {
                                                 /* What does this indicate?
                                                  * "Authentication information cannot be recovered?" from libpam? */
                                                 error = g_error_new_literal (PASSWD_ERROR, PASSWD_ERROR_UNKNOWN,
@@ -548,7 +556,7 @@ io_watch_stdout (GIOChannel *source, GIOCondition cond
                         break;
                 case PASSWD_STATE_NONE:
                         /* Passwd is not asking for anything yet */
-                        if (is_string_complete (str->str, "assword: ", NULL)) {
+                        if (is_string_complete (str->str, "assword:", NULL)) {
 
                                 /* If the user does not have a password set,
                                  * passwd will immediately ask for the new password,
