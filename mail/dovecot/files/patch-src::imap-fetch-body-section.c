--- src/imap/imap-fetch-body-section.c.orig	Sun Jan 26 10:38:34 2003
+++ src/imap/imap-fetch-body-section.c	Sun Apr 20 02:33:03 2003
@@ -78,6 +78,7 @@
 	struct istream *stream;
 	const char *str;
 	int skip_cr;
+	uoff_t size;
 	off_t ret;
 
 	stream = mail->get_stream(mail, &hdr_size, &body_size);
@@ -87,8 +88,13 @@
 	if (fetch_header)
 		message_size_add(&body_size, &hdr_size);
 
-	str = t_strdup_printf("%s {%"PRIuUOFF_T"}\r\n",
-			      ctx->prefix, body_size.virtual_size);
+	if (body->skip >= body_size.virtual_size)
+		size = 0;
+	else {
+		size = body_size.virtual_size - body->skip;
+		if (size > body->max_size) size = body->max_size;
+	}
+	str = t_strdup_printf("%s {%"PRIuUOFF_T"}\r\n", ctx->prefix, size);
 	if (o_stream_send_str(ctx->output, str) < 0)
 		return FALSE;
 
@@ -96,6 +102,7 @@
 			       &partial, stream,
 			       fetch_header ? 0 : hdr_size.physical_size,
 			       body->skip);
+
 	ret = message_send(ctx->output, stream, &body_size,
 			   skip_cr, body->max_size);
 	if (ret > 0) {
