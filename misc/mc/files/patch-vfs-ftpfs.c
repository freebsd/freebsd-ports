--- vfs/ftpfs.c.orig	Thu Dec 26 08:21:43 2002
+++ vfs/ftpfs.c	Tue Jun 15 03:15:09 2004
@@ -266,8 +266,7 @@
 	switch (sscanf(answer, "%d", &code)){
 	    case 0:
 	        if (string_buf) {
-		    strncpy (string_buf, answer, string_len - 1);
-		    *(string_buf + string_len - 1) = 0;
+		    g_strlcpy (string_buf, answer, string_len);
 		}
 	        code = 500;
 	        return 5;
@@ -286,8 +285,7 @@
 		    }
 		}
 	        if (string_buf){
-		    strncpy (string_buf, answer, string_len - 1);
-		    *(string_buf + string_len - 1) = 0;
+		    g_strlcpy (string_buf, answer, string_len);
 		}
 		return code / 100;
 	}
@@ -321,28 +319,28 @@
     va_list ap;
     char *str, *fmt_str;
     int status;
-    int sock = SUP.sock;
+    int cmdlen;
     
     va_start (ap, fmt);
     fmt_str = g_strdup_vprintf (fmt, ap);
     va_end (ap);
 
-    status = strlen (fmt_str);
-    str = g_realloc (fmt_str, status + 3);
-    strcpy (str + status, "\r\n");
+    cmdlen = strlen (fmt_str);
+    str = g_realloc (fmt_str, cmdlen + 3);
+    strcpy (str + cmdlen, "\r\n");
 
     if (logfile){
         if (strncmp (str, "PASS ", 5) == 0){
             fputs ("PASS <Password not logged>\r\n", logfile);
         } else
-	    fwrite (str, status + 2, 1, logfile);
+	    fwrite (str, cmdlen + 2, 1, logfile);
 
 	fflush (logfile);
     }
 
     got_sigpipe = 0;
     enable_interrupt_key ();
-    status = write (SUP.sock, str, status + 2);
+    status = write (SUP.sock, str, cmdlen + 2);
     
     if (status < 0){
 	code = 421;
@@ -353,7 +351,7 @@
 		level = 1;
 		status = reconnect (me, super);
 		level = 0;
-		if (status && write (SUP.sock, str, status + 2) > 0)
+		if (status && write (SUP.sock, str, cmdlen + 2) > 0)
 		    goto ok;
 	    }
 	    got_sigpipe = 1;
@@ -367,7 +365,7 @@
     disable_interrupt_key ();
     
     if (wait_reply)
-	return get_reply (me, sock, (wait_reply & WANT_STRING) ? reply_str : NULL, sizeof (reply_str)-1);
+	return get_reply (me, SUP.sock, (wait_reply & WANT_STRING) ? reply_str : NULL, sizeof (reply_str)-1);
     return COMPLETE;
 }
 
@@ -903,23 +901,29 @@
     int data, len = sizeof(data_addr);
     struct protoent *pe;
 
-    getsockname(SUP.sock, (struct sockaddr *) &data_addr, &len);
-    data_addr.sin_port = 0;
-    
     pe = getprotobyname("tcp");
     if (pe == NULL)
 	    ERRNOR (EIO, -1);
+again:
+    if (getsockname(SUP.sock, (struct sockaddr *) &data_addr, &len) == -1)
+	ERRNOR (EIO, -1);
+    data_addr.sin_port = 0;
+    
     data = socket (AF_INET, SOCK_STREAM, pe->p_proto);
     if (data < 0)
 	    ERRNOR (EIO, -1);
 
     if (SUP.use_passive_connection){
-	if ((SUP.use_passive_connection = setup_passive (me, super, data, &data_addr)))
+	if (setup_passive (me, super, data, &data_addr))
 	    return data;
 
 	SUP.use_source_route = 0;
 	SUP.use_passive_connection = 0;
 	print_vfs_message (_("ftpfs: could not setup passive mode"));
+
+	/* data or data_addr may be damaged by setup_passive */
+	close (data);
+	goto again;
     }
 
     /* If passive setup fails, fallback to active connections */
@@ -971,11 +975,12 @@
 	data = s;
     else {
 	data = accept (s, (struct sockaddr *)&from, &fromlen);
-	close(s);
 	if (data < 0) {
 	    my_errno = errno;
+	    close(s);
 	    return -1;
 	}
+	close(s);
     } 
     disable_interrupt_key();
     return data;
@@ -1019,6 +1024,7 @@
 		gettimeofday (&tim, NULL);
 		if (tim.tv_sec > start_tim.tv_sec + ABORT_TIMEOUT) {
 		    /* server keeps sending, drop the connection and reconnect */
+		    close (dsock);
 		    reconnect (me, super);
 		    return;
 		}
