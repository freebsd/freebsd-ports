
$FreeBSD$

--- fifo_server.c.orig	Sat Nov  1 20:56:58 2003
+++ fifo_server.c	Tue Jun 29 22:33:53 2004
@@ -642,7 +657,7 @@
 static int print_version_cmd( FILE *stream, char *response_file )
 {
 	if (response_file) {
-		fifo_reply(response_file, "200 ok\n" SERVER_HDR CRLF );
+		fifo_reply(response_file, "200 ok\n" SERVER_HDR "%s" CRLF, server_name ? server_name : UA_NAME );
 	} else {
 		LOG(L_ERR, "ERROR: no file for %s\n", "print_version_cmd" );
 	}
