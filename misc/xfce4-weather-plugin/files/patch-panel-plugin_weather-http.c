--- panel-plugin/weather-http.c.orig	Wed Jan 17 19:02:39 2007
+++ panel-plugin/weather-http.c	Mon May 14 17:04:58 2007
@@ -83,14 +83,61 @@ http_connect (gchar *hostname,
   fcntl (fd, F_SETFL, O_NONBLOCK);
 
   if ((connect (fd, (struct sockaddr *) &dest_host, sizeof (struct sockaddr))
-       == -1) && errno != EINPROGRESS)
+       == -1))
     {
-      perror ("http_connect()");
-      return -1;
+	gboolean failed = TRUE;
+        
+	if(errno == EWOULDBLOCK || errno == EINPROGRESS || errno == EALREADY)
+	 {
+	   gint iters_left;
+	   for(iters_left = 5; iters_left >= 0; iters_left--) {
+		fd_set wfd;
+		struct timeval tv = { 2, 0 };
+		int sock_err = 0;
+		socklen_t sock_err_len = sizeof(int);
+
+		FD_ZERO(&wfd);
+		FD_SET(fd, &wfd);
+
+		DBG("checking for a connection...");
+
+		/* wait until the connect attempt finishes */
+		if(select(FD_SETSIZE, NULL, &wfd, NULL, &tv) < 0)
+		   break;
+                
+		/* check to see if it finished, and, if so, if there was an
+		 * error, or if it completed successfully */
+		if(FD_ISSET(fd, &wfd)) {
+		    if(!getsockopt(fd, SOL_SOCKET, SO_ERROR,
+				&sock_err, &sock_err_len)
+			    && !sock_err)
+		    {
+			DBG("    connection succeeded");
+			failed = FALSE;
+                    } else {
+			g_warning("    connection failed");
+			DBG("    connection failed: sock_err is %d", sock_err);
+		    }
+		    break;
+		}
+	    }
+	 }
+        
+	if(failed)
+	 {
+	    DBG("failed to connect");
+	    close(fd);
+	    fd = -1;
+	    perror ("http_connect()");
+	    return -1;
+	 }
     }
-  else
-    return fd;
+    
+    if(fcntl(fd, F_SETFL, fcntl(fd, F_GETFL) & ~(O_NONBLOCK))) {
+	g_warning("Unable to return socket to blocking mode.");
+    }
 
+    return fd;
 }
 
 
