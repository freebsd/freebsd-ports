--- provider.c.orig	2024-08-03 14:10:13 UTC
+++ provider.c
@@ -236,7 +236,9 @@ static int oauth_provider_parse_auth_header(php_oauth_
 		&return_value,
 		&subpats,
 		1, /* global */
+#if PHP_VERSION_ID <= 80300
 		1, /* use flags */
+#endif
 		2, /* PREG_SET_ORDER */
 		0
 	);
