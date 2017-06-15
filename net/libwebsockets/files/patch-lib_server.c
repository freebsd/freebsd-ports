--- lib/server.c.orig	2016-11-23 13:04:24 UTC
+++ lib/server.c
@@ -110,7 +110,7 @@ lws_context_init_server(struct lws_conte
 	if (LWS_IPV6_ENABLED(vhost)) {
 		if (vhost->options & LWS_SERVER_OPTION_IPV6_V6ONLY_MODIFY) {
 			int value = (vhost->options & LWS_SERVER_OPTION_IPV6_V6ONLY_VALUE) ? 1 : 0;
-			if (setsockopt(sockfd, SOL_IPV6, IPV6_V6ONLY,
+			if (setsockopt(sockfd, IPPROTO_IPV6, IPV6_V6ONLY,
 					(const void*)&value, sizeof(value)) < 0) {
 				compatible_close(sockfd);
 				return 1;
