--- src/panel.c.orig	2019-09-20 16:17:28 UTC
+++ src/panel.c
@@ -51,7 +51,7 @@
 #define PLATFORM_DORADO			1       /* Dorado + 9211 RevC           */
 #define PLATFORM_GX2BASED		1       /* Redcloud                             */
 
-unsigned char *XpressROMPtr;
+extern unsigned char *XpressROMPtr;
 
 #include "pnl_init.c"
 #include "pnl_bios.c"
