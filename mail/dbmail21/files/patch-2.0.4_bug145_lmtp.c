Index: lmtp.c
===================================================================
--- lmtp.c	(revision 1559)
+++ lmtp.c	(revision 1700)
@@ -77,8 +77,9 @@
  *     - -1 on error
  *     -  1 on success
  */
-static int read_whole_message_network(FILE *instream, char **whole_message,
-				      u64_t *whole_message_size);
+static int read_whole_message_network(FILE *instream,
+		char **whole_message, u64_t *whole_message_size,
+		const char *prepend_format, ...) PRINTF_ARGS(4, 5);
 
 /**
  * \function lmtp_error
@@ -624,7 +625,9 @@
 					if (read_whole_message_network(
 						    (FILE *) instream,
 						    &whole_message,
-						    &whole_message_size) < 0) {
+						    &whole_message_size,
+						    "Return-Path: %s\r\n",
+						    (char *)(list_getstart(&from)->data)) < 0) {
 						trace(TRACE_ERROR,
 						      "%s,%s: read_whole_message_network() failed",
 						      __FILE__, __func__);
@@ -755,8 +758,9 @@
 	return 1;
 }
 
-int read_whole_message_network(FILE *instream, char **whole_message,
-				      u64_t *whole_message_size)
+int read_whole_message_network(FILE *instream,
+		char **whole_message, u64_t *whole_message_size,
+		const char *prepend_format, ...)
 {
 	char *tmpmessage = NULL;
 	char tmpline[MESSAGE_MAX_LINE_SIZE + 1];
@@ -765,9 +769,17 @@
 	size_t total_size = 0;
 	size_t current_pos = 0;
 	int error = 0;
+	va_list argp;
 
 	memset(tmpline, '\0', MESSAGE_MAX_LINE_SIZE + 1);
-	while (fgets(tmpline, MESSAGE_MAX_LINE_SIZE, instream) != NULL) {
+
+	/* This adds the Return-Path header and any other
+	 * important headers we might need; see RFC 2076. */
+	va_start(argp, prepend_format);
+	line_size = vsnprintf(tmpline, MESSAGE_MAX_LINE_SIZE, prepend_format, argp);
+	va_end(argp);
+
+	do {
 		line_size = strlen(tmpline);
 		
 		/* It sometimes happens that we read a line of size 0,
@@ -798,6 +810,7 @@
 				
 		memset(tmpline, '\0', MESSAGE_MAX_LINE_SIZE + 1);
 	}
+	while (fgets(tmpline, MESSAGE_MAX_LINE_SIZE, instream) != NULL);
 		
 	if (ferror(instream)) {
 		trace(TRACE_ERROR, "%s,%s: error reading instream",
