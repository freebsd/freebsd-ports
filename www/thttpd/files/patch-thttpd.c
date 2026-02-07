--- thttpd.c.orig	Wed Jun 29 19:50:59 2005
+++ thttpd.c	Sun Jun 17 21:30:11 2007
@@ -331,6 +331,7 @@
 re_open_logfile( void )
     {
     FILE* logfp;
+    int retchmod;
 
     if ( no_log || hs == (httpd_server*) 0 )
 	return;
@@ -340,7 +341,8 @@
 	{
 	syslog( LOG_NOTICE, "re-opening logfile" );
 	logfp = fopen( logfile, "a" );
-	if ( logfp == (FILE*) 0 )
+	retchmod = chmod( logfile, S_IRUSR|S_IWUSR|S_IRGRP );
+	if ( logfp == (FILE*) 0 || retchmod != 0 )
 	    {
 	    syslog( LOG_CRIT, "re-opening %.80s - %m", logfile );
 	    return;
@@ -360,6 +362,7 @@
     gid_t gid = 32767;
     char cwd[MAXPATHLEN+1];
     FILE* logfp;
+    int retchmod;
     int num_ready;
     int cnum;
     connecttab* c;
@@ -429,7 +432,8 @@
 	else
 	    {
 	    logfp = fopen( logfile, "a" );
-	    if ( logfp == (FILE*) 0 )
+	    retchmod = chmod( logfile, S_IRUSR|S_IWUSR|S_IRGRP );
+	    if ( logfp == (FILE*) 0 || retchmod != 0 )
 		{
 		syslog( LOG_CRIT, "%.80s - %m", logfile );
 		perror( logfile );
@@ -1714,12 +1718,45 @@
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
@@ -1730,6 +1767,7 @@
 	iv[1].iov_base = &(hc->file_address[c->next_byte_index]);
 	iv[1].iov_len = MIN( c->end_byte_index - c->next_byte_index, max_bytes );
 	sz = writev( hc->conn_fd, iv, 2 );
+#endif
 	}
 
     if ( sz < 0 && errno == EINTR )
@@ -1777,7 +1815,11 @@
 	**
 	** And ECONNRESET isn't interesting either.
 	*/
-	if ( errno != EPIPE && errno != EINVAL && errno != ECONNRESET )
+	if ( errno != EPIPE && errno != EINVAL && errno != ECONNRESET
+#ifdef USE_SENDFILE
+	&& errno != ENOTCONN
+#endif
+	)
 	    syslog( LOG_ERR, "write - %m sending %.80s", hc->encodedurl );
 	clear_connection( c, tvP );
 	return;
