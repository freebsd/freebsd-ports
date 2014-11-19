--- sf-gencode.h         2014-10-17 12:39:16.000000000 +0200
+++ sf-gencode.h.orig     2014-10-17 12:39:01.000000000 +0200
@@ -188,7 +188,7 @@
 const char *sf_get_error(void);
 int sf_compile(struct bpf_program *, char *, int, bpf_u_int32);
 void sf_freecode(struct bpf_program *);
-void bpf_dump(struct bpf_program *, int);
+void bpf_dump(const struct bpf_program *, int);
 
 extern int no_optimize;
