--- src/readstat_writer.c.orig	2023-05-02 13:36:19 UTC
+++ src/readstat_writer.c
@@ -35,7 +35,7 @@ readstat_string_ref_t *readstat_string_ref_init(const 
     return ref;
 }
 
-readstat_writer_t *readstat_writer_init() {
+readstat_writer_t *readstat_writer_init(void) {
     readstat_writer_t *writer = calloc(1, sizeof(readstat_writer_t));
 
     writer->variables = calloc(VARIABLES_INITIAL_CAPACITY, sizeof(readstat_variable_t *));
