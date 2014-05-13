CVE-2014-0210
CVE-2014-0211

--- src/fc/fsconvert.c.orig	2014-01-07 17:25:08.000000000 +0100
+++ src/fc/fsconvert.c	2014-05-13 18:14:43.000000000 +0200
@@ -118,6 +118,10 @@ _fs_convert_props(fsPropInfo *pi, fsProp
     for (i = 0; i < nprops; i++, dprop++, is_str++)
     {
 	memcpy(&local_off, off_adr, SIZEOF(fsPropOffset));
+	if ((local_off.name.position >= pi->data_len) ||
+		(local_off.name.length >
+		 (pi->data_len - local_off.name.position)))
+	    goto bail;
 	dprop->name = MakeAtom(&pdc[local_off.name.position],
 			       local_off.name.length, 1);
 	if (local_off.type != PropTypeString) {
@@ -125,10 +129,15 @@ _fs_convert_props(fsPropInfo *pi, fsProp
 	    dprop->value = local_off.value.position;
 	} else {
 	    *is_str = TRUE;
+	    if ((local_off.value.position >= pi->data_len) ||
+		(local_off.value.length >
+		 (pi->data_len - local_off.value.position)))
+		goto bail;
 	    dprop->value = (INT32) MakeAtom(&pdc[local_off.value.position],
 					    local_off.value.length, 1);
 	    if (dprop->value == BAD_RESOURCE)
 	    {
+	      bail:
 		free (pfi->props);
 		pfi->nprops = 0;
 		pfi->props = 0;
@@ -712,7 +721,12 @@ fs_alloc_glyphs (FontPtr pFont, int size
     FSGlyphPtr	glyphs;
     FSFontPtr	fsfont = (FSFontPtr) pFont->fontPrivate;
 
-    glyphs = malloc (sizeof (FSGlyphRec) + size);
+    if (size < (INT_MAX - sizeof (FSGlyphRec)))
+	glyphs = malloc (sizeof (FSGlyphRec) + size);
+    else
+	glyphs = NULL;
+    if (glyphs == NULL)
+	return NULL;
     glyphs->next = fsfont->glyphs;
     fsfont->glyphs = glyphs;
     return (pointer) (glyphs + 1);
