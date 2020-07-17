--- main/http.c.orig	2020-07-09 15:33:47 UTC
+++ main/http.c
@@ -2110,7 +2110,7 @@ static int __ast_http_load(int reload)
 	struct http_uri_redirect *redirect;
 	struct ast_flags config_flags = { reload ? CONFIG_FLAG_FILEUNCHANGED : 0 };
 	uint32_t bindport = DEFAULT_PORT;
-	RAII_VAR(struct ast_sockaddr *, addrs, NULL, ast_free);
+	struct ast_sockaddr *addrs = NULL;
 	int num_addrs = 0;
 	int http_tls_was_enabled = 0;
 
