--- libgnomeprint/gnome-print-meta.c.orig	Wed Oct 29 00:53:15 2003
+++ libgnomeprint/gnome-print-meta.c	Wed Oct 29 01:06:23 2003
@@ -312,6 +312,7 @@
 	gpm_encode_int (pc, w);
 	gpm_encode_int (pc, ch);
 
+	gpm_ensure_space(pc, w * ch * h);
 	for (y = 0; y < h; y++){
 		gpm_encode_block (pc, px, w * ch);
 		px += rowstride;
