--- src/opt_extract.c.orig	2023-02-20 12:39:15 UTC
+++ src/opt_extract.c
@@ -164,7 +164,7 @@ void 
 parser_opts (int argc, char **argv)
 {
 
-	char c;
+	int c;
 
 	static struct option long_options[] =
 	{
