
$FreeBSD$

--- msg_translator.c	2004/06/29 19:19:33	1.1
+++ msg_translator.c	2004/06/29 19:55:57
@@ -1657,7 +1657,7 @@
 	}
 	/* server header */
 	if (server_signature)
-		len += SERVER_HDR_LEN + CRLF_LEN;
+		len += SERVER_HDR_LEN + CRLF_LEN + (server_name ? strlen(server_name) : UA_NAME_LEN);
 	/* warning hdr */
 	if (sip_warning) {
 		warning_buf = warning_builder(msg,&warning_len);
@@ -1788,6 +1788,13 @@
 	if (server_signature) {
 		memcpy( p, SERVER_HDR , SERVER_HDR_LEN );
 		p+=SERVER_HDR_LEN;
+		if (server_name) {
+			memcpy( p, server_name, strlen(server_name) );
+			p+=strlen(server_name);
+		} else {
+			memcpy( p, UA_NAME, UA_NAME_LEN );
+			p+=UA_NAME_LEN;
+		}
 		memcpy( p, CRLF, CRLF_LEN );
 		p+=CRLF_LEN;
 	}
