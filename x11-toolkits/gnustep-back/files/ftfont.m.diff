--- Source/art/ftfont.m.orig	Sun May 11 19:23:43 2003
+++ Source/art/ftfont.m	Tue Jun  3 05:25:16 2003
@@ -79,9 +79,9 @@
 @interface FTFontInfo : GSFontInfo <FTFontInfo>
 {
 @public
-  FTC_ImageDesc imgd;
+  FTC_Image_Desc imgd;
 
-  FTC_ImageDesc fallback;
+  FTC_Image_Desc fallback;
 
   FTFaceInfo *face_info;
 
@@ -748,7 +748,7 @@
   int use_sbit;
 
   FTC_SBit sbit;
-  FTC_ImageDesc cur;
+  FTC_Image_Desc cur;
 
   FT_Matrix ftmatrix;
   FT_Vector ftdelta;
@@ -800,23 +800,23 @@
 	    int rh = face_info->render_hints_hack;
 	    if (rh & 0x10000)
 	      {
-		cur.type = ftc_image_grays;
+		cur.image_type = ftc_image_grays;
 		rh = (rh >> 8) & 0xff;
 	      }
 	    else
 	      {
-		cur.type = ftc_image_mono;
+		cur.image_type = ftc_image_mono;
 		rh = rh & 0xff;
 	      }
 	    if (rh & 1)
-	      cur.type |= ftc_image_flag_autohinted;
+	      cur.image_type |= ftc_image_flag_autohinted;
 	    if (!(rh & 2))
-	      cur.type |= ftc_image_flag_unhinted;
+	      cur.image_type |= ftc_image_flag_unhinted;
 	  }
 	else if (xx < 8)
-	  cur.type = ftc_image_grays | ftc_image_flag_unhinted;
+	  cur.image_type = ftc_image_grays | ftc_image_flag_unhinted;
 	else
-	  cur.type = ftc_image_grays;
+	  cur.image_type = ftc_image_grays;
       }
     else
       {
@@ -1163,7 +1163,7 @@
   int use_sbit;
 
   FTC_SBit sbit;
-  FTC_ImageDesc cur;
+  FTC_Image_Desc cur;
 
   FT_Matrix ftmatrix;
   FT_Vector ftdelta;
@@ -1215,23 +1215,23 @@
 	    int rh = face_info->render_hints_hack;
 	    if (rh & 0x10000)
 	      {
-		cur.type = ftc_image_grays;
+		cur.image_type = ftc_image_grays;
 		rh = (rh >> 8) & 0xff;
 	      }
 	    else
 	      {
-		cur.type = ftc_image_mono;
+		cur.image_type = ftc_image_mono;
 		rh = rh & 0xff;
 	      }
 	    if (rh & 1)
-	      cur.type |= ftc_image_flag_autohinted;
+	      cur.image_type |= ftc_image_flag_autohinted;
 	    if (!(rh & 2))
-	      cur.type |= ftc_image_flag_unhinted;
+	      cur.image_type |= ftc_image_flag_unhinted;
 	  }
 	else if (xx < 8)
-	  cur.type = ftc_image_grays | ftc_image_flag_unhinted;
+	  cur.image_type = ftc_image_grays | ftc_image_flag_unhinted;
 	else
-	  cur.type = ftc_image_grays;
+	  cur.image_type = ftc_image_grays;
       }
     else
       {
@@ -1521,7 +1521,7 @@
       /* TODO: try to more efficiently? */
       /* TODO: set up all this stuff in -init... for the raw metric case */
       float xx, yy;
-      FTC_ImageDesc cur;
+      FTC_Image_Desc cur;
       FTC_SBit sbit;
 
       cur = imgd;
@@ -1534,23 +1534,23 @@
 	    int rh = face_info->render_hints_hack;
 	    if (rh & 0x10000)
 	      {
-		cur.type = ftc_image_grays;
+		cur.image_type = ftc_image_grays;
 		rh = (rh >> 8) & 0xff;
 	      }
 	    else
 	      {
-		cur.type = ftc_image_mono;
+		cur.image_type = ftc_image_mono;
 		rh = rh & 0xff;
 	      }
 	    if (rh & 1)
-	      cur.type |= ftc_image_flag_autohinted;
+	      cur.image_type |= ftc_image_flag_autohinted;
 	    if (!(rh & 2))
-	      cur.type |= ftc_image_flag_unhinted;
+	      cur.image_type |= ftc_image_flag_unhinted;
 	  }
 	else if (xx < 8)
-	  cur.type = ftc_image_grays | ftc_image_flag_unhinted;
+	  cur.image_type = ftc_image_grays | ftc_image_flag_unhinted;
 	else
-	  cur.type = ftc_image_grays;
+	  cur.image_type = ftc_image_grays;
 
       if ((error=FTC_SBitCache_Lookup(ftc_sbitcache, &cur, glyph, &sbit, NULL)))
 	{
@@ -1605,7 +1605,7 @@
 
 - (NSRect) boundingRectForGlyph: (NSGlyph)glyph
 {
-  FTC_ImageDesc *cur;
+  FTC_Image_Desc *cur;
   FT_BBox bbox;
   FT_Glyph g;
   FT_Error error;
@@ -1682,7 +1682,7 @@
 
   FTC_SBit sbit;
 
-  FTC_ImageDesc *cur;
+  FTC_Image_Desc *cur;
 
 
   cmap.face_id = imgd.font.face_id;
@@ -1895,7 +1895,7 @@
   unichar *uch;
   int ulen;
 
-  FTC_ImageDesc cur;
+  FTC_Image_Desc cur;
 
 
   FT_Matrix ftmatrix;
@@ -2065,7 +2065,7 @@
   int use_sbit;
 
   FTC_SBit sbit;
-  FTC_ImageDesc cur;
+  FTC_Image_Desc cur;
 
   FT_Matrix ftmatrix;
   FT_Vector ftdelta;
@@ -2111,9 +2111,9 @@
 
 /*	if (cur.font.pix_width < 16 && cur.font.pix_height < 16 &&
 	    cur.font.pix_width > 6 && cur.font.pix_height > 6)
-	  cur.type = ftc_image_mono;
+	  cur.image_type = ftc_image_mono;
 	else*/
-	  cur.type = ftc_image_grays, subpixel = YES, cur.font.pix_width *= 3, x *= 3;
+	  cur.image_type = ftc_image_grays, subpixel = YES, cur.font.pix_width *= 3, x *= 3;
 //			imgd.type|=|ftc_image_flag_unhinted; /* TODO? when? */
       }
     else
