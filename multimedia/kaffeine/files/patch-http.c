--- kaffeine/player-parts/http.c.orig	Wed Dec  8 15:07:06 2004
+++ kaffeine/player-parts/http.c	Fri Dec 31 14:57:16 2004
@@ -48,6 +48,7 @@
 #include <stdio.h>
 #include <stdlib.h>
 #include <sys/types.h>
+#include <netinet/in.h>
 #include <sys/socket.h>
 #include <netinet/in.h>
 #include <netdb.h>
@@ -56,6 +57,11 @@
 #include <string.h>
 #include <ctype.h>
 #include <errno.h>
+#ifdef HAVE_STDINT_H
+#include <stdint.h>
+#else
+#include <inttypes.h>
+#endif
 
 #include "http.h"
 
@@ -514,7 +520,11 @@
 	}
       } else {
 	if (this->contentlength == 0) {
+#ifdef HAVE_STDINT_H
 	  intmax_t contentlength;
+#else
+	  int64_t contentlength;
+#endif
 	  
 	  if ( strlen(this->buf)<(BUFSIZE-20) && sscanf(this->buf, "Content-Length: %Ld", &contentlength) == 1) {
 	    printf ("http: content length = %Ld bytes\n", contentlength);
