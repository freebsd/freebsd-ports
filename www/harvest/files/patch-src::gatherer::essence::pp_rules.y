--- src/gatherer/essence/pp_rules.y.orig	Mon Mar 17 07:18:10 1997
+++ src/gatherer/essence/pp_rules.y	Wed Nov 13 09:06:33 2002
@@ -65,6 +65,7 @@
 		;
 
 condition	: condattr condop condstr	{ $$ = mk_cond ($1, $2, $3); }
+		;
 
 condattr	: word				{ $$ = $1; }
 		;
