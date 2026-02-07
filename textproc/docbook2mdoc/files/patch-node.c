--- node.c.orig	2022-09-15 07:09:04 UTC
+++ node.c
@@ -33,6 +33,7 @@ static	const struct nodeprop properties[] = {
 
 static	const struct nodeprop properties[] = {
 	{ "abstract",		CLASS_BLOCK },
+	{ "address",		CLASS_LINE },
 	{ "appendix",		CLASS_BLOCK },
 	{ "arg",		CLASS_ENCL },
 	{ "author",		CLASS_LINE },
