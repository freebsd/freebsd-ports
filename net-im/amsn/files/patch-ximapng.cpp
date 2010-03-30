--- utils/TkCximage/src/CxImage/ximapng.cpp.orig	2008-03-07 20:14:37.000000000 +0100
+++ utils/TkCximage/src/CxImage/ximapng.cpp	2010-03-30 07:33:06.000000000 +0200
@@ -142,9 +142,9 @@
 	if (info_ptr->num_trans!=0){ //palette transparency
 		if (info_ptr->num_trans==1){
 			if (info_ptr->color_type == PNG_COLOR_TYPE_PALETTE){
-				info.nBkgndIndex = info_ptr->trans_values.index;
+				info.nBkgndIndex = info_ptr->trans_color.index;
 			} else{
-				info.nBkgndIndex = info_ptr->trans_values.gray>>nshift;
+				info.nBkgndIndex = info_ptr->trans_color.gray>>nshift;
 			}
 		}
 		if (info_ptr->num_trans>1){
@@ -152,7 +152,7 @@
 			if (pal){
 				DWORD ip;
 				for (ip=0;ip<min(head.biClrUsed,(unsigned long)info_ptr->num_trans);ip++)
-					pal[ip].rgbReserved=info_ptr->trans[ip];
+					pal[ip].rgbReserved=info_ptr->trans_alpha[ip];
 				for (ip=info_ptr->num_trans;ip<head.biClrUsed;ip++){
 					pal[ip].rgbReserved=255;
 				}
@@ -166,9 +166,9 @@
 		int num_trans;
 		png_color_16 *image_background;
 		if (png_get_tRNS(png_ptr, info_ptr, &trans, &num_trans, &image_background)){
-			info.nBkgndColor.rgbRed   = (BYTE)(info_ptr->trans_values.red>>nshift);
-			info.nBkgndColor.rgbGreen = (BYTE)(info_ptr->trans_values.green>>nshift);
-			info.nBkgndColor.rgbBlue  = (BYTE)(info_ptr->trans_values.blue>>nshift);
+			info.nBkgndColor.rgbRed   = (BYTE)(info_ptr->trans_color.red>>nshift);
+			info.nBkgndColor.rgbGreen = (BYTE)(info_ptr->trans_color.green>>nshift);
+			info.nBkgndColor.rgbBlue  = (BYTE)(info_ptr->trans_color.blue>>nshift);
 			info.nBkgndColor.rgbReserved = 0;
 			info.nBkgndIndex = 0;
 		}
@@ -417,12 +417,12 @@
 	if (info.nBkgndIndex >= 0){
 		info_ptr->num_trans = 1;
 		info_ptr->valid |= PNG_INFO_tRNS;
-		info_ptr->trans = trans;
-		info_ptr->trans_values.index = (BYTE)info.nBkgndIndex;
-		info_ptr->trans_values.red   = tc.rgbRed;
-		info_ptr->trans_values.green = tc.rgbGreen;
-		info_ptr->trans_values.blue  = tc.rgbBlue;
-		info_ptr->trans_values.gray  = info_ptr->trans_values.index;
+		info_ptr->trans_alpha = trans;
+		info_ptr->trans_color.index = (BYTE)info.nBkgndIndex;
+		info_ptr->trans_color.red   = tc.rgbRed;
+		info_ptr->trans_color.green = tc.rgbGreen;
+		info_ptr->trans_color.blue  = tc.rgbBlue;
+		info_ptr->trans_color.gray  = info_ptr->trans_color.index;
 
 		// the transparency indexes start from 0 for non grayscale palette
 		if (!bGrayScale && head.biClrUsed && info.nBkgndIndex)
@@ -443,7 +443,7 @@
 				trans[ip]=GetPaletteColor((BYTE)ip).rgbReserved;
 			info_ptr->num_trans = (WORD)nc;
 			info_ptr->valid |= PNG_INFO_tRNS;
-			info_ptr->trans = trans;
+			info_ptr->trans_alpha = trans;
 		}
 
 		// copy the palette colors
