--- src/fcfreetype.c.orig	Fri Jul 18 17:54:08 2003
+++ src/fcfreetype.c	Fri Jul 18 17:54:12 2003
@@ -255,87 +255,6 @@
     return 0;
 }
 
-typedef struct _FcStringConst {
-    const char	*name;
-    int		value;
-} FcStringConst;
-
-static int
-FcStringIsConst (const FcChar8		*string,
-		 const FcStringConst	*c,
-		 int			nc)
-{
-    int	i;
-
-    for (i = 0; i < nc; i++)
-	if (FcStrCmpIgnoreBlanksAndCase (string, c[i].name) == 0)
-	    return c[i].value;
-    return -1;
-}
-
-static int
-FcStringContainsConst (const FcChar8	    *string,
-		       const FcStringConst  *c,
-		       int		    nc)
-{
-    int	i;
-
-    for (i = 0; i < nc; i++)
-	if (FcStrContainsIgnoreBlanksAndCase (string, c[i].name))
-	    return c[i].value;
-    return -1;
-}
-
-static const FcStringConst  weightConsts[] = {
-    { "thin",		FC_WEIGHT_THIN },
-    { "extralight",	FC_WEIGHT_EXTRALIGHT },
-    { "ultralight",	FC_WEIGHT_ULTRALIGHT },
-    { "light",		FC_WEIGHT_LIGHT },
-    { "book",		FC_WEIGHT_BOOK },
-    { "regular",	FC_WEIGHT_REGULAR },
-    { "normal",		FC_WEIGHT_NORMAL },
-    { "medium",		FC_WEIGHT_MEDIUM },
-    { "demibold",	FC_WEIGHT_DEMIBOLD },
-    { "demi",		FC_WEIGHT_DEMIBOLD },
-    { "semibold",	FC_WEIGHT_SEMIBOLD },
-    { "bold",		FC_WEIGHT_BOLD },
-    { "extrabold",	FC_WEIGHT_EXTRABOLD },
-    { "ultrabold",	FC_WEIGHT_ULTRABOLD },
-    { "black",		FC_WEIGHT_BLACK },
-    { "heavy",		FC_WEIGHT_HEAVY },
-};
-
-#define NUM_WEIGHT_CONSTS  (sizeof (weightConsts) / sizeof (weightConsts[0]))
-
-#define FcIsWeight(s)	    FcStringIsConst(s,weightConsts,NUM_WEIGHT_CONSTS)
-#define FcContainsWeight(s) FcStringContainsConst (s,weightConsts,NUM_WEIGHT_CONSTS)
-
-static const FcStringConst  widthConsts[] = {
-    { "ultracondensed",	FC_WIDTH_ULTRACONDENSED },
-    { "extracondensed",	FC_WIDTH_EXTRACONDENSED },
-    { "semicondensed",  FC_WIDTH_SEMICONDENSED },
-    { "condensed",	FC_WIDTH_CONDENSED },	/* must be after *condensed */
-    { "normal",		FC_WIDTH_NORMAL },
-    { "semiexpanded",	FC_WIDTH_SEMIEXPANDED },
-    { "extraexpanded",	FC_WIDTH_EXTRAEXPANDED },
-    { "ultraexpanded",	FC_WIDTH_ULTRAEXPANDED },
-    { "expanded",	FC_WIDTH_EXPANDED },	/* must be after *expanded */
-};
-
-#define NUM_WIDTH_CONSTS    (sizeof (widthConsts) / sizeof (widthConsts[0]))
-
-#define FcIsWidth(s)	    FcStringIsConst(s,widthConsts,NUM_WIDTH_CONSTS)
-#define FcContainsWidth(s)  FcStringContainsConst (s,widthConsts,NUM_WIDTH_CONSTS)
-
-static const FcStringConst  slantConsts[] = {
-    { "italic",		FC_SLANT_ITALIC },
-    { "oblique",	FC_SLANT_OBLIQUE },
-};
-
-#define NUM_SLANT_CONSTS    (sizeof (slantConsts) / sizeof (slantConsts[0]))
-
-#define FcIsSlant(s)	    FcStringIsConst(s,slantConsts,NUM_SLANT_CONSTS)
-#define FcContainsSlant(s)  FcStringContainsConst (s,slantConsts,NUM_SLANT_CONSTS)
 
 FcPattern *
 FcFreeTypeQuery (const FcChar8	*file,
@@ -345,8 +264,8 @@
 {
     FT_Face	    face;
     FcPattern	    *pat;
-    int		    slant = -1;
-    int		    weight = -1;
+    int		    slant;
+    int		    weight;
     int		    width = -1;
     int		    i;
     FcCharSet	    *cs;
@@ -358,9 +277,6 @@
     int		    spacing;
     TT_OS2	    *os2;
     PS_FontInfoRec  psfontinfo;
-#ifdef USE_FTBDF
-    BDF_PropertyRec prop;
-#endif
     TT_Header	    *head;
     const FcChar8   *exclusiveLang = 0;
     FT_SfntName	    sname;
@@ -391,6 +307,15 @@
 	goto bail1;
 
 
+    slant = FC_SLANT_ROMAN;
+    if (face->style_flags & FT_STYLE_FLAG_ITALIC)
+	slant = FC_SLANT_ITALIC;
+
+
+    weight = FC_WEIGHT_MEDIUM;
+    if (face->style_flags & FT_STYLE_FLAG_BOLD)
+	weight = FC_WEIGHT_BOLD;
+
     /*
      * Get the OS/2 table
      */
@@ -673,15 +598,30 @@
     }
 
     if (FcDebug() & FC_DBG_SCAN)
-	printf ("\n\"%s\" \"%s\"\n", family, style ? style : (FcChar8 *) "<none>");
+	printf ("\"%s\" \"%s\" ", family, style ? style : (FcChar8 *) "<none>");
 
     if (!FcPatternAddString (pat, FC_FAMILY, family))
+    {
+	if (family_allocated)
+	    free (family);
+	if (style_allocated)
+	    free (style);
 	goto bail1;
+    }
+
+    if (family_allocated)
+	free (family);
 
     if (style)
     {
 	if (!FcPatternAddString (pat, FC_STYLE, style))
+	{
+	    if (style_allocated)
+		free (style);
 	    goto bail1;
+	}
+	if (style_allocated)
+	    free (style);
     }
 
     if (!FcPatternAddString (pat, FC_FILE, file))
@@ -755,7 +695,7 @@
     if (os2 && os2->version != 0xffff)
     {
 	if (os2->usWeightClass == 0)
-	    ;
+	    weight = -1;
 	else if (os2->usWeightClass < 150)
 	    weight = FC_WEIGHT_THIN;
 	else if (os2->usWeightClass < 250)
@@ -774,6 +714,8 @@
 	    weight = FC_WEIGHT_EXTRABOLD;
 	else if (os2->usWeightClass < 950)
 	    weight = FC_WEIGHT_BLACK;
+	else
+	    weight = FC_WEIGHT_MEDIUM;
 
 	switch (os2->usWidthClass) {
 	case 1:	width = FC_WIDTH_ULTRACONDENSED; break;
@@ -795,12 +737,36 @@
     
     if (FT_Get_PS_Font_Info(face, &psfontinfo) == 0)
     {
-	if (weight == -1 && psfontinfo.weight)
+	if (psfontinfo.weight)
 	{
-	    weight = FcIsWeight (psfontinfo.weight);
-    	    if (FcDebug() & FC_DBG_SCANV)
-    		printf ("\tType1 weight %s maps to %d\n",
-			psfontinfo.weight, weight);
+	    static struct {
+		char    *name;
+		int	value;
+	    } ps_weights[] = {
+		{ "thin",		FC_WEIGHT_THIN },
+		{ "extralight",		FC_WEIGHT_EXTRALIGHT },
+		{ "ultralight",		FC_WEIGHT_ULTRALIGHT },
+		{ "light",		FC_WEIGHT_LIGHT },
+		{ "regular",		FC_WEIGHT_REGULAR },
+		{ "normal",		FC_WEIGHT_NORMAL },
+		{ "medium",		FC_WEIGHT_MEDIUM },
+		{ "demibold",		FC_WEIGHT_DEMIBOLD },
+		{ "semibold",		FC_WEIGHT_SEMIBOLD },
+		{ "bold",		FC_WEIGHT_BOLD },
+		{ "extrabold",		FC_WEIGHT_EXTRABOLD },
+		{ "ultrabold",		FC_WEIGHT_ULTRABOLD },
+		{ "black",		FC_WEIGHT_BLACK },
+		{ "heavy",		FC_WEIGHT_HEAVY },
+	    };
+#define NUM_PS_WEIGHTS	(sizeof (ps_weights) / sizeof (ps_weights[0]))
+	    int	w;
+	    for (w = 0; w < NUM_PS_WEIGHTS; w++)
+		if (!FcStrCmpIgnoreCase ((FcChar8 *) ps_weights[w].name,
+					 (FcChar8 *) psfontinfo.weight))
+		{
+		    weight = ps_weights[w].value;
+		    break;
+		}
 	}
      
 #if 0
@@ -808,9 +774,9 @@
 	 * Don't bother with italic_angle; FreeType already extracts that
 	 * information for us and sticks it into style_flags
 	 */
-        if (psfontinfo.italic_angle)
+        if (psfontinfo.italic_angle < 0) 
             slant = FC_SLANT_ITALIC; 
-        else
+        else if (psfontinfo.italic_angle >= 0) 
             slant = FC_SLANT_ROMAN; 
 #endif
 
@@ -835,6 +801,7 @@
 
     if (width == -1)
     {
+	BDF_PropertyRec prop;
 	if (MY_Get_BDF_Property(face, "RELATIVE_SETWIDTH", &prop) == 0 &&
 	    (prop.type == BDF_PROPERTY_TYPE_INTEGER ||
 	     prop.type == BDF_PROPERTY_TYPE_CARDINAL))
@@ -857,60 +824,33 @@
 	    case 9: width = FC_WIDTH_ULTRAEXPANDED; break;
 	    }
 	}
-	if (width == -1 &&
-	    MY_Get_BDF_Property (face, "SETWIDTH_NAME", &prop) == 0 &&
-	    prop.type == BDF_PROPERTY_TYPE_ATOM)
+	else if (MY_Get_BDF_Property (face, "SETWIDTH_NAME", &prop) == 0 &&
+		 prop.type == BDF_PROPERTY_TYPE_ATOM)
 	{
-	    width = FcIsWidth (prop.u.atom);
+	    static struct {
+		FcChar8	    *width_name;
+		int	    width;
+	    } FcSetWidths[] = {
+		{ "Condensed",	    FC_WIDTH_CONDENSED },
+		{ "SemiCondensed",  FC_WIDTH_SEMICONDENSED },
+		{ "Normal",	    FC_WIDTH_NORMAL },
+	    };
+	    int	i;
+
 	    if (FcDebug () & FC_DBG_SCANV)
-		printf ("\tsetwidth %s maps to %d\n", prop.u.atom, width);
+		printf ("\nsetwidth: %s\n", prop.u.atom);
+	    for (i = 0; i < sizeof (FcSetWidths) / sizeof (FcSetWidths[0]); i++)
+		if (!FcStrCmpIgnoreCase ((FcChar8 *) prop.u.atom,
+					 FcSetWidths[i].width_name))
+		{
+		    width = FcSetWidths[i].width;
+		    break;
+		}
 	}
     }
 
 #endif
 
-    /*
-     * Look for weight, width and slant names in the style value
-     */
-    if (style)
-    {
-	if (weight == -1)
-	{
-	    weight = FcContainsWeight (style);
-	    if (FcDebug() & FC_DBG_SCANV)
-		printf ("\tStyle %s maps to weight %d\n", style, weight);
-	}
-	if (width == -1)
-	{
-	    width = FcContainsWidth (style);
-	    if (FcDebug() & FC_DBG_SCANV)
-		printf ("\tStyle %s maps to width %d\n", style, width);
-	}
-	if (slant == -1)
-	{
-	    slant = FcContainsSlant (style);
-	    if (FcDebug() & FC_DBG_SCANV)
-		printf ("\tStyle %s maps to slant %d\n", style, slant);
-	}
-    }
-    /*
-     * Pull default values from the FreeType flags if more
-     * specific values not found above
-     */
-    if (slant == -1)
-    {
-	slant = FC_SLANT_ROMAN;
-	if (face->style_flags & FT_STYLE_FLAG_ITALIC)
-	    slant = FC_SLANT_ITALIC;
-    }
-
-    if (weight == -1)
-    {
-	weight = FC_WEIGHT_MEDIUM;
-	if (face->style_flags & FT_STYLE_FLAG_BOLD)
-	    weight = FC_WEIGHT_BOLD;
-    }
-
     if (!FcPatternAddInteger (pat, FC_SLANT, slant))
 	goto bail1;
 
@@ -934,20 +874,6 @@
     if (!cs)
 	goto bail1;
 
-#ifdef USE_FTBDF
-    /* For PCF fonts, override the computed spacing with the one from
-       the property */
-    if(MY_Get_BDF_Property(face, "SPACING", &prop) == 0 &&
-       prop.type == BDF_PROPERTY_TYPE_ATOM) {
-        if(strcmp(prop.u.atom, "c") || strcmp(prop.u.atom, "C"))
-            spacing = FC_CHARCELL;
-        else if(strcmp(prop.u.atom, "m") || strcmp(prop.u.atom, "M"))
-            spacing = FC_MONO;
-        else if(strcmp(prop.u.atom, "p") || strcmp(prop.u.atom, "P"))
-            spacing = FC_PROPORTIONAL;
-    }
-#endif
-
     /*
      * Skip over PCF fonts that have no encoded characters; they're
      * usually just Unicode fonts transcoded to some legacy encoding
@@ -966,17 +892,17 @@
 	goto bail2;
 
     if (!FcPatternAddLangSet (pat, FC_LANG, ls))
-    {
-	FcLangSetDestroy (ls);
 	goto bail2;
-    }
-
-    FcLangSetDestroy (ls);
 
     if (spacing != FC_PROPORTIONAL)
 	if (!FcPatternAddInteger (pat, FC_SPACING, spacing))
 	    goto bail2;
 
+    /*
+     * Drop our reference to the charset
+     */
+    FcCharSetDestroy (cs);
+    
     if (!(face->face_flags & FT_FACE_FLAG_SCALABLE))
     {
 	for (i = 0; i < face->num_fixed_sizes; i++)
@@ -985,63 +911,8 @@
 		goto bail1;
 	if (!FcPatternAddBool (pat, FC_ANTIALIAS, FcFalse))
 	    goto bail1;
-#ifdef USE_FTBDF
-        if(face->num_fixed_sizes == 1) {
-            int rc;
-            int value;
-            BDF_PropertyRec prop;
-
-            rc = MY_Get_BDF_Property(face, "PIXEL_SIZE", &prop);
-            if(rc == 0 && prop.type == BDF_PROPERTY_TYPE_INTEGER)
-                value = prop.u.integer;
-            else if(rc == 0 && prop.type == BDF_PROPERTY_TYPE_CARDINAL)
-                value = prop.u.cardinal;
-            else
-                goto nevermind;
-            if(value != face->available_sizes[0].height)
-                /* ``impossible'' */
-                goto nevermind;
-
-            rc = MY_Get_BDF_Property(face, "POINT_SIZE", &prop);
-            if(rc == 0 && prop.type == BDF_PROPERTY_TYPE_INTEGER)
-                value = prop.u.integer;
-            else if(rc == 0 && prop.type == BDF_PROPERTY_TYPE_CARDINAL)
-                value = prop.u.cardinal;
-            else
-                goto nevermind;
-            if(!FcPatternAddDouble(pat, FC_SIZE, value / 10.0))
-                goto nevermind;
-
-            rc = MY_Get_BDF_Property(face, "RESOLUTION_Y", &prop);
-            if(rc == 0 && prop.type == BDF_PROPERTY_TYPE_INTEGER)
-                value = prop.u.integer;
-            else if(rc == 0 && prop.type == BDF_PROPERTY_TYPE_CARDINAL)
-                value = prop.u.cardinal;
-            else
-                goto nevermind;
-            if(!FcPatternAddDouble(pat, FC_DPI, (double)value))
-                goto nevermind;
-
-        }
-    nevermind:
-        ;
-#endif
     }
 
-    /*
-     * Drop our reference to the charset
-     */
-    FcCharSetDestroy (cs);
-    
-    /*
-     * Deallocate family/style values
-     */
-    
-    if (family_allocated)
-	free (family);
-    if (style_allocated)
-	free (style);
-    
     FT_Done_Face (face);
     FT_Done_FreeType (ftLibrary);
     return pat;
@@ -1050,10 +921,6 @@
     FcCharSetDestroy (cs);
 bail1:
     FcPatternDestroy (pat);
-    if (family_allocated)
-	free (family);
-    if (style_allocated)
-	free (style);
 bail0:
     FT_Done_Face (face);
 bail:
@@ -1596,107 +1463,6 @@
     return 0;
 }
 
-#include "../fc-glyphname/fcglyphname.h"
-
-static FcChar32
-FcHashGlyphName (const FcChar8 *name)
-{
-    FcChar32	h = 0;
-    FcChar8	c;
-
-    while ((c = *name++))
-    {
-	h = ((h << 1) | (h >> 31)) ^ c;
-    }
-    return h;
-}
-
-/*
- * Use Type1 glyph names for fonts which have reliable names
- * and which export an Adobe Custom mapping
- */
-static FcBool
-FcFreeTypeUseNames (FT_Face face)
-{
-    FT_Int  map;
-    
-    if (!FT_Has_PS_Glyph_Names (face))
-	return FcFalse;
-    for (map = 0; map < face->num_charmaps; map++)
-	if (face->charmaps[map]->encoding == ft_encoding_adobe_custom)
-	    return FcTrue;
-    return FcFalse;
-}
-
-static FcChar8 *
-FcUcs4ToGlyphName (FcChar32 ucs4)
-{
-    int		i = (int) (ucs4 % FC_GLYPHNAME_HASH);
-    int		r = 0;
-    FcGlyphName	*gn;
-
-    while ((gn = ucs_to_name[i]))
-    {
-	if (gn->ucs == ucs4)
-	    return gn->name;
-	if (!r) 
-	{
-	    r = (int) (ucs4 % FC_GLYPHNAME_REHASH);
-	    if (!r)
-		r = 1;
-	}
-	i += r;
-	if (i >= FC_GLYPHNAME_HASH)
-	    i -= FC_GLYPHNAME_HASH;
-    }
-    return 0;
-}
-
-static FcChar32
-FcGlyphNameToUcs4 (FcChar8 *name)
-{
-    FcChar32	h = FcHashGlyphName (name);
-    int		i = (int) (h % FC_GLYPHNAME_HASH);
-    int		r = 0;
-    FcGlyphName	*gn;
-
-    while ((gn = name_to_ucs[i]))
-    {
-	if (!strcmp ((char *) name, (char *) gn->name))
-	    return gn->ucs;
-	if (!r) 
-	{
-	    r = (int) (h % FC_GLYPHNAME_REHASH);
-	    if (!r)
-		r = 1;
-	}
-	i += r;
-	if (i >= FC_GLYPHNAME_HASH)
-	    i -= FC_GLYPHNAME_HASH;
-    }
-    return 0xffff;
-}
-
-/*
- * Search through a font for a glyph by name.  This is
- * currently a linear search as there doesn't appear to be
- * any defined order within the font
- */
-static FT_UInt
-FcFreeTypeGlyphNameIndex (FT_Face face, FcChar8 *name)
-{
-    FT_UInt gindex;
-    FcChar8 name_buf[FC_GLYPHNAME_MAXLEN + 2];
-
-    for (gindex = 0; gindex < face->num_glyphs; gindex++)
-    {
-	if (FT_Get_Glyph_Name (face, gindex, name_buf, FC_GLYPHNAME_MAXLEN+1) == 0)
-	    if (!strcmp ((char *) name, (char *) name_buf))
-		return gindex;
-    }
-    return 0;
-}
-
 /*
  * Map a UCS4 glyph to a glyph index.  Use all available encoding
  * tables to try and find one that works.  This information is expected
@@ -1743,19 +1509,6 @@
 	if (glyphindex)
 	    return glyphindex;
     }
-    /*
-     * Check postscript name table if present
-     */
-    if (FcFreeTypeUseNames (face))
-    {
-	FcChar8	*name = FcUcs4ToGlyphName (ucs4);
-	if (name)
-	{
-	    glyphindex = FcFreeTypeGlyphNameIndex (face, name);
-	    if (glyphindex)
-		return glyphindex;
-	}
-    }
     return 0;
 }
 
@@ -1764,7 +1517,7 @@
 		      FT_UInt glyph, FcBlanks *blanks,
 		      FT_Pos *advance)
 {
-    FT_Int	    load_flags = FT_LOAD_IGNORE_GLOBAL_ADVANCE_WIDTH | FT_LOAD_NO_SCALE | FT_LOAD_NO_HINTING;
+    FT_Int	    load_flags = FT_LOAD_NO_SCALE | FT_LOAD_NO_HINTING;
     FT_GlyphSlot    slot;
     
     /*
@@ -1835,9 +1588,6 @@
     if (!fcs)
 	goto bail0;
     
-#ifdef CHECK
-    printf ("Family %s style %s\n", face->family_name, face->style_name);
-#endif
     for (o = 0; o < NUM_DECODE; o++)
     {
 	if (FT_Select_Charmap (face, fcFontDecoders[o].encoding) != 0)
@@ -1945,54 +1695,15 @@
 #endif
 	}
     }
-    /*
-     * Add mapping from PS glyph names if available
-     */
-    if (FcFreeTypeUseNames (face))
-    {
-	FcChar8 name_buf[FC_GLYPHNAME_MAXLEN + 2];
-
-	for (glyph = 0; glyph < face->num_glyphs; glyph++)
-	{
-	    if (FT_Get_Glyph_Name (face, glyph, name_buf, FC_GLYPHNAME_MAXLEN+1) == 0)
-	    {
-		ucs4 = FcGlyphNameToUcs4 (name_buf);
-		if (ucs4 != 0xffff && 
-		    FcFreeTypeCheckGlyph (face, ucs4, glyph, blanks, &advance))
-		{
-		    if (!has_advance)
-		    {
-			has_advance = FcTrue;
-			all_advance = advance;
-		    }
-		    else if (advance != all_advance)
-			fixed_advance = FcFalse;
-		    leaf = FcCharSetFindLeafCreate (fcs, ucs4);
-		    if (!leaf)
-			goto bail1;
-		    leaf->map[(ucs4 & 0xff) >> 5] |= (1 << (ucs4 & 0x1f));
-#ifdef CHECK
-		    if (ucs4 > font_max)
-			font_max = ucs4;
-#endif
-		}
-	    }
-	}
-    }
 #ifdef CHECK
     printf ("%d glyphs %d encoded\n", (int) face->num_glyphs, FcCharSetCount (fcs));
     for (ucs4 = 0; ucs4 <= font_max; ucs4++)
     {
-	FcBool	has_char = (glyph = FcFreeTypeCharIndex (face, ucs4)) != 0;
+	FcBool	has_char = FcFreeTypeCharIndex (face, ucs4) != 0;
 	FcBool	has_bit = FcCharSetHasChar (fcs, ucs4);
 
 	if (has_char && !has_bit)
-	{
-	    if (!FcFreeTypeCheckGlyph (face, ucs4, glyph, blanks, &advance))
-		printf ("Bitmap missing broken char 0x%x\n", ucs4);
-	    else
-		printf ("Bitmap missing char 0x%x\n", ucs4);
-	}
+	    printf ("Bitmap missing char 0x%x\n", ucs4);
 	else if (!has_char && has_bit)
 	    printf ("Bitmap extra char 0x%x\n", ucs4);
     }
