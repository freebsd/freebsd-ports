--- relayctl/parser.h.orig	Wed Jun  6 18:25:59 2007
+++ relayctl/parser.h	Wed Jun  6 18:27:58 2007
@@ -38,5 +38,3 @@
 };
 
 struct parse_result	*parse(int, char *[]);
-const struct token      *match_token(const char *, const struct token []);
-void                     show_valid_args(const struct token []);
