--- mini_httpd.c~	Wed Dec  3 19:27:22 2003
+++ mini_httpd.c	Thu May  6 23:36:20 2004
@@ -816,7 +816,7 @@
 	    }
 	if ( conn_fd < 0 )
 	    {
-	    if ( errno == EINTR || errno == EAGAIN )
+	    if ( errno == EINTR || errno == EAGAIN || errno == ECONNABORTED )
 		continue;	/* try again */
 #ifdef EPROTO
 	    if ( errno == EPROTO )
