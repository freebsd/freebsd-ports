--- src/lib/ostream-file.c.orig	2019-07-12 19:18:41 UTC
+++ src/lib/ostream-file.c
@@ -334,7 +334,7 @@ static void o_stream_tcp_flush_via_nodelay(struct file
 {
 	if (net_set_tcp_nodelay(fstream->fd, TRUE) < 0) {
 		if (errno != ENOTSUP && errno != ENOTSOCK &&
-		    errno != ENOPROTOOPT) {
+		    errno != ENOPROTOOPT && errno != EINVAL) {
 			i_error("file_ostream.net_set_tcp_nodelay(%s, TRUE) failed: %m",
 				o_stream_get_name(&fstream->ostream.ostream));
 		}
