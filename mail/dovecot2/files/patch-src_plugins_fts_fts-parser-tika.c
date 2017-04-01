From 3751b61dfbc6c141731a740d982fc59918db2482 Mon Sep 17 00:00:00 2001
From: =?UTF-8?q?Martti=20Rannanj=C3=A4rvi?= <martti.rannanjarvi@dovecot.fi>
Date: Wed, 1 Mar 2017 12:29:17 +0200
Subject: [PATCH] fts: Don't add NULL content disposition or type to HTTP
 header

---
 src/plugins/fts/fts-parser-tika.c | 9 ++++++---
 1 file changed, 6 insertions(+), 3 deletions(-)

diff --git a/src/plugins/fts/fts-parser-tika.c b/src/plugins/fts/fts-parser-tika.c
index 8457f28..385f1d0 100644
--- src/plugins/fts/fts-parser-tika.c
+++ src/plugins/fts/fts-parser-tika.c
@@ -158,9 +158,12 @@ fts_parser_tika_try_init(struct mail_user *user, const char *content_type,
 			fts_tika_parser_response, parser);
 	http_client_request_set_port(http_req, http_url->port);
 	http_client_request_set_ssl(http_req, http_url->have_ssl);
-	http_client_request_add_header(http_req, "Content-Type", content_type);
-	http_client_request_add_header(http_req, "Content-Disposition",
-				       content_disposition);
+	if (content_type != NULL)
+		http_client_request_add_header(http_req, "Content-Type",
+					       content_type);
+	if (content_disposition != NULL)
+		http_client_request_add_header(http_req, "Content-Disposition",
+					       content_disposition);
 	http_client_request_add_header(http_req, "Accept", "text/plain");
 
 	parser->http_req = http_req;
