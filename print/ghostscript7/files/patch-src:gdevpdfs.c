--- src/gdevpdfs.c.org	2003-09-20 00:11:16.000000000 +0900
+++ src/gdevpdfs.c	2003-09-25 17:44:10.000000000 +0900
@@ -481,15 +481,21 @@
 
 	    if (cid < pfd->chars_count) {
 		int index = cid >> 3, mask = 0x80 >> (cid & 7);
+		int gid;
+
+		if (!(pfd->chars_used.data[index] & mask) ||
+		    !(psubf->widths_known[index] & mask)) {
 
-		if (!(pfd->chars_used.data[index] & mask)) {
-		    pfd->chars_used.data[index] |= mask;
 		    if (psubf->CIDToGIDMap) {
 			gs_font_cid2 *const subfont2 =
 			    (gs_font_cid2 *)subfont;
-			int gid =
-			    subfont2->cidata.CIDMap_proc(subfont2, glyph);
 
+			gid = subfont2->cidata.CIDMap_proc(subfont2, glyph);
+		    }
+		}
+		if (!(pfd->chars_used.data[index] & mask)) {
+		    pfd->chars_used.data[index] |= mask;
+		    if (psubf->CIDToGIDMap) {
 			if (gid >= 0) {
 			    psubf->CIDToGIDMap[cid] = gid;
 			    mark_glyphs_used(subfont, gid + gs_min_cid_glyph,
@@ -500,7 +506,11 @@
 		if (!(psubf->widths_known[index] & mask)) {
 		    int width;
 
-		    code = pdf_glyph_width(psubf, glyph, subfont, &width);
+		    if (psubf->CIDToGIDMap)
+			code = pdf_glyph_width(psubf, gid + gs_min_cid_glyph,
+					       subfont, &width);
+		    else
+		        code = pdf_glyph_width(psubf, glyph, subfont, &width);
 		    if (code == 0) {
 			psubf->Widths[cid] = width;
 			psubf->widths_known[index] |= mask;
