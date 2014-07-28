--- xtb.c.orig	Thu Jul 17 04:26:41 1997
+++ xtb.c	Fri Dec 10 03:06:26 1999
@@ -196,7 +196,7 @@
 {
     xtb_data data;
 
-    if (!XFindContext(t_disp, win, h_context, &data)) {
+    if (!XFindContext(t_disp, win, h_context, (XPointer*)&data)) {
 	return ((struct h_info *) data)->info;
     } else {
 	return (xtb_data) 0;
