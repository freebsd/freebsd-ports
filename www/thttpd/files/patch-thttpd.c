--- thttpd.c.orig	Tue May 13 17:14:33 2003
+++ thttpd.c	Wed Oct 29 05:50:14 2003
@@ -1593,12 +1593,45 @@
     if ( hc->responselen == 0 )
 	{
 	/* No, just write the file. */
+#ifdef USE_SENDFILE
+	off_t sbytes;
+	
+	sz = sendfile(
+	     hc->file_fd, hc->conn_fd, c->bytes_sent,
+	     MIN( c->bytes_to_send - c->bytes_sent, c->max_limit ),
+	     NULL, &sbytes, 0 );
+	if (sz == -1 && errno == EAGAIN)
+	    sz = sbytes > 0 ? sbytes : -1;
+	else if (sz == 0)
+	    sz = sbytes;
+#else		      
 	sz = write(
 	    hc->conn_fd, &(hc->file_address[c->bytes_sent]),
 	    MIN( c->bytes_to_send - c->bytes_sent, c->max_limit ) );
+#endif
 	}
     else
 	{
+#ifdef USE_SENDFILE
+	struct sf_hdtr sf;
+	struct iovec iv;
+	off_t sbytes;
+
+	iv.iov_base = hc->response;
+	iv.iov_len = hc->responselen;
+	sf.headers = &iv;
+	sf.hdr_cnt = 1;
+	sf.trailers = NULL;
+	sf.trl_cnt = 0;
+	sz = sendfile(
+	     hc->file_fd, hc->conn_fd, c->bytes_sent,
+	     MIN( c->bytes_to_send - c->bytes_sent, c->max_limit ),
+	     &sf, &sbytes, 0 );
+	if (sz == -1 && errno == EAGAIN)
+	    sz = sbytes > 0 ? sbytes : -1;
+	else if (sz == 0)
+	    sz = sbytes;
+#else		      
 	/* Yes.  We'll combine headers and file into a single writev(),
 	** hoping that this generates a single packet.
 	*/
@@ -1609,6 +1642,7 @@
 	iv[1].iov_base = &(hc->file_address[c->bytes_sent]);
 	iv[1].iov_len = MIN( c->bytes_to_send - c->bytes_sent, c->max_limit );
 	sz = writev( hc->conn_fd, iv, 2 );
+#endif
 	}
 
     if ( sz == 0 ||
