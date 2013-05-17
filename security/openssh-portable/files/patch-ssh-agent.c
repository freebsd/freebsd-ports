r110506 | des | 2003-02-07 09:48:27 -0600 (Fri, 07 Feb 2003) | 4 lines

Set the ruid to the euid at startup as a workaround for a bug in pam_ssh.

r226103 | des | 2011-10-07 08:10:16 -0500 (Fri, 07 Oct 2011) | 5 lines

Add a -x option that causes ssh-agent(1) to exit when all clients have
disconnected.

--- ssh-agent.c.orig	2011-06-02 23:14:16.000000000 -0500
+++ ssh-agent.c	2013-05-09 15:59:14.044627857 -0500
@@ -137,15 +137,34 @@
 /* Default lifetime (0 == forever) */
 static int lifetime = 0;
 
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
@@ -900,6 +919,10 @@
 {
 	u_int i, old_alloc, new_alloc;
 
+	if (type == AUTH_CONNECTION) {
+		debug("xcount %d -> %d", xcount, xcount + 1);
+		++xcount;
+	}
 	set_nonblock(fd);
 
 	if (fd > max_fd)
@@ -1120,6 +1143,7 @@
 	fprintf(stderr, "  -d          Debug mode.\n");
 	fprintf(stderr, "  -a socket   Bind agent socket to given name.\n");
 	fprintf(stderr, "  -t life     Default identity lifetime (seconds).\n");
+	fprintf(stderr, "  -x          Exit when the last client disconnects.\n");
 	exit(1);
 }
 
@@ -1149,6 +1173,7 @@
 	/* drop */
 	setegid(getgid());
 	setgid(getgid());
+	setuid(geteuid());
 
 #if defined(HAVE_PRCTL) && defined(PR_SET_DUMPABLE)
 	/* Disable ptrace on Linux without sgid bit */
@@ -1160,7 +1185,7 @@
 	__progname = ssh_get_progname(av[0]);
 	seed_rng();
 
-	while ((ch = getopt(ac, av, "cdksa:t:")) != -1) {
+	while ((ch = getopt(ac, av, "cdksa:t:x")) != -1) {
 		switch (ch) {
 		case 'c':
 			if (s_flag)
@@ -1189,6 +1214,9 @@
 				usage();
 			}
 			break;
+		case 'x':
+			xcount = 0;
+			break;
 		default:
 			usage();
 		}
@@ -1348,8 +1376,7 @@
 	if (ac > 0)
 		parent_alive_interval = 10;
 	idtab_init();
-	if (!d_flag)
-		signal(SIGINT, SIG_IGN);
+	signal(SIGINT, d_flag ? cleanup_handler : SIG_IGN);
 	signal(SIGPIPE, SIG_IGN);
 	signal(SIGHUP, cleanup_handler);
 	signal(SIGTERM, cleanup_handler);
