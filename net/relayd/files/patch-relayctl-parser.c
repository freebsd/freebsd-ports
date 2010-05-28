--- relayctl/parser.c.orig	2010-05-27 11:10:01.109068426 +0200
+++ relayctl/parser.c	2010-05-27 11:11:24.194566616 +0200
@@ -166,7 +166,7 @@
 }
 
 const struct token *
-match_token(const char *word, const struct token table[])
+match_token(const char *word, const struct token *table)
 {
 	u_int			 i, match;
 	const struct token	*t = NULL;
@@ -243,7 +243,7 @@
 }
 
 void
-show_valid_args(const struct token table[])
+show_valid_args(const struct token *table)
 {
 	int	i;
 
