--- main/http.c.orig	2015-07-24 22:06:05 UTC
+++ main/http.c
@@ -1072,7 +1072,7 @@ static int __ast_http_load(int reload)
 	struct http_uri_redirect *redirect;
 	struct ast_flags config_flags = { reload ? CONFIG_FLAG_FILEUNCHANGED : 0 };
 	uint32_t bindport = DEFAULT_PORT;
-	RAII_VAR(struct ast_sockaddr *, addrs, NULL, ast_free);
+	struct ast_sockaddr *addrs = NULL;
 	int num_addrs = 0;
 	int http_tls_was_enabled = 0;
 
