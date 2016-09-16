--- bpf_image.c.orig	2016-09-12 16:51:21.704680000 +0200
+++ bpf_image.c	2016-09-12 16:43:28.038646000 +0200
@@ -36,7 +36,7 @@
 
 char *
 bpf_image(p, n)
-	struct bpf_insn *p;
+	const struct bpf_insn *p;
 	int n;
 {
 	int v;
