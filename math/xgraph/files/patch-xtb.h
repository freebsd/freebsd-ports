--- xtb.h.orig	1997-07-16 18:40:41 UTC
+++ xtb.h
@@ -164,7 +164,7 @@ typedef union xtb_fmt_defn {
     xtb_fmt_align align;
 } xtb_fmt;
 
-#define NE	0
+#define NE	((xtb_fmt *) 0)
 
 DECLARE(xtb_w, xtb_fmt *, (xtb_frame *w));
    /* Returns formatting structure for frame */
