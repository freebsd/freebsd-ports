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
@@ -3889,6 +3889,9 @@
 	    httpd_send_err( hc, 500, err500title, "", err500form, hc->encodedurl );
 	    return -1;
 	    }
+#ifdef USE_SENDFILE
+	hc->file_fd = *((int *) hc->file_address);
+#endif
 	send_mime(
 	    hc, 200, ok200title, hc->encodings, "", hc->type, hc->sb.st_size,
 	    hc->sb.st_mtime );
