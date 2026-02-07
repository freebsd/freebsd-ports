--- xa_color.c.orig	1999-03-21 22:36:25 UTC
+++ xa_color.c
@@ -2606,6 +2606,7 @@ xaULONG image_type;
 
 void *YUV2x2_Blk_Func(image_type,blks,dith_flag)
 xaULONG image_type;
+xaULONG blks;
 xaULONG dith_flag;
 { void (*color_func)();
   if (blks == 1)
