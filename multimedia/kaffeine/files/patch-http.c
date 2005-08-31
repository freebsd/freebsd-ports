--- kaffeine/player-parts/http.c.orig	Wed Aug 31 16:16:57 2005
+++ kaffeine/player-parts/http.c	Wed Aug 31 16:23:33 2005
@@ -492,10 +492,19 @@
 	}
       } else {
 	if (this->contentlength == 0) {
+#ifdef HAVE_STDINT_H
 	  intmax_t contentlength;
 
 	  if ( strlen(this->buf)<(BUFSIZE-20) && sscanf(this->buf, "Content-Length: %" PRIdMAX, &contentlength) == 1) {
+
 	    printf ("http: content length = %" PRIdMAX " bytes\n", contentlength);
+#else
+	  int64_t contentlength;
+
+	  if ( strlen(this->buf)<(BUFSIZE-20) && sscanf(this->buf, "Content-Length: %Ld", &contentlength) == 1) {
+	    printf ("http: content length = %Ld bytes\n", contentlength);
+#endif
+
 	    this->contentlength = (off_t)contentlength;
 	  }
         }
