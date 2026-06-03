--- src/lib_ccx/configuration.c.orig	2026-01-20 09:45:22 UTC
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
