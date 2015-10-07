--- src/iscan.c.orig	2013-04-30 10:47:49.000000000 +0900
+++ src/iscan.c	2013-04-30 10:48:19.000000000 +0900
@@ -635,7 +635,7 @@
 		uint size = ref_stack_count_inline(&o_stack) - pstack;
 		ref arr;
 
-		if_debug4('S', "[S}]d=%d, s=%d->%ld, c=%d\n",
+		if_debug4('S', "[S}]d=%d, s=%d->%d, c=%d\n",
 			  pdepth, pstack,
 			  (pstack == pdepth ? 0 :
 			   ref_stack_index(&o_stack, size)->value.intval),
