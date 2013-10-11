--- src/plotting_contour.cpp.orig	2013-09-17 22:13:27.000000000 +0200
+++ src/plotting_contour.cpp	2013-10-11 10:35:22.000000000 +0200
@@ -728,7 +728,7 @@
               actStream->pat(1,&ori,&spa);
 
               if (docolors) actStream->Color ( ( *colors )[i%colors->N_Elements ( )], decomposed, (PLINT)colorindex_table_0_color );
-              if (dothick) actStream->wid ( ( *thick )[i%thick->N_Elements ( )]);
+              if (dothick) actStream->width ( ( *thick )[i%thick->N_Elements ( )]);
               if (dostyle) gdlLineStyle(actStream, ( *style )[i%style->N_Elements ( )]);
               actStream->shade( map, xEl, yEl, isLog?doIt:NULL, xStart, xEnd, yStart, yEnd,
               clevel[i], clevel[i+1],
@@ -811,7 +811,7 @@
               actStream->stransform(gdl3dTo2dTransformContour, &Data3d);
             }
             if (docolors) actStream->Color ( ( *colors )[i%colors->N_Elements ( )], decomposed, 2);
-            if (dothick) actStream->wid ( ( *thick )[i%thick->N_Elements ( )]);
+            if (dothick) actStream->width ( ( *thick )[i%thick->N_Elements ( )]);
             if (dostyle) gdlLineStyle(actStream, ( *style )[i%style->N_Elements ( )]);
             if (dolabels) actStream->setcontlabelparam ( LABELOFFSET, (PLFLT) label_size, LABELSPACING,
                                                         (PLINT)(*labels)[i%labels->N_Elements()] );
