--- src/input/input_http.c.orig	Tue Jun  6 21:16:04 2006
+++ src/input/input_http.c	Tue Jun  6 21:22:34 2006
@@ -895,6 +895,12 @@
 	len = 0;
     } else
       len ++;
+    if ( len >= BUFSIZE ) {
+       _x_message(this->stream, XINE_MSG_PERMISSION_ERROR, this->mrl, NULL);
+       xine_log (this->stream->xine, XINE_LOG_MSG,
+         _("input_http: buffer exhausted after %d bytes."), BUFSIZE);
+       return 0;
+    }
   }
 
   lprintf ("end of headers\n");
