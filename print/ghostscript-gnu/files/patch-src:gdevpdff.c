--- src/gdevpdff.c.org	2003-01-17 09:49:02.000000000 +0900
+++ src/gdevpdff.c	2003-09-21 05:08:36.000000000 +0900
@@ -276,6 +276,11 @@
     const byte *chars = font->font_name.chars;
     uint size = font->font_name.size;
 
+    /* CIDFonts has null string in font_name, key_name is used */
+    if (0 == size) {
+	chars = font->key_name.chars;
+	size = font->key_name.size;
+    }
     /*
      * The behavior of Acrobat Distiller changed between 3.0 (PDF 1.2),
      * which will never embed the base 14 fonts, and 4.0 (PDF 1.3), which
@@ -720,19 +725,22 @@
 	same &= ~FONT_SAME_METRICS;
 	break;
     case FONT_EMBED_NO:
-	/*
-	 * Per the PDF 1.3 documentation, there are only 3 BaseEncoding
-	 * values allowed for non-embedded fonts.  Pick one here.
-	 */
-	BaseEncoding =
-	    ((const gs_font_base *)base_font)->nearest_encoding_index;
-	switch (BaseEncoding) {
-	default:
-	    BaseEncoding = ENCODING_INDEX_WINANSI;
-	case ENCODING_INDEX_WINANSI:
-	case ENCODING_INDEX_MACROMAN:
-	case ENCODING_INDEX_MACEXPERT:
-	    break;
+	if (!(font->FontType == ft_CID_encrypted ||
+	      font->FontType == ft_CID_TrueType)) {
+	    /*
+	     * Per the PDF 1.3 documentation, there are only 3 BaseEncoding
+	     * values allowed for non-embedded fonts.  Pick one here.
+	     */
+	    BaseEncoding =
+	        ((const gs_font_base *)base_font)->nearest_encoding_index;
+	    switch (BaseEncoding) {
+	    default:
+	        BaseEncoding = ENCODING_INDEX_WINANSI;
+	    case ENCODING_INDEX_WINANSI:
+	    case ENCODING_INDEX_MACROMAN:
+	    case ENCODING_INDEX_MACEXPERT:
+	        break;
+	    }
 	}
 	code = pdf_compute_font_descriptor(pdev, &fdesc, font, NULL);
 	if (code < 0)
@@ -888,6 +896,7 @@
 	memcpy(ppf->widths_known, ftemp_widths_known,
 	       sizeof(ftemp_widths_known));
     }
+    ppf->embed = embed;
     code = pdf_register_font(pdev, font, ppf);
 
     *pppf = ppf;

