
$FreeBSD$

--- parser/msg_parser.h.orig
+++ parser/msg_parser.h
@@ -193,6 +193,7 @@
 	struct hdr_field* accept_disposition;
 	struct hdr_field* diversion;
 	struct hdr_field* rpid;
+	struct hdr_field* server;
 
 	char* eoh;        /* pointer to the end of header (if found) or null */
 	char* unparsed;   /* here we stopped parsing*/
@@ -287,7 +288,11 @@
 	
 	/* topmost Via is part of transaction key as well ! */
 	src[5]= msg->via1->host;
+#if 0
 	src[6]= msg->via1->port_str;
+#else
+	src[6].len = 0;
+#endif
 	if (msg->via1->branch) {
 		src[7]= msg->via1->branch->value;
 		MDStringArray ( cv, src, 8 );
