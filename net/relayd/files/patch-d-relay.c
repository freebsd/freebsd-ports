--- relayd/relay.c.orig	2007-12-09 05:36:36.000000000 +0900
+++ relayd/relay.c	2008-01-14 10:26:05.345356528 +0900
@@ -16,7 +16,7 @@
  * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
  */
 
-#include <sys/types.h>
+#include <sys/param.h>
 #include <sys/queue.h>
 #include <sys/time.h>
 #include <sys/stat.h>
@@ -675,6 +675,7 @@
 		    &val, sizeof(val)) == -1)
 			goto bad;
 	}
+#if 0
 	if (proto->tcpflags & (TCPFLAG_SACK|TCPFLAG_NSACK)) {
 		if (proto->tcpflags & TCPFLAG_NSACK)
 			val = 0;
@@ -684,6 +685,7 @@
 		    &val, sizeof(val)) == -1)
 			goto bad;
 	}
+#endif
 
 	return (s);
 
@@ -1000,7 +1002,7 @@
 		}
 	}
 	if (strstr(val, "$TIMEOUT") != NULL) {
-		snprintf(ibuf, sizeof(ibuf), "%lu", rlay->conf.timeout.tv_sec);
+		snprintf(ibuf, sizeof(ibuf), "%lu", (unsigned long)rlay->conf.timeout.tv_sec);
 		if (expand_string(buf, len, "$TIMEOUT", ibuf) != 0)
 			return (NULL);
 	}
@@ -1565,7 +1567,7 @@
 	switch (type) {
 	case DIGEST_SHA1:
 	case DIGEST_MD5:
-		if ((md = digeststr(type, val, strlen(val), NULL)) == NULL) {
+		if ((md = digeststr(type, (u_int8_t*)val, strlen(val), NULL)) == NULL) {
 			relay_close_http(con, 500,
 			    "failed to allocate digest", 0);
 			goto fail;
@@ -2469,7 +2471,7 @@
 		goto err;
 
 	/* Set session context to the local relay name */
-	if (!SSL_CTX_set_session_id_context(ctx, rlay->conf.name,
+	if (!SSL_CTX_set_session_id_context(ctx, (unsigned char*)rlay->conf.name,
 	    strlen(rlay->conf.name)))
 		goto err;
 
@@ -2849,7 +2851,7 @@
 	if (fstat(fd, &st) != 0)
 		goto fail;
 	size = st.st_size;
-	if ((buf = (char *)calloc(1, size + 1)) == NULL)
+	if ((buf = (u_int8_t *)calloc(1, size + 1)) == NULL)
 		goto fail;
 	if (read(fd, buf, size) != size)
 		goto fail;
@@ -2857,7 +2859,7 @@
 	close(fd);
 
 	*len = size + 1;
-	return (buf);
+	return (char *)(buf);
 
  fail:
 	if (buf != NULL)
