--- UTC
r110506 | des | 2003-02-07 09:48:27 -0600 (Fri, 07 Feb 2003) | 4 lines

Set the ruid to the euid at startup as a workaround for a bug in pam_ssh.

r226103 | des | 2011-10-07 08:10:16 -0500 (Fri, 07 Oct 2011) | 5 lines

Add a -x option that causes ssh-agent(1) to exit when all clients have
disconnected.

--- ssh-agent.c.orig	2015-05-29 03:27:21.000000000 -0500
+++ ssh-agent.c	2015-06-02 09:46:54.719580000 -0500
@@ -157,15 +157,34 @@ static long lifetime = 0;
 
 static int fingerprint_hash = SSH_FP_HASH_DEFAULT;
 
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
 	sshbuf_free(e->input);
 	sshbuf_free(e->output);
 	sshbuf_free(e->request);
+	if (last)
+		cleanup_exit(0);
 }
 
 static void
@@ -963,6 +982,10 @@ new_socket(sock_type type, int fd)
 {
 	u_int i, old_alloc, new_alloc;
 
+	if (type == AUTH_CONNECTION) {
+		debug("xcount %d -> %d", xcount, xcount + 1);
+		++xcount;
+	}
 	set_nonblock(fd);
 
 	if (fd > max_fd)
@@ -1190,7 +1213,7 @@ static void
 usage(void)
 {
 	fprintf(stderr,
-	    "usage: ssh-agent [-c | -s] [-Dd] [-a bind_address] [-E fingerprint_hash]\n"
+	    "usage: ssh-agent [-c | -s] [-Ddx] [-a bind_address] [-E fingerprint_hash]\n"
 	    "                 [-P pkcs11_whitelist] [-t life] [command [arg ...]]\n"
 	    "       ssh-agent [-c | -s] -k\n");
 	exit(1);
@@ -1222,6 +1245,7 @@ main(int ac, char **av)
 	/* drop */
 	setegid(getgid());
 	setgid(getgid());
+	setuid(geteuid());
 
 	platform_disable_tracing(0);	/* strict=no */
 
@@ -1232,7 +1256,7 @@ main(int ac, char **av)
 	__progname = ssh_get_progname(av[0]);
 	seed_rng();
 
-	while ((ch = getopt(ac, av, "cDdksE:a:P:t:")) != -1) {
+	while ((ch = getopt(ac, av, "cDdksE:a:P:t:x")) != -1) {
 		switch (ch) {
 		case 'E':
 			fingerprint_hash = ssh_digest_alg_by_name(optarg);
@@ -1276,6 +1300,9 @@ main(int ac, char **av)
 				usage();
 			}
 			break;
+		case 'x':
+			xcount = 0;
+			break;
 		default:
 			usage();
 		}
