--- thttpd.c.orig	Thu Dec 25 19:06:52 2003
+++ thttpd.c	Fri May 28 12:25:54 2004
@@ -1723,12 +1723,45 @@
     if ( hc->responselen == 0 )
 	{
 	/* No, just write the file. */
+#ifdef USE_SENDFILE
+	off_t sbytes;
+	
+	sz = sendfile(
+	     hc->file_fd, hc->conn_fd, c->next_byte_index,
+	     MIN( c->end_byte_index - c->next_byte_index, max_bytes ),
+	     NULL, &sbytes, 0 );
+	if (sz == -1 && errno == EAGAIN)
+	    sz = sbytes > 0 ? sbytes : -1;
+	else if (sz == 0)
+	    sz = sbytes;
+#else		      
 	sz = write(
 	    hc->conn_fd, &(hc->file_address[c->next_byte_index]),
 	    MIN( c->end_byte_index - c->next_byte_index, max_bytes ) );
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
+	     hc->file_fd, hc->conn_fd, c->next_byte_index,
+	     MIN( c->end_byte_index - c->next_byte_index, max_bytes ),
+	     &sf, &sbytes, 0 );
+	if (sz == -1 && errno == EAGAIN)
+	    sz = sbytes > 0 ? sbytes : -1;
+	else if (sz == 0)
+	    sz = sbytes;
+#else		      
 	/* Yes.  We'll combine headers and file into a single writev(),
 	** hoping that this generates a single packet.
 	*/
@@ -1739,6 +1772,7 @@
 	iv[1].iov_base = &(hc->file_address[c->next_byte_index]);
 	iv[1].iov_len = MIN( c->end_byte_index - c->next_byte_index, max_bytes );
 	sz = writev( hc->conn_fd, iv, 2 );
+#endif
 	}
 
     if ( sz < 0 && errno == EINTR )
