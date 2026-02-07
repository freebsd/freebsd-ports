--- libhttpd.c.orig	Mon May 27 01:22:26 2002
+++ libhttpd.c	Sun Oct 20 23:49:58 2002
@@ -1483,7 +1483,7 @@
 	    httpd_realloc_str( &checked, &maxchecked, checkedlen );
 	    (void) strcpy( checked, path );
 	    /* Trim trailing slashes. */
-	    while ( checked[checkedlen - 1] == '/' )
+	    while ( checkedlen && checked[checkedlen - 1] == '/' )
 		{
 		checked[checkedlen - 1] = '\0';
 		--checkedlen;
@@ -1502,7 +1502,7 @@
     restlen = strlen( path );
     httpd_realloc_str( &rest, &maxrest, restlen );
     (void) strcpy( rest, path );
-    if ( rest[restlen - 1] == '/' )
+    if ( restlen && rest[restlen - 1] == '/' )
 	rest[--restlen] = '\0';         /* trim trailing slash */
     if ( ! tildemapped )
 	/* Remove any leading slashes. */
@@ -2348,8 +2348,11 @@
 	{
 	int i;
 	i = strlen( hc->origfilename ) - strlen( hc->pathinfo );
-	if ( i > 0 && strcmp( &hc->origfilename[i], hc->pathinfo ) == 0 )
-	    hc->origfilename[i - 1] = '\0';
+	if ( strcmp( &hc->origfilename[i], hc->pathinfo ) == 0 )
+	    {
+	    if ( i == 0 ) hc->origfilename[0] = '\0';
+	    else hc->origfilename[i - 1] = '\0';
+	    }
 	}
 
     /* If the expanded filename is an absolute path, check that it's still
@@ -2571,7 +2574,7 @@
     size_t ext_len, encodings_len;
     int i, top, bot, mid;
     int r;
-    char* default_type = "text/plain; charset=%s";
+    char* default_type = "application/octet-stream";
 
     /* Peel off encoding extensions until there aren't any more. */
     n_me_indexes = 0;
@@ -3312,7 +3315,7 @@
 	cp += strcspn( cp, " \t" );
 	status = atoi( cp );
 	}
-    if ( ( cp = strstr( headers, "Location:" ) ) != (char*) 0 &&
+    else if ( ( cp = strstr( headers, "Location:" ) ) != (char*) 0 &&
 	 cp < br &&
 	 ( cp == headers || *(cp-1) == '\012' ) )
 	status = 302;
@@ -3889,6 +3892,9 @@
 	    httpd_send_err( hc, 500, err500title, "", err500form, hc->encodedurl );
 	    return -1;
 	    }
+#ifdef USE_SENDFILE
+	hc->file_fd = *((int *) hc->file_address);
+#endif
 	send_mime(
 	    hc, 200, ok200title, hc->encodings, "", hc->type, hc->sb.st_size,
 	    hc->sb.st_mtime );
