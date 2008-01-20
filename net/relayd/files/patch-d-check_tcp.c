--- relayd/check_tcp.c.orig	2007-12-08 02:17:00.000000000 +0900
+++ relayd/check_tcp.c	2008-01-14 16:47:41.131892553 +0900
@@ -31,7 +31,7 @@
 #include <stdlib.h>
 #include <errno.h>
 #include <fnmatch.h>
-#include <sha1.h>
+#include <sha.h>
 
 #include <openssl/ssl.h>
 
@@ -285,7 +285,7 @@
 	if (b == NULL)
 		fatal("out of memory");
 	*b = '\0';
-	if (fnmatch(cte->table->conf.exbuf, cte->buf->buf, 0) == 0) {
+	if (fnmatch(cte->table->conf.exbuf, (char *)cte->buf->buf, 0) == 0) {
 		cte->host->up = HOST_UP;
 		return (0);
 	}
@@ -316,7 +316,7 @@
 		fatal("out of memory");
 	*b = '\0';
 
-	head = cte->buf->buf;
+	head = (char *)cte->buf->buf;
 	host = cte->host;
 	if (strncmp(head, "HTTP/1.1 ", strlen("HTTP/1.1 ")) &&
 	    strncmp(head, "HTTP/1.0 ", strlen("HTTP/1.0 "))) {
@@ -363,7 +363,7 @@
 		fatal("out of memory");
 	*b = '\0';
 
-	head = cte->buf->buf;
+	head = (char *)cte->buf->buf;
 	host = cte->host;
 	if ((head = strstr(head, "\r\n\r\n")) == NULL) {
 		log_debug("check_http_digest: %s failed "
@@ -373,7 +373,7 @@
 	}
 	head += strlen("\r\n\r\n");
 
-	digeststr(cte->table->conf.digest_type, head, strlen(head), digest);
+	digeststr(cte->table->conf.digest_type, (u_int8_t*)head, strlen(head), digest);
 
 	if (strcmp(cte->table->conf.digest, digest)) {
 		log_warnx("check_http_digest: %s failed "
