--- main/http.c.orig	2013-12-17 23:42:58.982720307 +0100
+++ main/http.c	2013-12-17 23:43:16.054863909 +0100
@@ -1024,7 +1024,7 @@
 	struct http_uri_redirect *redirect;
 	struct ast_flags config_flags = { reload ? CONFIG_FLAG_FILEUNCHANGED : 0 };
 	uint32_t bindport = DEFAULT_PORT;
-	RAII_VAR(struct ast_sockaddr *, addrs, NULL, ast_free);
+	struct ast_sockaddr *addrs = NULL;
 	int num_addrs = 0;
 	int http_tls_was_enabled = 0;
 
