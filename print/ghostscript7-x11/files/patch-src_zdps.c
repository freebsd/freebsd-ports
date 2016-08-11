--- src/zdps.c.orig	2003-01-17 00:49:05 UTC
+++ src/zdps.c
@@ -46,19 +46,18 @@ zsetscreenphase(i_ctx_t *i_ctx_p)
 {
     os_ptr op = osp;
     int code;
-    long x, y;
+    int x, y;
 
     check_type(op[-2], t_integer);
     check_type(op[-1], t_integer);
     check_type(*op, t_integer);
     x = op[-1].value.intval;
     y = op->value.intval;
-    if (x != (int)x || y != (int)y ||
-	op[-2].value.intval < -1 ||
+    if (op[-2].value.intval < -1 ||
 	op[-2].value.intval >= gs_color_select_count
 	)
 	return_error(e_rangecheck);
-    code = gs_setscreenphase(igs, (int)x, (int)y,
+    code = gs_setscreenphase(igs, x, y,
 			     (gs_color_select_t) op[-2].value.intval);
     if (code >= 0)
 	pop(3);
