--- src/subshell.c.orig	Sat Jan 25 03:37:28 2003
+++ src/subshell.c	Mon Feb 10 01:10:59 2003
@@ -806,6 +806,8 @@
 /* If it actually changed the directory it returns true */
 void do_subshell_chdir (const char *directory, int do_update, int reset_prompt)
 {
+    char buf[MAXPATHLEN];
+
     if (!(subshell_state == INACTIVE && strcmp (subshell_cwd, cpanel->cwd))){
 	/* We have to repaint the subshell prompt if we read it from
 	 * the main program.  Please note that in the code after this
@@ -838,7 +840,12 @@
     subshell_state = RUNNING_COMMAND;
     feed_subshell (QUIETLY, FALSE);
     
-    if (subshell_alive && strcmp (subshell_cwd, cpanel->cwd) && strcmp (cpanel->cwd, "."))
+    if (subshell_alive
+    && strcmp (subshell_cwd, cpanel->cwd)
+    && strcmp (cpanel->cwd, ".")
+    && (subshell_type != TCSH ||
+      realpath (subshell_cwd, buf) == NULL ||
+      strcmp (cpanel->cwd, buf)))
 	fprintf (stderr, _("Warning: Cannot change to %s.\n"), cpanel->cwd);
 
     if (reset_prompt)
