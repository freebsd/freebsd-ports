--- io.c.orig	2011-12-09 18:04:38.000000000 +0400
+++ io.c	2014-05-07 18:15:26.000000000 +0400
@@ -56,7 +56,7 @@ static size_t io_get_gz_file_size(char *
 static size_t io_get_file_size(char *filename);
 static size_t io_get_regular_file_size(char *filename);
 size_t io_gz_file_to_mem (struct io_buf_handle *iobh, char *filename);
-int foma_net_print(struct fsm *net, gzFile *outfile);
+int foma_net_print(struct fsm *net, gzFile outfile);
 struct fsm *io_net_read(struct io_buf_handle *iobh, char **net_name);
 static inline int explode_line (char *buf, int *values);
 
@@ -507,7 +507,7 @@ struct fsm *fsm_read_text_file(char *fil
 }
 
 int fsm_write_binary_file(struct fsm *net, char *filename) {
-    gzFile *outfile;
+    gzFile outfile;
     if ((outfile = gzopen(filename,"wb")) == NULL) {
 	return(1);
     }
@@ -560,7 +560,7 @@ struct fsm *fsm_read_binary_file(char *f
 }
 
 int save_defined(char *filename) {
-    gzFile *outfile;
+    gzFile outfile;
     struct defined *def;
     def = get_defines();
     if (def == NULL) {
@@ -829,7 +829,7 @@ static int io_gets(struct io_buf_handle 
     return(i);
 }
 
-int foma_net_print(struct fsm *net, gzFile *outfile) {
+int foma_net_print(struct fsm *net, gzFile outfile) {
     struct sigma *sigma;
     struct fsm_state *fsm;
     int i, maxsigma, laststate, *cm, extras;
@@ -949,7 +949,7 @@ static size_t io_get_regular_file_size(c
 
 
 static size_t io_get_file_size(char *filename) {
-    gzFile *FILE;
+    gzFile FILE;
     size_t size;
     FILE = gzopen(filename, "r");
     if (FILE == NULL) {
@@ -968,7 +968,7 @@ static size_t io_get_file_size(char *fil
 size_t io_gz_file_to_mem(struct io_buf_handle *iobh, char *filename) {
 
     size_t size;
-    gzFile *FILE;
+    gzFile FILE;
 
     size = io_get_file_size(filename);
     if (size == 0) {
