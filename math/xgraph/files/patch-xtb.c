--- xtb.c.orig	2000-08-02 18:33:01 UTC
+++ xtb.c
@@ -198,7 +198,7 @@ Window win;
 {
     xtb_data data;
 
-    if (!XFindContext(t_disp, win, h_context, &data)) {
+    if (!XFindContext(t_disp, win, h_context, (XPointer*)&data)) {
 	return ((struct h_info *) data)->info;
     } else {
 	return (xtb_data) 0;
