--- putget.c.orig
+++ putget.c
@@ -30,6 +30,7 @@
     *expand_variables(),
     *find_robot_action_string(),
     *return_last();
+extern void cmd_putfile(), cmd_getfile();
 
 /*  This is a temporary buffer of text received from the MUD game.
  *  If the flag "getfiling" is true, the routines that receive the MUD
@@ -44,7 +45,7 @@
 /*---------------------------------------------------------------------------*/
 
 /* Send a file to LPmud using the built-in editor */
-cmd_putfile(filename, optional_filename)
+void cmd_putfile(filename, optional_filename)
 char *filename, *optional_filename;
 {
     char *local_filename, *remote_filename, cmd_buffer[MAX_LINE_LENGTH + 1];
@@ -103,7 +104,7 @@
 /*---------------------------------------------------------------------------*/
 
 /* Get a file from LPmud using the built-in editor */
-cmd_getfile(filename, optional_filename)
+void cmd_getfile(filename, optional_filename)
 char *filename, *optional_filename;
 {
     char *local_filename, *remote_filename, cmd_buffer[MAX_LINE_LENGTH + 1];
