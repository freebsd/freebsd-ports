--- src/utilunix.c.orig	Thu Dec 26 20:47:46 2002
+++ src/utilunix.c	Tue Jun 15 03:15:09 2004
@@ -280,9 +280,7 @@
 	if (!p){
 	    passwd = getpwnam (directory);
 	} else {
-	    name = g_malloc (p - directory + 1);
-	    strncpy (name, directory, p - directory);
-	    name [p - directory] = 0;
+	    name = g_strndup (directory, p - directory);
 	    passwd = getpwnam (name);
 	    g_free (name);
 	}
@@ -298,7 +296,7 @@
 
 /*
  * Return the directory where mc should keep its temporary files.
- * This directory is (in Bourne shell terms) "${TMPDIR=/tmp}-$USER"
+ * This directory is (in Bourne shell terms) "${TMPDIR=/tmp}/mc-$USER"
  * When called the first time, the directory is created if needed.
  * The first call should be done early, since we are using fprintf()
  * and not message() to report possible problems.
@@ -372,6 +370,7 @@
 	if (fallback_ok) {
 	    fprintf (stderr, _("Temporary files will be created in %s\n"),
 		     sys_tmp);
+	    error = NULL;
 	} else {
 	    fprintf (stderr, _("Temporary files will not be created\n"));
 	    tmpdir = "/dev/null/";
@@ -380,6 +379,9 @@
 	fprintf (stderr, "%s\n", _("Press any key to continue..."));
 	getc (stdin);
     }
+
+    if (!error)
+	setenv ("MC_TMPDIR", tmpdir, 1);
 
     return tmpdir;
 }
