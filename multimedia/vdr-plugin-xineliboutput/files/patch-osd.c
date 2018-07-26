--- a/osd.c.orig	2012-05-11 07:37:27 UTC
+++ b/osd.c
@@ -567,7 +567,7 @@ void cXinelibOsd::Flush(void)
       int NumColors;
       const tColor *Colors = Bitmap->Colors(NumColors);
       if (Colors) {
-	osd_rect_t DirtyArea = {x1:x1, y1:y1, x2:x2, y2:y2};
+	osd_rect_t DirtyArea = {x1:(uint16_t)x1, y1:(uint16_t)y1, x2:(uint16_t)x2, y2:(uint16_t)y2};
         CmdLut8(i,
                 Left() + Bitmap->X0() + XOffset, Top() + Bitmap->Y0() + YOffset,
                 Bitmap->Width(), Bitmap->Height(),
