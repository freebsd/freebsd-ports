--- src/mod_cgi.c	(revision 34)
+++ src/mod_cgi.c	(revision 35)
@@ -690,12 +690,14 @@
 	
 #ifndef __WIN32	
 	
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
