--- bpf_dump.c.orig   2007-11-07 07:34:18.000000000 +0100
+++ bpf_dump.c   2014-10-17 12:39:01.000000000 +0200
@@ -33,10 +33,10 @@
 #include <stdio.h>
 
 
-extern void bpf_dump(struct bpf_program *, int);
+extern void bpf_dump(const struct bpf_program *, int);
 
 void
-bpf_dump(struct bpf_program *p, int option)
+bpf_dump(const struct bpf_program *p, int option)
 {
        struct bpf_insn *insn;
        int i;
