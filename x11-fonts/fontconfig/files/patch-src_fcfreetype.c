--- src/fcfreetype.c.orig	Fri Feb 28 10:44:26 2003
+++ src/fcfreetype.c	Fri Feb 28 10:44:41 2003
@@ -467,7 +467,7 @@
     if (!FcPatternAddString (pat, FC_SOURCE, (FcChar8 *) "FreeType"))
 	goto bail1;
 
-#if 1
+#if 0
     if ((face->face_flags & FT_FACE_FLAG_FIXED_WIDTH) != 0)
 	if (!FcPatternAddInteger (pat, FC_SPACING, FC_MONO))
 	    goto bail1;
