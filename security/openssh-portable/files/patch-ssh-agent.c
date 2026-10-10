--- UTC
r110506 | des | 2003-02-07 09:48:27 -0600 (Fri, 07 Feb 2003) | 4 lines

Set the ruid to the euid at startup as a workaround for a bug in pam_ssh.

r226103 | des | 2011-10-07 08:10:16 -0500 (Fri, 07 Oct 2011) | 5 lines

Add a -x option that causes ssh-agent(1) to exit when all clients have
disconnected.

--- ssh-agent.c.orig	2026-10-06 01:45:31.000000000 -0700
+++ ssh-agent.c	2026-10-10 10:04:29.143375000 -0700
@@ -198,11 +198,28 @@ static char *websafe_allowlist;
 static int restrict_websafe = 1;
 static char *websafe_allowlist;
 
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
 	size_t i;
+	int last = 0;
 
+	if (e->type == AUTH_CONNECTION) {
+		debug("xcount %d -> %d", xcount, xcount - 1);
+		if (--xcount == 0)
+			last = 1;
+	}
+
 	close(e->fd);
 	sshbuf_free(e->input);
 	sshbuf_free(e->output);
@@ -215,6 +232,8 @@ close_socket(SocketEntry *e)
 	memset(e, '\0', sizeof(*e));
 	e->fd = -1;
 	e->type = AUTH_UNUSED;
+	if (last)
+		cleanup_exit(0);
 }
 
 static void
@@ -1947,6 +1966,10 @@ new_socket(sock_type type, int fd)
 
 	debug_f("type = %s", type == AUTH_CONNECTION ? "CONNECTION" :
 	    (type == AUTH_SOCKET ? "SOCKET" : "UNKNOWN"));
+	if (type == AUTH_CONNECTION) {
+		debug("xcount %d -> %d", xcount, xcount + 1);
+		++xcount;
+	}
 	set_nonblock(fd);
 
 	if (fd > max_fd)
@@ -2240,7 +2263,7 @@ usage(void)
 usage(void)
 {
 	fprintf(stderr,
-	    "usage: ssh-agent [-c | -s] [-DdU] [-T | -A directory | -a bind_address]\n"
+	    "usage: ssh-agent [-c | -s] [-DdUx] [-T | -A directory | -a bind_address]\n"
 	    "                 [-E fingerprint_hash] [-O option]\n"
 	    "                 [-P allowed_providers] [-t life]\n"
 	    "       ssh-agent [-U] [-T | -A directory | -a bind_address]\n"
@@ -2285,6 +2308,7 @@ main(int ac, char **av)
 	/* drop */
 	(void)setegid(getgid());
 	(void)setgid(getgid());
+	(void)setuid(geteuid());
 
 	platform_disable_tracing(0);	/* strict=no */
 
@@ -2300,7 +2324,7 @@ main(int ac, char **av)
 	__progname = ssh_get_progname(av[0]);
 	seed_rng();
 
-	while ((ch = getopt(ac, av, "cDdksTuUVA:E:a:O:P:t:")) != -1) {
+	while ((ch = getopt(ac, av, "cDdksTuUVA:E:a:O:P:t:x")) != -1) {
 		switch (ch) {
 		case 'E':
 			fingerprint_hash = ssh_digest_alg_by_name(optarg);
@@ -2360,6 +2384,9 @@ main(int ac, char **av)
 				usage();
 			}
 			break;
+		case 'x':
+			xcount = 0;
+			break;
 		case 'T':
 			T_flag++;
 			break;
