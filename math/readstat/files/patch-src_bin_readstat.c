--- src/bin/readstat.c.orig	2023-04-20 20:55:14 UTC
+++ src/bin/readstat.c
@@ -154,7 +154,7 @@ readstat_error_t parse_file(readstat_parser_t *parser,
     return error;
 }
 
-static void print_version() {
+static void print_version(void) {
     fprintf(stdout, "ReadStat version " READSTAT_VERSION "\n");
 }
 
