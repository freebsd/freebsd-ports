--- src/gdevpdfw.c.orig	2003-01-17 00:49:01 UTC
+++ src/gdevpdfw.c
@@ -348,18 +348,19 @@ pdf_write_CIDFont_widths(gx_device_pdf *
     /* Use the most common width as DW. */
 
     {
-	ushort counts[1001];
+        ushort counts[1500*2]; /* histogram of (-1500..1500) */
 	int dw_count = 0, i;
 
 	memset(counts, 0, sizeof(counts));
 	while (!psf_enumerate_glyphs_next(&genum, &glyph)) {
-	    int width = ppf->Widths[glyph - gs_min_cid_glyph];
+	    int cid = glyph - gs_min_cid_glyph;
+	    int width = ppf->Widths[cid];
 
-	    counts[min(width, countof(counts) - 1)]++;
+	    counts[max(0,min(width+countof(counts)/2,countof(counts)-1))]++;
 	}
-	for (i = 0; i < countof(counts); ++i)
+	for (i = 0; i < countof(counts); i++)
 	    if (counts[i] > dw_count)
-		dw = i, dw_count = counts[i];
+		dw = i - countof(counts)/2, dw_count = counts[i];
 	if (dw != 0)
 	    pprintd1(s, "/DW %d\n", dw);
     }
@@ -496,14 +497,16 @@ pdf_write_font_resource(gx_device_pdf *p
 	if (pdf_has_subset_prefix(chars, size))
 	    chars += SUBSET_PREFIX_SIZE, size -= SUBSET_PREFIX_SIZE;
 	pdf_put_name(pdev, chars, size);
-	if (pef->sub_font_type == ft_CID_encrypted &&
+	if ((pef->sub_font_type == ft_CID_encrypted ||
+	     pef->sub_font_type == ft_CID_TrueType) &&
 	    pef->cmapname[0] == '/'
 	    ) {
 	    stream_putc(s, '-');
 	    pdf_put_name_chars(pdev, (const byte*) (pef->cmapname + 1),
 			       strlen(pef->cmapname + 1));
 	}
-	pprints1(s, "/Encoding %s", pef->cmapname);
+	pprints1(s, (pef->cmapname[0] == '/') ? "/Encoding%s" : "/Encoding %s",
+		 pef->cmapname);
 	pprintld1(s, "/DescendantFonts[%ld 0 R]",
 		pdf_resource_id((const pdf_resource_t *)pef->DescendantFont));
 	write_Widths = 0;
@@ -563,8 +566,10 @@ pdf_write_font_resource(gx_device_pdf *p
 	break;
     case -1:
 	pdf_write_CIDFont_widths(pdev, pef);
-	if (pef->FontType == ft_CID_TrueType)
-	    pdf_write_CIDToGIDMap(pdev, pef, &cidmap_id);
+	if (pef->FontType == ft_CID_TrueType) {
+	    if (pef->embed != FONT_EMBED_NO)
+	        pdf_write_CIDToGIDMap(pdev, pef, &cidmap_id);
+	}
 	break;
     }
     if (pef->Differences) {
