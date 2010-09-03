--- ./libdnet-stripped/include/dnet/sctp.h.orig	2009-07-05 23:02:43.000000000 +0200
+++ ./libdnet-stripped/include/dnet/sctp.h	2010-09-03 21:04:28.000000000 +0200
@@ -36,7 +36,7 @@
 	sctp_pack_p->sh_vtag = htonl(vtag);				\
 } while (0)
 
-struct sctp_chunkhdr {
+struct dnet_sctp_chunkhdr {
 	uint8_t		sch_type;	/* chunk type */
 	uint8_t		sch_flags;	/* chunk flags */
 	uint16_t	sch_length;	/* chunk length */
@@ -70,7 +70,7 @@
 #define SCTP_TYPEFLAG_SKIP	2
 
 #define sctp_pack_chunkhdr(hdr, type, flags, length) do {		\
-	struct sctp_chunkhdr *sctp_pack_chp = (struct sctp_chunkhdr *)(hdr);\
+	struct dnet_sctp_chunkhdr *sctp_pack_chp = (struct dnet_sctp_chunkhdr *)(hdr);\
 	sctp_pack_chp->sch_type = type;					\
 	sctp_pack_chp->sch_flags = flags;				\
 	sctp_pack_chp->sch_length = htons(length);			\
@@ -80,7 +80,7 @@
  * INIT chunk
  */
 struct sctp_chunkhdr_init {
-	struct sctp_chunkhdr chunkhdr;
+	struct dnet_sctp_chunkhdr chunkhdr;
 
 	uint32_t	schi_itag;	/* Initiate Tag */
 	uint32_t	schi_arwnd;	/* Advertised Receiver Window Credit */
@@ -105,7 +105,7 @@
  * INIT ACK chunk
  */
 struct sctp_chunkhdr_init_ack {
-	struct sctp_chunkhdr chunkhdr;
+	struct dnet_sctp_chunkhdr chunkhdr;
 
 	uint32_t	schia_itag;	/* Initiate Tag */
 	uint32_t	schia_arwnd;	/* Advertised Receiver Window Credit */
@@ -130,7 +130,7 @@
  * ABORT chunk
  */
 struct sctp_chunkhdr_abort {
-	struct sctp_chunkhdr chunkhdr;
+	struct dnet_sctp_chunkhdr chunkhdr;
 
 	/* empty */
 } __attribute__((__packed__));
@@ -145,7 +145,7 @@
  * SHUTDOWN ACK chunk
  */
 struct sctp_chunkhdr_shutdown_ack {
-	struct sctp_chunkhdr chunkhdr;
+	struct dnet_sctp_chunkhdr chunkhdr;
 
 	/* empty */
 } __attribute__((__packed__));
@@ -160,7 +160,7 @@
  * COOKIE ECHO chunk
  */
 struct sctp_chunkhdr_cookie_echo {
-	struct sctp_chunkhdr chunkhdr;
+	struct dnet_sctp_chunkhdr chunkhdr;
 
 	/* empty */
 } __attribute__((__packed__));
