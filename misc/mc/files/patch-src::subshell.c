--- src/subshell.c.orig	Mon Oct 21 01:43:29 2002
+++ src/subshell.c	Mon Oct 21 02:37:56 2002
@@ -852,6 +852,8 @@
 /* If it actually changed the directory it returns true */
 void do_subshell_chdir (const char *directory, int do_update, int reset_prompt)
 {
+    char buf[MAXPATHLEN];
+
     if (!(subshell_state == INACTIVE && strcmp (subshell_cwd, cpanel->cwd))){
 	/* We have to repaint the subshell prompt if we read it from
 	 * the main program.  Please note that in the code after this
@@ -878,7 +880,12 @@
     subshell_state = RUNNING_COMMAND;
     feed_subshell (QUIETLY, FALSE);
     
-    if (subshell_alive && strcmp (subshell_cwd, cpanel->cwd) && strcmp (cpanel->cwd, "."))
+    if (subshell_alive
+    && strcmp (subshell_cwd, cpanel->cwd)
+    && strcmp (cpanel->cwd, ".")
+    && (subshell_type != TCSH ||
+      realpath (subshell_cwd, buf) == NULL ||
+      strcmp (cpanel->cwd, buf)))
 	fprintf (stderr, _("Warning: Couldn't change to %s.\n"), cpanel->cwd);
 
     if (reset_prompt)
