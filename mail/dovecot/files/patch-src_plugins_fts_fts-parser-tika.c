--- src/plugins/fts/fts-parser-tika.c.orig	2019-01-02 22:11:26 UTC
+++ src/plugins/fts/fts-parser-tika.c
@@ -77,7 +77,7 @@ tika_get_http_client_url(struct mail_user *user, struc
 		http_set.request_timeout_msecs = 60*1000;
 		http_set.ssl = &ssl_set;
 		http_set.debug = user->mail_debug;
-		tika_http_client = http_client_init(&http_set);
+		tika_http_client = http_client_init_private(&http_set);
 	}
 	*http_url_r = tuser->http_url;
 	return 0;
