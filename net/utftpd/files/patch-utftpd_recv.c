--- utftpd_recv.c.orig	Mon Nov  1 10:02:32 1999
+++ utftpd_recv.c	Fri Jun 11 16:37:25 2004
@@ -69,7 +69,7 @@
 	struct sigaction old_sa;
 	const char *errortext;
 	size_t sendlength;
-	short got_blockno;
+	unsigned short got_blockno;
 	short got_opcode;
 	int is_final=0;
 
@@ -82,6 +82,7 @@
 
 	blockno=1;
 	got=flags->segsize+TFTP_OFFSET;
+	flags->sendbuf.hdr->th_block = htons(0);
 	sendlength=flags->first_packet_length+TFTP_OFFSET;
 
 	while (1) {

