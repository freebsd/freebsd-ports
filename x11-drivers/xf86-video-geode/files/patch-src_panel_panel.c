--- src/panel/panel.c.orig	2019-09-20 16:17:28 UTC
+++ src/panel/panel.c
@@ -65,7 +65,7 @@ extern unsigned long gfx_detect_video(void);
 #define PLATFORM_DORADO			1       /* Dorado + 9211 RevC */
 #define PLATFORM_REDCLOUD		1       /* GX2 */
 
-unsigned char *XpressROMPtr;
+extern unsigned char *XpressROMPtr;
 
 #include "pnl_init.c"
 #include "pnl_bios.c"
