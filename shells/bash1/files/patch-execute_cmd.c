--- execute_cmd.c.orig	Thu Jun  8 17:29:00 1995
+++ execute_cmd.c	Fri Nov 24 14:41:40 2000
@@ -2718,6 +2718,7 @@
   char *redirectee_word;
   enum r_instruction ri = redirect->instruction;
   REDIRECT *new_redirect;
+  mode_t um;
 
   if (ri == r_duplicating_input_word || ri == r_duplicating_output_word)
     {
@@ -2938,11 +2939,15 @@
 	  pid_t pid = getpid ();
 
 	  /* Make the filename for the temp file. */
-	  sprintf (filename, "/tmp/t%d-sh", pid);
+	  sprintf (filename, "/tmp/t-sh-XXXXXX", pid);
 
-	  fd = open (filename, O_TRUNC | O_WRONLY | O_CREAT, 0666);
+	  /* O_TRUNC | O_WRONLY | O_CREAT */
+	  fd = mkstemp (filename);
 	  if (fd < 0)
 	    return (errno);
+	  um=umask(022);
+	  umask(um);
+	  fchmod(fd, 0666 & ~um);
 
 	  errno = 0;		/* XXX */
 	  if (redirectee->word)
