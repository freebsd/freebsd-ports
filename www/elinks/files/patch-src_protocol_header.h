--- src/protocol/header.h.orig	2022-12-25 18:17:02 UTC
+++ src/protocol/header.h
@@ -13,7 +13,7 @@ enum parse_header_param {
 	 * Unknown values should be treated as errors. */
 };
 
-char *parse_header(char *, const char *, char **);
+char *parse_header(const char *, const char *, const char **);
 enum parse_header_param parse_header_param(char *, const char *, char **, int);
 char *get_header_param(char *, const char *);
 
