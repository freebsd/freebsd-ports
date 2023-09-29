--- bpf_image.c.orig	2022-06-07 16:20:35 UTC
+++ bpf_image.c
@@ -36,7 +36,7 @@ bpf_image(p, n)
 
 char *
 bpf_image(p, n)
-	struct bpf_insn *p;
+	const struct bpf_insn *p;
 	int n;
 {
 	int v;
