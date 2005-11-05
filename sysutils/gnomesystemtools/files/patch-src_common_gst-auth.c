--- src/common/gst-auth.c.orig	Mon Aug  8 15:00:01 2005
+++ src/common/gst-auth.c	Sat Sep 10 01:47:35 2005
@@ -55,6 +55,82 @@
 static int root;			/* if we are root, no password is
 					   required */
 
+#ifdef __FreeBSD__
+static int
+_forkpty (int *amaster, char *name,
+	  struct termios *termp, struct winsize *winp)
+{
+	int master, slave;
+	char *line;
+	pid_t pid;
+
+	master = posix_openpt (O_RDWR);
+	if (master == -1)
+		return (-1);
+
+	if (grantpt (master) == -1)
+	{
+		(void) close (master);
+		return (-1);
+	}
+
+	if (unlockpt (master) == -1)
+	{
+		(void) close (master);
+		return (-1);
+	}
+
+	line = ptsname (master);
+	if (line == NULL)
+	{
+		(void) close (master);
+		return (-1);
+	}
+
+	slave = open (line, O_RDWR);
+	if (slave < 0)
+	{
+		(void) close (master);
+		return (-1);
+	}
+
+	if (amaster)
+		*amaster = master;
+
+	if (name)
+		strcpy (name, line);
+
+	if (termp)
+		(void) tcsetattr(slave, TCSAFLUSH, termp);
+
+	if (winp)
+		(void) ioctl(slave, TIOCSWINSZ, (char *) winp);
+
+	pid = fork ();
+	switch (pid)
+	{
+		case -1:
+			(void) close (slave);
+			(void) close (master);
+			return (-1);
+		case 0:
+			(void) close (master);
+			dup2 (slave, STDIN_FILENO);
+			dup2 (slave, STDOUT_FILENO);
+			dup2 (slave, STDERR_FILENO);
+			return (0);
+		default:
+			(void) close (slave);
+			return (pid);
+	}
+
+	(void) close (master);
+	return (-1);
+}
+#else
+#define _forkpty forkpty
+#endif
+
 static void
 gst_auth_display_error_message (GstTool *tool, gchar *primary_text, gchar *secondary_text)
 {
@@ -125,7 +201,7 @@ gst_auth_run_term (GstTool *tool, gchar 
 	int p[2];
 
 	pipe (p);
-	tool->backend_pid = forkpty (&tool->write_fd, NULL, NULL, NULL);
+	tool->backend_pid = _forkpty (&tool->write_fd, NULL, NULL, NULL);
 
 	if (tool->backend_pid < 0) {
 		gst_auth_display_error_message (tool,
@@ -142,12 +218,12 @@ gst_auth_run_term (GstTool *tool, gchar 
 		unsetenv("LANG");
 		unsetenv("LANGUAGE");
 
-		dup2 (p[1], 1);
-		dup2 (p[1], 2);
+		dup2 (p[1], STDOUT_FILENO);
+		dup2 (p[1], STDERR_FILENO);
 		close (p[0]);
 
 		execv (args[0], args);
-		exit (255);
+		_exit (255);
 	} else {
 #ifndef __FreeBSD__
 		/* Linux's su works ok with echo disabling */
