--- util.h.orig	2002-04-24 15:45:24 UTC
+++ util.h
@@ -57,7 +57,7 @@ void copy_stream(stream *in, out_state *
 void debug(out_state *out, char *fmt, ...);
 char *expand(char *path);
 FILE *fopen_uniq(char **s);
-char *getline(FILE *f);
+char *get_line(FILE *f);
 void output_header(out_state *out, symbol name, struct header *h);
 void prdebug(int level, char *fmt, ...);
 void prdebug_init(int do_file, int do_stdout);
