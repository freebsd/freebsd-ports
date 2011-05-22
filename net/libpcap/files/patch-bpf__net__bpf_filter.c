--- ./bpf/net/bpf_filter.c.orig	2010-03-11 20:56:53.000000000 -0500
+++ ./bpf/net/bpf_filter.c	2011-05-22 12:59:10.148490778 -0400
@@ -405,7 +405,18 @@
 			continue;
 
 		case BPF_JMP|BPF_JA:
+#if defined(KERNEL) || defined(_KERNEL)
+			/*
+			 * No backward jumps allowed.
+			 */
 			pc += pc->k;
+#else
+			/*
+			 * XXX - we currently implement "ip6 protochain"
+			 * with backward jumps, so sign-extend pc->k.
+			 */
+			pc += (bpf_int32)pc->k;
+#endif
 			continue;
 
 		case BPF_JMP|BPF_JGT|BPF_K:
