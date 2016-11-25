--- main/udptl.c.orig	2016-11-23 15:26:01 UTC
+++ main/udptl.c
@@ -1016,6 +1016,9 @@ struct ast_udptl *ast_udptl_new_with_bin
 	int i;
 	long int flags;
 	RAII_VAR(struct udptl_config *, cfg, ao2_global_obj_ref(globals), ao2_cleanup);
+#if defined(__FreeBSD__)
+	int portretryipv4 = 1;
+#endif
 
 	if (!cfg || !cfg->general) {
 		ast_log(LOG_ERROR, "Could not access global udptl options!\n");
@@ -1039,8 +1042,18 @@ struct ast_udptl *ast_udptl_new_with_bin
 		udptl->tx[i].buf_len = -1;
 	}
 
-	if ((udptl->fd = socket(ast_sockaddr_is_ipv6(addr) ?
-					AF_INET6 : AF_INET, SOCK_DGRAM, 0)) < 0) {
+#if defined(__FreeBSD__)
+	udptl->fd = socket(AF_INET6, SOCK_DGRAM, 0);
+	if (udptl->fd < 0) {
+		ast_sockaddr_parse(addr, "0.0.0.0", 0);
+		udptl->fd = socket(AF_INET, SOCK_DGRAM, 0);
+		portretryipv4 = 0;
+	}
+#else
+	udptl->fd = socket(ast_sockaddr_is_ipv6(addr) ?
+			AF_INET6 : AF_INET, SOCK_DGRAM, 0);
+#endif
+	if (udptl->fd < 0) {
 		ast_free(udptl);
 		ast_log(LOG_WARNING, "Unable to allocate socket: %s\n", strerror(errno));
 		return NULL;
@@ -1079,8 +1092,30 @@ struct ast_udptl *ast_udptl_new_with_bin
 		if (x > cfg->general->end)
 			x = cfg->general->start;
 		if (x == startplace) {
+#if defined(__FreeBSD__)
+			/* Try again with IPv4 if not IPv6 port could be found */
+			if (portretryipv4 == 1) {
+				close(udptl->fd);
+				ast_sockaddr_parse(addr, "0.0.0.0", 0);
+				udptl->fd = socket(AF_INET, SOCK_DGRAM, 0);
+				if (udptl->fd >= 0) {
+					flags = fcntl(udptl->fd, F_GETFL);
+					fcntl(udptl->fd, F_SETFL, flags | O_NONBLOCK);
+					/* Reset the RTP port search parameters */
+					x = (cfg->general->start == cfg->general->end) ? cfg->general->start : (ast_random() % (cfg->general->end - cfg->general->start)) + cfg->general->start;
+					if (cfg->general->use_even_ports && (x & 1)) {
+						++x;
+					}
+					startplace = x;
+					portretryipv4 = 0;
+					continue;
+				}
+			}
+#endif
 			ast_log(LOG_WARNING, "No UDPTL ports remaining\n");
-			close(udptl->fd);
+			if (udptl->fd >= 0) {
+				close(udptl->fd);
+			}
 			ast_free(udptl);
 			return NULL;
 		}
