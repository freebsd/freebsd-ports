--- src/iscan.c.orig	2003-01-17 00:49:04 UTC
+++ src/iscan.c
@@ -635,7 +635,7 @@ scan_token(i_ctx_t *i_ctx_p, stream * s,
 		uint size = ref_stack_count_inline(&o_stack) - pstack;
 		ref arr;
 
-		if_debug4('S', "[S}]d=%d, s=%d->%ld, c=%d\n",
+		if_debug4('S', "[S}]d=%d, s=%d->%d, c=%d\n",
 			  pdepth, pstack,
 			  (pstack == pdepth ? 0 :
 			   ref_stack_index(&o_stack, size)->value.intval),
