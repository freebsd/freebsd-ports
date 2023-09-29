--- bpf_filter.c.orig	2022-06-07 16:20:35 UTC
+++ bpf_filter.c
@@ -143,8 +143,8 @@ bpf_filter(pc, p, wirelen, buflen)
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
