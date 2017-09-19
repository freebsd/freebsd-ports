--- SixelConverter.vala.orig	2016-09-25 11:53:37 UTC
+++ SixelConverter.vala
@@ -90,7 +90,7 @@ public class SixelConverter
 	public void SetPaletteFixed8()
 	{
 		for (int i = 0; i < 8; i++) {
-			uint8 R = (uint8)((i     ) & 0x01) * 255;
+			uint8 R = (uint8)((i >> 0) & 0x01) * 255;
 			uint8 G = (uint8)((i >> 1) & 0x01) * 255;
 			uint8 B = (uint8)((i >> 2) & 0x01) * 255;
 
@@ -131,7 +131,7 @@ public class SixelConverter
 		// ANSI 16 色といっても色実体は実装依存らしい。
 
 		for (int i = 0; i < 16; i++) {
-			uint8 R = (uint8)((i     ) & 0x01);
+			uint8 R = (uint8)((i >> 0) & 0x01);
 			uint8 G = (uint8)((i >> 1) & 0x01);
 			uint8 B = (uint8)((i >> 2) & 0x01);
 			uint8 I = (uint8)((i >> 3) & 0x01);
@@ -153,7 +153,7 @@ public class SixelConverter
 		for (int i = 0; i < 256; i++) {
 			Palette[i, 0] = (uint8)(((i >> 5) & 0x07) * 255 / 7);
 			Palette[i, 1] = (uint8)(((i >> 2) & 0x07) * 255 / 7);
-			Palette[i, 2] = (uint8)(((i     ) & 0x03) * 255 / 3);
+			Palette[i, 2] = (uint8)(((i >> 0) & 0x03) * 255 / 3);
 		}
 		PaletteCount = 256;
 	}
