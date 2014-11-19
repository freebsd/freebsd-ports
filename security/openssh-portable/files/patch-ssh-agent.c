r110506 | des | 2003-02-07 09:48:27 -0600 (Fri, 07 Feb 2003) | 4 lines

Set the ruid to the euid at startup as a workaround for a bug in pam_ssh.

r226103 | des | 2011-10-07 08:10:16 -0500 (Fri, 07 Oct 2011) | 5 lines

Add a -x option that causes ssh-agent(1) to exit when all clients have
disconnected.

--- ssh-agent.c.orig	2014-07-29 21:32:46.000000000 -0500
+++ ssh-agent.c	2014-11-03 16:48:03.930786112 -0600
@@ -142,15 +142,34 @@ extern char *__progname;
 /* Default lifetime in seconds (0 == forever) */
 static long lifetime = 0;
 
+/*
+ * Client connection count; incremented in new_socket() and decremented in
+ * close_socket().  When it reaches 0, ssh-agent will exit.  Since it is
+ * normally initialized to 1, it will never reach 0.  However, if the -x
+ * option is specified, it is initialized to 0 in main(); in that case,
+ * ssh-agent will exit as soon as it has had at least one client but no
+ * longer has any.
+ */
+static int xcount = 1;
+
 static void
 close_socket(SocketEntry *e)
 {
+	int last = 0;
+
+	if (e->type == AUTH_CONNECTION) {
+		debug("xcount %d -> %d", xcount, xcount - 1);
+		if (--xcount == 0)
+			last = 1;
+	}
 	close(e->fd);
 	e->fd = -1;
 	e->type = AUTH_UNUSED;
 	buffer_free(&e->input);
 	buffer_free(&e->output);
 	buffer_free(&e->request);
+	if (last)
+		cleanup_exit(0);
 }
 
 static void
@@ -810,6 +829,10 @@ new_socket(sock_type type, int fd)
 {
 	u_int i, old_alloc, new_alloc;
 
+	if (type == AUTH_CONNECTION) {
+		debug("xcount %d -> %d", xcount, xcount + 1);
+		++xcount;
+	}
 	set_nonblock(fd);
 
 	if (fd > max_fd)
@@ -1026,7 +1049,7 @@ usage(void)
 {
 	fprintf(stderr,
 	    "usage: ssh-agent [-c | -s] [-d] [-a bind_address] [-t life]\n"
-	    "                 [command [arg ...]]\n"
+	    "                 [-x] [command [arg ...]]\n"
 	    "       ssh-agent [-c | -s] -k\n");
 	exit(1);
 }
@@ -1056,6 +1079,7 @@ main(int ac, char **av)
 	/* drop */
 	setegid(getgid());
 	setgid(getgid());
+	setuid(geteuid());
 
 #if defined(HAVE_PRCTL) && defined(PR_SET_DUMPABLE)
 	/* Disable ptrace on Linux without sgid bit */
@@ -1069,7 +1093,7 @@ main(int ac, char **av)
 	__progname = ssh_get_progname(av[0]);
 	seed_rng();
 
-	while ((ch = getopt(ac, av, "cdksa:t:")) != -1) {
+	while ((ch = getopt(ac, av, "cdksa:t:x")) != -1) {
 		switch (ch) {
 		case 'c':
 			if (s_flag)
@@ -1098,6 +1122,9 @@ main(int ac, char **av)
 				usage();
 			}
 			break;
+		case 'x':
+			xcount = 0;
+			break;
 		default:
 			usage();
 		}
