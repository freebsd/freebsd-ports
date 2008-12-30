--- php_imap.c.orig	2008-12-30 11:06:18.000000000 +0100
+++ php_imap.c	2008-12-30 11:06:56.000000000 +0100
@@ -2172,7 +2172,7 @@
 
 	/* rfc822_parse_adrlist() modifies passed string. Copy it. */
 	str_copy = estrndup(Z_STRVAL_PP(str), Z_STRLEN_PP(str));
-	rfc822_parse_adrlist(&env->to, str_copy, defaulthost);
+	rfc822_parse_adrlist(&env->to, str_copy, Z_STRVAL_PP(defaulthost));
 	efree(str_copy);
 
 	array_init(return_value);
