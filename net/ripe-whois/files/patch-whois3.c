--- whois3.c.orig	Thu Aug  5 16:41:00 2004
+++ whois3.c	Thu Aug  5 16:59:16 2004
@@ -130,7 +130,12 @@
 	/* create the socket */
 	fd = socket(dest.ss_family, SOCK_STREAM, 0);
 	if (fd < 0)
-	    fatal("cannot create the socket: %s", strerror(errno));
+	{
+	    if (errno == EPROTONOSUPPORT)
+    		continue;
+	    else
+	    	fatal("cannot create the socket: %s", strerror(errno));
+	}
 
 	/* perform the connection */
 	err = connect(fd, (struct sockaddr *) &dest, destlen);
