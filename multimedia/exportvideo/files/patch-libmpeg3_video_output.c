--- libmpeg3/video/output.c.orig	2001-02-12 22:35:18.000000000 +0100
+++ libmpeg3/video/output.c	2007-11-15 15:55:06.000000000 +0100
@@ -483,10 +483,11 @@
 	*data++ = 0;
 
 #define STORE_PIXEL_RGB565 \
-	*((unsigned short*)data)++ = \
+	*data = \
 		((CLIP(r_l) & 0xf8) << 8) | \
 		((CLIP(g_l) & 0xfc) << 3) | \
-		((CLIP(b_l) & 0xf8) >> 3);
+		((CLIP(b_l) & 0xf8) >> 3); \
+	data += sizeof(unsigned short);
 
 #define STORE_PIXEL_RGB888 \
 	*data++ = CLIP(r_l); \
