--- xftfreetype.c.orig	Fri Mar 19 04:11:09 2004
+++ xftfreetype.c	Fri Mar 19 04:11:30 2004
@@ -192,53 +192,9 @@
 	if (XftDebug() & XFT_DBG_GLYPH)
 	    printf ("Set face size to %dx%d (%dx%d)\n", 
 		    (int) (xsize >> 6), (int) (ysize >> 6), (int) xsize, (int) ysize);
-	/*
-	 * Bitmap only faces must match exactly, so find the closest
-	 * one (height dominant search)
-	 */
-	if (!(face->face_flags & FT_FACE_FLAG_SCALABLE))
-	{
-	    FT_Short    width = xsize >> 6;
-	    FT_Short    height = ysize >> 6;
-	    int		i, best = -1;
-
-#define xft_abs(a)	((a) < 0 ? -(a) : (a))
-#define dist(a,b)	(xft_abs((a)-(b)))
-
-#if !HAVE_FT_BITMAP_SIZE_Y_PPEM
-#define y_ppem height
-#define x_ppem width
-#endif
-	    for (i = 0; i < face->num_fixed_sizes; i++)
-	    {
-		if (best == -1 ||
-		    dist (height, face->available_sizes[i].y_ppem >> 6) <
-		    dist (height, face->available_sizes[best].y_ppem >> 6) ||
-		    (dist (height, face->available_sizes[i].y_ppem >> 6) ==
-		     dist (height, face->available_sizes[best].y_ppem >> 6) &&
-		     dist (width, face->available_sizes[i].x_ppem >> 6) <
-		     dist (width, face->available_sizes[best].x_ppem >> 6)))
-		{
-		    best = i;
-		}
-	    }
-	    if (FT_Set_Char_Size (face, face->available_sizes[best].x_ppem,
-				  face->available_sizes[best].y_ppem, 0, 0) != 0)
-	    {
-		return False;
-	    }
-#if !HAVE_FT_BITMAP_SIZE_Y_PPEM
-#undef y_ppem
-#undef x_ppem
-#endif
-	}
-	else
-    	{
 	    if (FT_Set_Char_Size (face, xsize, ysize, 0, 0))
-	    {
 		return False;
-	    }
-	}
+
 	f->xsize = xsize;
 	f->ysize = ysize;
     }
