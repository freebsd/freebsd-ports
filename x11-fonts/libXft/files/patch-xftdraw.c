--- xftdraw.c	2002/10/11 17:53:02	1.25
+++ xftdraw.c	2003/04/03 22:25:50	1.26
@@ -724,7 +724,7 @@ XftDrawGlyphFontSpec (XftDraw			*draw,
 	    {
 		XftGlyphFontSpecRender (draw->dpy, _XftDrawOp (draw, color),
 					src, draw->render.pict,
-					0, 0, glyphs, i - start);
+					0, 0, glyphs + start , i - start);
 	    }
 	}
 	else
@@ -732,7 +732,7 @@ XftDrawGlyphFontSpec (XftDraw			*draw,
 	    while (i < len && !((XftFontInt *) glyphs[i].font)->format)
 		i++;
 	    if (_XftDrawCorePrepare (draw, color))
-		XftGlyphFontSpecCore (draw, color, glyphs, len);
+		XftGlyphFontSpecCore (draw, color, glyphs + start, i - start);
 	}
     }
 }
