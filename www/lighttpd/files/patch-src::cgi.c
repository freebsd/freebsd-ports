--- ./src/cgi.c~	2005-02-08 00:08:01.000000000 +0200
+++ ./src/cgi.c	2005-02-08 00:13:02.000000000 +0200
@@ -686,16 +686,18 @@
 	
 	int to_cgi_fds[2];
 	int from_cgi_fds[2];
-	struct stat st;
-	
+
 #ifndef __WIN32	
+	struct stat st;
 	
-	/* stat the exec file */
-	if (-1 == (stat(cgi_handler->ptr, &st))) {
-		log_error_write(srv, __FILE__, __LINE__, "sbss", 
-				"stat for cgi-handler", cgi_handler,
-				"failed:", strerror(errno));
-		return -1;
+	if (cgi_handler->used > 1) {
+		/* stat the exec file */
+		if (-1 == (stat(cgi_handler->ptr, &st))) {
+			log_error_write(srv, __FILE__, __LINE__, "sbss", 
+					"stat for cgi-handler", cgi_handler,
+					"failed:", strerror(errno));
+			return -1;
+		}
 	}
 	
 	if (pipe(to_cgi_fds)) {
