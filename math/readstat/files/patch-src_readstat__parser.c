--- src/readstat_parser.c.orig	2023-04-20 20:54:06 UTC
+++ src/readstat_parser.c
@@ -3,7 +3,7 @@
 #include "readstat.h"
 #include "readstat_io_unistd.h"
 
-readstat_parser_t *readstat_parser_init() {
+readstat_parser_t *readstat_parser_init(void) {
     readstat_parser_t *parser = calloc(1, sizeof(readstat_parser_t));
     parser->io = calloc(1, sizeof(readstat_io_t));
     if (unistd_io_init(parser) != READSTAT_OK) {
