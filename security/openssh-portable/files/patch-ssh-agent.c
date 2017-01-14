--- UTC
r110506 | des | 2003-02-07 09:48:27 -0600 (Fri, 07 Feb 2003) | 4 lines

Set the ruid to the euid at startup as a workaround for a bug in pam_ssh.

r226103 | des | 2011-10-07 08:10:16 -0500 (Fri, 07 Oct 2011) | 5 lines

Add a -x option that causes ssh-agent(1) to exit when all clients have
disconnected.

Add a -P option to specify PKCS11_WHITELIST (fixes CVE-2016-10009)


--- ssh-agent.c.orig	2016-07-27 17:54:27.000000000 -0500
+++ ssh-agent.c	2017-01-11 19:02:59.600125000 -0600
@@ -83,11 +83,16 @@
 #include "misc.h"
 #include "digest.h"
 #include "ssherr.h"
+#include "match.h"
 
 #ifdef ENABLE_PKCS11
 #include "ssh-pkcs11.h"
 #endif
 
+#ifndef DEFAULT_PKCS11_WHITELIST
+# define DEFAULT_PKCS11_WHITELIST "/usr/lib/*,/usr/local/lib/*"
+#endif
+
 typedef enum {
 	AUTH_UNUSED,
 	AUTH_SOCKET,
@@ -135,6 +140,9 @@
 char socket_name[PATH_MAX];
 char socket_dir[PATH_MAX];
 
+/* PKCS#11 path whitelist */
+static char *pkcs11_whitelist;
+
 /* locking */
 #define LOCK_SIZE	32
 #define LOCK_SALT_SIZE	16
@@ -150,15 +158,34 @@
 
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
@@ -738,7 +765,7 @@
 static void
 process_add_smartcard_key(SocketEntry *e)
 {
-	char *provider = NULL, *pin;
+	char *provider = NULL, *pin, canonical_provider[PATH_MAX];
 	int r, i, version, count = 0, success = 0, confirm = 0;
 	u_int seconds;
 	time_t death = 0;
@@ -770,10 +797,21 @@
 			goto send;
 		}
 	}
+	if (realpath(provider, canonical_provider) == NULL) {
+		verbose("failed PKCS#11 add of \"%.100s\": realpath: %s",
+		    provider, strerror(errno));
+		goto send;
+	}
+	if (match_pattern_list(canonical_provider, pkcs11_whitelist, 0) != 1) {
+		verbose("refusing PKCS#11 add of \"%.100s\": "
+		    "provider not whitelisted", canonical_provider);
+		goto send;
+	}
+	debug("%s: add %.100s", __func__, canonical_provider);
 	if (lifetime && !death)
 		death = monotime() + lifetime;
 
-	count = pkcs11_add_provider(provider, pin, &keys);
+	count = pkcs11_add_provider(canonical_provider, pin, &keys);
 	for (i = 0; i < count; i++) {
 		k = keys[i];
 		version = k->type == KEY_RSA1 ? 1 : 2;
@@ -781,8 +819,8 @@
 		if (lookup_identity(k, version) == NULL) {
 			id = xcalloc(1, sizeof(Identity));
 			id->key = k;
-			id->provider = xstrdup(provider);
-			id->comment = xstrdup(provider); /* XXX */
+			id->provider = xstrdup(canonical_provider);
+			id->comment = xstrdup(canonical_provider); /* XXX */
 			id->death = death;
 			id->confirm = confirm;
 			TAILQ_INSERT_TAIL(&tab->idlist, id, next);
@@ -945,6 +983,10 @@
 {
 	u_int i, old_alloc, new_alloc;
 
+	if (type == AUTH_CONNECTION) {
+		debug("xcount %d -> %d", xcount, xcount + 1);
+		++xcount;
+	}
 	set_nonblock(fd);
 
 	if (fd > max_fd)
@@ -1172,8 +1214,8 @@
 usage(void)
 {
 	fprintf(stderr,
-	    "usage: ssh-agent [-c | -s] [-Dd] [-a bind_address] [-E fingerprint_hash]\n"
-	    "                 [-t life] [command [arg ...]]\n"
+	    "usage: ssh-agent [-c | -s] [-Ddx] [-a bind_address] [-E fingerprint_hash]\n"
+	    "                 [-P pkcs11_whitelist] [-t life] [command [arg ...]]\n"
 	    "       ssh-agent [-c | -s] -k\n");
 	exit(1);
 }
@@ -1204,6 +1246,7 @@
 	/* drop */
 	setegid(getgid());
 	setgid(getgid());
+	setuid(geteuid());
 
 	platform_disable_tracing(0);	/* strict=no */
 
@@ -1214,7 +1257,7 @@
 	__progname = ssh_get_progname(av[0]);
 	seed_rng();
 
-	while ((ch = getopt(ac, av, "cDdksE:a:t:")) != -1) {
+	while ((ch = getopt(ac, av, "cDdksE:a:P:t:x")) != -1) {
 		switch (ch) {
 		case 'E':
 			fingerprint_hash = ssh_digest_alg_by_name(optarg);
@@ -1229,6 +1272,11 @@
 		case 'k':
 			k_flag++;
 			break;
+		case 'P':
+			if (pkcs11_whitelist != NULL)
+				fatal("-P option already specified");
+			pkcs11_whitelist = xstrdup(optarg);
+			break;
 		case 's':
 			if (c_flag)
 				usage();
@@ -1253,6 +1301,9 @@
 				usage();
 			}
 			break;
+		case 'x':
+			xcount = 0;
+			break;
 		default:
 			usage();
 		}
@@ -1263,6 +1314,9 @@
 	if (ac > 0 && (c_flag || k_flag || s_flag || d_flag || D_flag))
 		usage();
 
+	if (pkcs11_whitelist == NULL)
+		pkcs11_whitelist = xstrdup(DEFAULT_PKCS11_WHITELIST);
+
 	if (ac == 0 && !c_flag && !s_flag) {
 		shell = getenv("SHELL");
 		if (shell != NULL && (len = strlen(shell)) > 2 &&
@@ -1410,7 +1464,7 @@
 	signal(SIGTERM, cleanup_handler);
 	nalloc = 0;
 
-	if (pledge("stdio cpath unix id proc exec", NULL) == -1)
+	if (pledge("stdio rpath cpath unix id proc exec", NULL) == -1)
 		fatal("%s: pledge: %s", __progname, strerror(errno));
 	platform_pledge_agent();
 
