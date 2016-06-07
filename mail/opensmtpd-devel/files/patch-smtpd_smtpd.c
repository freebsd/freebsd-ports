--- smtpd/smtpd.c.orig	2016-06-06 20:51:18 UTC
+++ smtpd/smtpd.c
@@ -1,4 +1,4 @@
-/*	$OpenBSD: smtpd.c,v 1.277 2016/05/28 21:21:20 eric Exp $	*/
+/*	$OpenBSD: smtpd.c,v 1.278 2016/06/07 06:52:49 gilles Exp $	*/
 
 /*
  * Copyright (c) 2008 Gilles Chehade <gilles@poolp.org>
@@ -843,9 +843,12 @@ start_child(int save_argc, char **save_a
 	if (save_argc >= SMTPD_MAXARG - 2)
 		fatalx("too many arguments");
 
-	if (socketpair(AF_UNIX, SOCK_STREAM|SOCK_NONBLOCK, PF_UNSPEC, sp) == -1)
+	if (socketpair(AF_UNIX, SOCK_STREAM, PF_UNSPEC, sp) == -1)
 		fatal("socketpair");
 
+	io_set_nonblocking(sp[0]);
+	io_set_nonblocking(sp[1]);
+
 	switch (pid = fork()) {
 	case -1:
 		fatal("%s: fork", save_argv[0]);
@@ -884,9 +887,12 @@ setup_peers(struct mproc *a, struct mpro
 {
 	int sp[2];
 
-	if (socketpair(AF_UNIX, SOCK_STREAM|SOCK_NONBLOCK, PF_UNSPEC, sp) == -1)
+	if (socketpair(AF_UNIX, SOCK_STREAM, PF_UNSPEC, sp) == -1)
 		fatal("socketpair");
 
+	io_set_nonblocking(sp[0]);
+	io_set_nonblocking(sp[1]);
+
 	if (imsg_compose(&a->imsgbuf, IMSG_SETUP_PEER, b->proc, b->pid, sp[0],
 	    NULL, 0) == -1)
 		fatal("imsg_compose");
