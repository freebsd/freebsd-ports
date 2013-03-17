diff --git a/libfreerdp-codec/color.c b/libfreerdp-codec/color.c
index dc77707..ee3c1fa 100644
--- libfreerdp-codec/color.c
+++ libfreerdp-codec/color.c
@@ -86,7 +86,7 @@ void freerdp_set_pixel(uint8* data, int x, int y, int width, int height, int bpp
 	}
 }
 
-INLINE void freerdp_color_split_rgb(uint32* color, int bpp, uint8* red, uint8* green, uint8* blue, uint8* alpha, HCLRCONV clrconv)
+static INLINE void freerdp_color_split_rgb(uint32* color, int bpp, uint8* red, uint8* green, uint8* blue, uint8* alpha, HCLRCONV clrconv)
 {
 	*red = *green = *blue = 0;
 	*alpha = (clrconv->alpha) ? 0xFF : 0x00;
@@ -137,7 +137,7 @@ INLINE void freerdp_color_split_rgb(uint32* color, int bpp, uint8* red, uint8* g
 	}
 }
 
-INLINE void freerdp_color_split_bgr(uint32* color, int bpp, uint8* red, uint8* green, uint8* blue, uint8* alpha, HCLRCONV clrconv)
+static INLINE void freerdp_color_split_bgr(uint32* color, int bpp, uint8* red, uint8* green, uint8* blue, uint8* alpha, HCLRCONV clrconv)
 {
 	*red = *green = *blue = 0;
 	*alpha = (clrconv->alpha) ? 0xFF : 0x00;
@@ -188,7 +188,7 @@ INLINE void freerdp_color_split_bgr(uint32* color, int bpp, uint8* red, uint8* g
 	}
 }
 
-INLINE void freerdp_color_make_rgb(uint32* color, int bpp, uint8* red, uint8* green, uint8* blue, uint8* alpha, HCLRCONV clrconv)
+static INLINE void freerdp_color_make_rgb(uint32* color, int bpp, uint8* red, uint8* green, uint8* blue, uint8* alpha, HCLRCONV clrconv)
 {
 	switch (bpp)
 	{
@@ -229,7 +229,7 @@ INLINE void freerdp_color_make_rgb(uint32* color, int bpp, uint8* red, uint8* gr
 	}
 }
 
-INLINE void freerdp_color_make_bgr(uint32* color, int bpp, uint8* red, uint8* green, uint8* blue, uint8* alpha, HCLRCONV clrconv)
+static INLINE void freerdp_color_make_bgr(uint32* color, int bpp, uint8* red, uint8* green, uint8* blue, uint8* alpha, HCLRCONV clrconv)
 {
 	switch (bpp)
 	{
