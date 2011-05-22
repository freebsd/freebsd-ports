--- relayd.orig/check_tcp.c	2011-05-22 01:06:39.463154237 +0200
+++ relayd/check_tcp.c	2011-05-22 01:06:54.673025092 +0200
@@ -31,7 +31,7 @@
 #include <stdlib.h>
 #include <errno.h>
 #include <fnmatch.h>
-#include <sha1.h>
+#include <sha.h>
 
 #include <openssl/ssl.h>
 
@@ -287,7 +287,11 @@
 	if (b == NULL)
 		fatal("out of memory");
 	*b = '\0';
+#ifndef __FreeBSD__
 	if (fnmatch(cte->table->conf.exbuf, cte->buf->buf, 0) == 0) {
+#else
+	if (fnmatch(cte->table->conf.exbuf, (char *)cte->buf->buf, 0) == 0) {
+#endif
 		cte->host->he = HCE_SEND_EXPECT_OK;
 		cte->host->up = HOST_UP;
 		return (0);
@@ -320,7 +324,11 @@
 		fatal("out of memory");
 	*b = '\0';
 
+#ifndef __FreeBSD__
 	head = cte->buf->buf;
+#else
+	head = (char *)cte->buf->buf;
+#endif
 	host = cte->host;
 	host->he = HCE_HTTP_CODE_ERROR;
 
@@ -372,7 +380,11 @@
 		fatal("out of memory");
 	*b = '\0';
 
+#ifndef __FreeBSD__
 	head = cte->buf->buf;
+#else
+	head = (char *)cte->buf->buf;
+#endif
 	host = cte->host;
 	host->he = HCE_HTTP_DIGEST_ERROR;
 
@@ -384,7 +396,11 @@
 	}
 	head += strlen("\r\n\r\n");
 
+#ifndef __FreeBSD__
 	digeststr(cte->table->conf.digest_type, head, strlen(head), digest);
+#else
+	digeststr(cte->table->conf.digest_type, (u_int8_t*)head, strlen(head), digest);
+#endif
 
 	if (strcmp(cte->table->conf.digest, digest)) {
 		log_warnx("%s: %s failed (wrong digest)",
