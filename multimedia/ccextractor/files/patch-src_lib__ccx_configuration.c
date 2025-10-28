--- src/lib_ccx/configuration.c.orig	2025-10-28 13:57:45 UTC
+++ src/lib_ccx/configuration.c
@@ -91,7 +91,7 @@ static void parse_file(FILE *f, struct ccx_s_options *
 static void parse_file(FILE *f, struct ccx_s_options *opt)
 {
 	char *str = (char *)malloc(128);
-	char c = '\0';
+	int c = '\0';
 	int comments = 0;
 	int i = 0;
 	int ret = 0;
