--- src/proxy.c.orig	Fri Jan  9 23:04:56 2004
+++ src/proxy.c	Thu Mar 25 12:37:20 2004
@@ -388,7 +388,11 @@
 	int rc, err;
 	GSList *hosts = NULL;
 	struct sockaddr *addr = NULL;
+#if HAVE_GETADDRINFO
+	size_t addrlen;
+#else
 	socklen_t addrlen;
+#endif
 
 	gaim_debug(GAIM_DEBUG_INFO, "dns", "Host '%s' resolved\n", req->host);
 	gaim_input_remove(req->inpa);
@@ -974,7 +978,7 @@
 
 	gaim_input_remove(phb->inpa);
 
-	while ((nlc != 2) && (read(source, &inputline[pos++], 1) == 1)) {
+	while ((pos < sizeof(inputline)-1) && (nlc != 2) && (read(source, &inputline[pos++], 1) == 1)) {
 		if (inputline[pos - 1] == '\n')
 			nlc++;
 		else if (inputline[pos - 1] != '\r')
