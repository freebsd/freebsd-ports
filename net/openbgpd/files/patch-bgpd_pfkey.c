Index: bgpd/pfkey.c
===================================================================
RCS file: /home/cvs/private/hrs/openbgpd/bgpd/pfkey.c,v
retrieving revision 1.1.1.1
retrieving revision 1.1.1.2
diff -u -p -r1.1.1.1 -r1.1.1.2
--- bgpd/pfkey.c	30 Jun 2009 05:46:15 -0000	1.1.1.1
+++ bgpd/pfkey.c	9 Jul 2009 16:49:54 -0000	1.1.1.2
@@ -1,4 +1,4 @@
-/*	$OpenBSD: pfkey.c,v 1.34 2006/10/26 14:26:49 henning Exp $ */
+/*	$OpenBSD: pfkey.c,v 1.37 2009/04/21 15:25:52 henning Exp $ */
 
 /*
  * Copyright (c) 2003, 2004 Henning Brauer <henning@openbsd.org>
@@ -36,7 +36,8 @@
 #define	ROUNDUP(x) (((x) + (PFKEY2_CHUNK - 1)) & ~(PFKEY2_CHUNK - 1))
 #define	IOV_CNT	20
 
-static u_int32_t	sadb_msg_seq = 1;
+static u_int32_t	sadb_msg_seq = 0;
+static u_int32_t	pid = 0; /* should pid_t but pfkey needs u_int32_t */
 static int		fd;
 
 int	pfkey_reply(int, u_int32_t *);
@@ -74,6 +75,9 @@ pfkey_send(int sd, uint8_t satype, uint8
 	int			iov_cnt;
 	struct sockaddr_storage	ssrc, sdst, speer, smask, dmask;
 
+	if (!pid)
+		pid = getpid();
+
 	/* we need clean sockaddr... no ports set */
 	bzero(&ssrc, sizeof(ssrc));
 	bzero(&smask, sizeof(smask));
@@ -129,8 +133,8 @@ pfkey_send(int sd, uint8_t satype, uint8
 
 	bzero(&smsg, sizeof(smsg));
 	smsg.sadb_msg_version = PF_KEY_V2;
-	smsg.sadb_msg_seq = sadb_msg_seq++;
-	smsg.sadb_msg_pid = getpid();
+	smsg.sadb_msg_seq = ++sadb_msg_seq;
+	smsg.sadb_msg_pid = pid;
 	smsg.sadb_msg_len = sizeof(smsg) / 8;
 	smsg.sadb_msg_type = mtype;
 	smsg.sadb_msg_satype = satype;
@@ -415,10 +419,23 @@ pfkey_reply(int sd, u_int32_t *spip)
 	u_int8_t *data;
 	ssize_t len;
 
-	if (recv(sd, &hdr, sizeof(hdr), MSG_PEEK) != sizeof(hdr)) {
-		log_warn("pfkey peek");
-		return (-1);
+	for (;;) {
+		if (recv(sd, &hdr, sizeof(hdr), MSG_PEEK) != sizeof(hdr)) {
+			log_warn("pfkey peek");
+			return (-1);
+		}
+
+		if (hdr.sadb_msg_seq == sadb_msg_seq &&
+		    hdr.sadb_msg_pid == pid)
+			break;
+
+		/* not ours, discard */
+		if (read(sd, &hdr, sizeof(hdr)) == -1) {
+			log_warn("pfkey read");
+			return (-1);
+		}
 	}
+
 	if (hdr.sadb_msg_errno != 0) {
 		errno = hdr.sadb_msg_errno;
 		if (errno == ESRCH)
@@ -497,6 +514,8 @@ pfkey_sa_remove(struct bgpd_addr *src, s
 int
 pfkey_md5sig_establish(struct peer *p)
 {
+	sleep(1);
+
 	if (!p->auth.spi_out)
 		if (pfkey_sa_add(&p->auth.local_addr, &p->conf.remote_addr,
 		    p->conf.auth.md5key_len, p->conf.auth.md5key,
