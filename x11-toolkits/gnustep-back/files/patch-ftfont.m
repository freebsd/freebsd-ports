--- Source/art/ftfont.m.orig	Mon Feb 10 18:46:06 2003
+++ Source/art/ftfont.m	Sun Mar 30 22:06:30 2003
@@ -79,9 +79,9 @@
 @interface FTFontInfo : GSFontInfo <FTFontInfo>
 {
 @public
-  FTC_ImageDesc imgd;
+  FTC_Image_Desc imgd;
 
-  FTC_ImageDesc fallback;
+  FTC_Image_Desc fallback;
 
   FTFaceInfo *face_info;
 
@@ -743,7 +743,7 @@
   int use_sbit;
 
   FTC_SBit sbit;
-  FTC_ImageDesc cur;
+  FTC_Image_Desc cur;
 
   FT_Matrix ftmatrix;
   FT_Vector ftdelta;
@@ -1135,7 +1135,7 @@
   int use_sbit;
 
   FTC_SBit sbit;
-  FTC_ImageDesc cur;
+  FTC_Image_Desc cur;
 
   FT_Matrix ftmatrix;
   FT_Vector ftdelta;
@@ -1466,7 +1466,7 @@
       /* TODO: try to more efficiently? */
       /* TODO: set up all this stuff in -init... for the raw metric case */
       float xx, yy;
-      FTC_ImageDesc cur;
+      FTC_Image_Desc cur;
       FTC_SBit sbit;
 
       cur = imgd;
@@ -1547,7 +1547,7 @@
 
 - (NSRect) boundingRectForGlyph: (NSGlyph)glyph
 {
-  FTC_ImageDesc *cur;
+  FTC_Image_Desc *cur;
   FT_BBox bbox;
   FT_Glyph g;
 
@@ -1618,7 +1618,7 @@
 
   FTC_SBit sbit;
 
-  FTC_ImageDesc *cur;
+  FTC_Image_Desc *cur;
 
 
   cmap.face_id = imgd.font.face_id;
@@ -1831,7 +1831,7 @@
   unichar *uch;
   int ulen;
 
-  FTC_ImageDesc cur;
+  FTC_Image_Desc cur;
 
 
   FT_Matrix ftmatrix;
@@ -2003,7 +2003,7 @@
   int use_sbit;
 
   FTC_SBit sbit;
-  FTC_ImageDesc cur;
+  FTC_Image_Desc cur;
 
   FT_Matrix ftmatrix;
   FT_Vector ftdelta;
