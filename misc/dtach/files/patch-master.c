--- master.c.orig	2008-01-30 21:59:54.000000000 -0800
+++ master.c	2010-01-12 10:30:56.000000000 -0800
@@ -53,6 +53,8 @@
 static struct client *clients;
 /* The pseudo-terminal created for the child process. */
 static struct pty the_pty;
+/* The mode of the socket */
+static mode_t socket_mode;
 
 #ifndef HAVE_FORKPTY
 pid_t forkpty(int *amaster, char *name, struct termios *termp,
@@ -66,6 +68,19 @@
 	unlink(sockname);
 }
 
+/* Check the actual mode of the socket */
+static void
+check_socket_mode(int has_attached_client)
+{
+	if (has_attached_client && ((socket_mode & 0100) != 0100)) {
+		socket_mode |= 0100;
+		chmod(sockname, socket_mode);
+	} else if (!has_attached_client && ((socket_mode & 0100) == 0100)) {
+		socket_mode &= ~0100;
+		chmod(sockname, socket_mode);
+	}
+}
+
 /* Signal */
 static RETSIGTYPE 
 die(int sig)
@@ -206,7 +221,8 @@
 		return -1;
 	}
 	/* chmod it to prevent any suprises */
-	if (chmod(name, 0600) < 0)
+	socket_mode = 0600;
+	if (chmod(name, socket_mode) < 0)
 	{
 		close(s);
 		return -1;
@@ -454,6 +470,8 @@
 	/* Loop forever. */
 	while (1)
 	{
+		int has_attached_client = 0;
+
 		/* Re-initialize the file descriptor set for select. */
 		FD_ZERO(&readfds);
 		FD_SET(s, &readfds);
@@ -480,8 +498,14 @@
 			FD_SET(p->fd, &readfds);
 			if (p->fd > highest_fd)
 				highest_fd = p->fd;
+
+			if (p->attached) {
+				has_attached_client = 1;
+			}
 		}
 
+		check_socket_mode(has_attached_client);
+
 		/* Wait for something to happen. */
 		if (select(highest_fd + 1, &readfds, NULL, NULL, NULL) < 0)
 		{
