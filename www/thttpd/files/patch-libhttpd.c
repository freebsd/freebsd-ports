--- libhttpd.c.orig	Mon May 27 01:22:26 2002
+++ libhttpd.c	Sun Oct 20 23:49:58 2002
@@ -3816,6 +3816,9 @@
 	    httpd_send_err( hc, 500, err500title, "", err500form, hc->encodedurl );
 	    return -1;
 	    }
+#ifdef USE_SENDFILE
+	hc->file_fd = *((int *) hc->file_address);
+#endif
 	send_mime(
 	    hc, 200, ok200title, hc->encodings, "", hc->type, hc->sb.st_size,
 	    hc->sb.st_mtime );
