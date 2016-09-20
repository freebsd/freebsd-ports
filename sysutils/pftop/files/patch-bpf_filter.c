--- bpf_filter.c.orig	2016-09-12 16:50:11.454297000 +0200
+++ bpf_filter.c	2016-09-12 16:43:28.150188000 +0200
@@ -143,8 +143,8 @@
  */
 u_int
 bpf_filter(pc, p, wirelen, buflen)
-	struct bpf_insn *pc;
-	u_char *p;
+	const struct bpf_insn *pc;
+	const u_char *p;
 	u_int wirelen;
 	u_int buflen;
 {
