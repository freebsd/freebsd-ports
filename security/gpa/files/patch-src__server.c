--- ./src/server.c.orig	2009-05-13 03:11:11.000000000 -0400
+++ ./src/server.c	2010-06-22 05:31:57.000000000 -0400
@@ -568,7 +568,7 @@
    the last command.  A RESET command undoes the effect of this
    command.
 */
-static int
+static gpg_error_t
 cmd_session (assuan_context_t ctx, char *line)
 {
   conn_ctrl_t ctrl = assuan_get_pointer (ctx);
@@ -594,7 +594,7 @@
   validity right away; if it does not (as here) all recipients are
   checked at the time of the ENCRYPT command.  All RECIPIENT commands
   are cumulative until a RESET or an successful ENCRYPT command.  */
-static int
+static gpg_error_t
 cmd_recipient (assuan_context_t ctx, char *line)
 {
   conn_ctrl_t ctrl = assuan_get_pointer (ctx);
@@ -615,7 +615,7 @@
    Set the file descriptor to read a message which is used with
    detached signatures.
  */
-static int 
+static gpg_error_t
 cmd_message (assuan_context_t ctx, char *line)
 {
   conn_ctrl_t ctrl = assuan_get_pointer (ctx);
@@ -659,7 +659,7 @@
 
    Encrypt the data received on INPUT to OUTPUT.
 */
-static int 
+static gpg_error_t
 cmd_encrypt (assuan_context_t ctx, char *line)
 {
   conn_ctrl_t ctrl = assuan_get_pointer (ctx);
@@ -755,7 +755,7 @@
 
    Dummy encryption command used to check whether the given recipients
    are all valid and to tell the client the preferred protocol.  */
-static int 
+static gpg_error_t
 cmd_prep_encrypt (assuan_context_t ctx, char *line)
 {
   conn_ctrl_t ctrl = assuan_get_pointer (ctx);
@@ -814,7 +814,7 @@
     @code{RESET} command.  A second command overrides the effect of
     the first one; if EMAIL is not given the server shall use the
     default signing key.  */
-static int
+static gpg_error_t
 cmd_sender (assuan_context_t ctx, char *line)
 {
   conn_ctrl_t ctrl = assuan_get_pointer (ctx);
@@ -867,7 +867,7 @@
 
    Sign the data received on INPUT to OUTPUT.
 */
-static int 
+static gpg_error_t
 cmd_sign (assuan_context_t ctx, char *line)
 {
   conn_ctrl_t ctrl = assuan_get_pointer (ctx);
@@ -943,7 +943,7 @@
    If the option --no-verify is given, the server should not try to
    verify a signature, in case the input data is an OpenPGP combined
    message.  */
-static int 
+static gpg_error_t
 cmd_decrypt (assuan_context_t ctx, char *line)
 {
   conn_ctrl_t ctrl = assuan_get_pointer (ctx);
@@ -1058,7 +1058,7 @@
 
    The DISPLAYSTRING is a percent-and-plus-encoded string with a short
    human readable description of the status.  */
-static int 
+static gpg_error_t
 cmd_verify (assuan_context_t ctx, char *line)
 {
   conn_ctrl_t ctrl = assuan_get_pointer (ctx);
@@ -1143,7 +1143,7 @@
    manager is brought into the foregound and that this command
    immediatley returns.
 */
-static int
+static gpg_error_t
 cmd_start_keymanager (assuan_context_t ctx, char *line)
 {
   gpa_open_key_manager (NULL, NULL);
@@ -1157,7 +1157,7 @@
    manager is brought into the foregound and that this command
    immediatley returns.
 */
-static int
+static gpg_error_t
 cmd_start_cardmanager (assuan_context_t ctx, char *line)
 {
   gpa_open_cardmanager (NULL, NULL);
@@ -1172,7 +1172,7 @@
    manager is brought into the foregound and that this command
    immediatley returns.
 */
-static int
+static gpg_error_t
 cmd_start_confdialog (assuan_context_t ctx, char *line)
 {
   gpa_open_settings_dialog (NULL, NULL);
@@ -1191,7 +1191,7 @@
      version     - Return the version of the program.
      pid         - Return the process id of the server.
  */
-static int
+static gpg_error_t
 cmd_getinfo (assuan_context_t ctx, char *line)
 {
   gpg_error_t err;
@@ -1295,7 +1295,7 @@
 
    Set the files on which to operate.
  */
-static int
+static gpg_error_t
 cmd_file (assuan_context_t ctx, char *line)
 {
   gpg_error_t err = 0;
@@ -1366,7 +1366,7 @@
 
 
 /* ENCRYPT_FILES --nohup  */
-static int
+static gpg_error_t
 cmd_encrypt_files (assuan_context_t ctx, char *line)
 {
   gpg_error_t err;
@@ -1389,7 +1389,7 @@
 
 
 /* SIGN_FILES --nohup  */
-static int
+static gpg_error_t
 cmd_sign_files (assuan_context_t ctx, char *line)
 {
   gpg_error_t err;
@@ -1412,7 +1412,7 @@
 
 
 /* ENCRYPT_SIGN_FILES --nohup  */
-static int
+static gpg_error_t
 cmd_encrypt_sign_files (assuan_context_t ctx, char *line)
 {
   gpg_error_t err;
@@ -1474,7 +1474,7 @@
 
 
 /* DECRYPT_FILES --nohup  */
-static int
+static gpg_error_t
 cmd_decrypt_files (assuan_context_t ctx, char *line)
 {
   gpg_error_t err;
@@ -1497,7 +1497,7 @@
 
 
 /* VERIFY_FILES --nohup  */
-static int
+static gpg_error_t
 cmd_verify_files (assuan_context_t ctx, char *line)
 {
   gpg_error_t err;
@@ -1520,7 +1520,7 @@
 
 
 /* DECRYPT_VERIFY_FILES --nohup  */
-static int
+static gpg_error_t
 cmd_decrypt_verify_files (assuan_context_t ctx, char *line)
 {
   gpg_error_t err;
@@ -1543,7 +1543,7 @@
 
 
 /* IMPORT_FILES --nohup  */
-static int
+static gpg_error_t
 cmd_import_files (assuan_context_t ctx, char *line)
 {
   gpg_error_t err;
@@ -1567,7 +1567,7 @@
 
 
 /* CHECKSUM_CREATE_FILES --nohup  */
-static int
+static gpg_error_t
 cmd_checksum_create_files (assuan_context_t ctx, char *line)
 {
   gpg_error_t err;
@@ -1591,7 +1591,7 @@
 
 
 /* CHECKSUM_VERIFY_FILES --nohup  */
-static int
+static gpg_error_t
 cmd_checksum_verify_files (assuan_context_t ctx, char *line)
 {
   gpg_error_t err;
@@ -1614,8 +1614,8 @@
 }
 
 
-static void
-reset_notify (assuan_context_t ctx)
+static gpg_error_t
+reset_notify (assuan_context_t ctx, char *line)
 {
   conn_ctrl_t ctrl = assuan_get_pointer (ctx);
 
@@ -1639,6 +1639,7 @@
   ctrl->session_number = 0;
   xfree (ctrl->session_title);
   ctrl->session_title = NULL;
+  return 0;
 }
 
 
@@ -1648,7 +1649,7 @@
 {
   static struct {
     const char *name;
-    int (*handler)(assuan_context_t, char *line);
+    assuan_handler_t handler;
   } table[] = {
     { "SESSION", cmd_session },
     { "RECIPIENT", cmd_recipient },
@@ -1681,7 +1682,8 @@
 
   for (i=0; table[i].name; i++)
     {
-      rc = assuan_register_command (ctx, table[i].name, table[i].handler);
+      rc = assuan_register_command (ctx, table[i].name, table[i].handler,
+				    NULL);
       if (rc)
         return rc;
     } 
@@ -1692,7 +1694,7 @@
 
 /* Prepare for a new connection on descriptor FD.  */
 static assuan_context_t
-connection_startup (int fd)
+connection_startup (assuan_fd_t fd)
 {
   gpg_error_t err;
   assuan_context_t ctx;
@@ -1700,7 +1702,16 @@
 
   /* Get an Assuan context for the already accepted file descriptor
      FD.  Allow descriptor passing.  */
-  err = assuan_init_socket_server_ext (&ctx, ASSUAN_INT2FD(fd), 1|2);
+  err = assuan_new (&ctx);
+  if (err)
+    {
+      g_debug ("failed to initialize the new connection: %s",
+               gpg_strerror (err));
+      return NULL;
+    }
+
+  err = assuan_init_socket_server (ctx, fd, ASSUAN_SOCKET_SERVER_FDPASSING
+				   | ASSUAN_SOCKET_SERVER_ACCEPTED);
   if (err)
     {
       g_debug ("failed to initialize the new connection: %s",
@@ -1712,7 +1723,7 @@
     {
       g_debug ("failed to register commands with Assuan: %s",
                gpg_strerror (err));
-      assuan_deinit_server (ctx);
+      assuan_release (ctx);
       return NULL;
     }
 
@@ -1736,8 +1747,8 @@
     {
       conn_ctrl_t ctrl = assuan_get_pointer (ctx);
 
-      reset_notify (ctx);
-      assuan_deinit_server (ctx);
+      reset_notify (ctx, NULL);
+      assuan_release (ctx);
       g_free (ctrl);
       connection_counter--;
       if (!connection_counter && shutdown_pending)
@@ -1805,14 +1816,23 @@
         }
       else
         {
+	  int done = 0;
           ctrl->in_command++;
-          err = assuan_process_next (ctx);
+          err = assuan_process_next (ctx, &done);
           ctrl->in_command--;
-          g_debug ("assuan_process_next returned: %s",
-                   err == -1? "EOF": gpg_strerror (err));
+	  if (err)
+	    {
+	      g_debug ("assuan_process_next returned: %s <%s>",
+		       gpg_strerror (err), gpg_strsource (err));
+	    }
+	  else
+	    {
+	      g_debug ("assuan_process_next returned: %s",
+		       done ? "done" : "success");
+	    }
           if (gpg_err_code (err) == GPG_ERR_EAGAIN)
             ; /* Ignore.  */
-          else if (gpg_err_code (err) == GPG_ERR_EOF || err == -1)
+          else if (!err && done)
             {
               if (ctrl->cont_cmd)
                 ctrl->client_died = 1; /* Need to delay the cleanup.  */
@@ -1868,14 +1888,14 @@
       g_debug ("error accepting connection: %s", strerror (errno));
       goto leave;
     }
-  if (assuan_sock_check_nonce (ASSUAN_INT2FD(fd), &socket_nonce))
+  if (assuan_sock_check_nonce ((assuan_fd_t) fd, &socket_nonce))
     {
       g_debug ("new connection at fd %d refused", fd); 
       goto leave;
     }
 
   g_debug ("new connection at fd %d", fd);
-  ctx = connection_startup (fd);
+  ctx = connection_startup ((assuan_fd_t) fd);
   if (!ctx)
     goto leave;
 
@@ -1911,7 +1931,7 @@
 
  leave:
   if (fd != -1)
-    assuan_sock_close (ASSUAN_INT2FD (fd));
+    assuan_sock_close ((assuan_fd_t) fd);
   return TRUE; /* Keep the listen_fd in the event loop.  */
 }
 
@@ -1929,7 +1949,7 @@
   GIOChannel *channel;
   unsigned int source_id;
 
-  assuan_set_assuan_err_source (GPG_ERR_SOURCE_DEFAULT);
+  assuan_set_gpg_err_source (GPG_ERR_SOURCE_DEFAULT);
   
   socket_name = g_build_filename (gnupg_homedir, "S.uiserver", NULL);
   if (strlen (socket_name)+1 >= sizeof serv_addr.sun_path ) 
@@ -1974,14 +1994,14 @@
   g_free (socket_name);
   socket_name = NULL;
 
-  if (listen (ASSUAN_FD2INT (fd), 5) == -1)
+  if (listen ((int) fd, 5) == -1)
     {
       g_debug ("listen() failed: %s\n", strerror (errno));
       assuan_sock_close (fd);
       return;
     }
 #ifdef HAVE_W32_SYSTEM
-  channel = g_io_channel_win32_new_socket (ASSUAN_FD2INT(fd));
+  channel = g_io_channel_win32_new_socket ((int) fd);
 #else
   channel = g_io_channel_unix_new (fd);
 #endif
