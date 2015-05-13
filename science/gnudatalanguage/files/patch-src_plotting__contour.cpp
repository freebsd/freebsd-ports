--- src/plotting_contour.cpp.orig	2015-04-22 19:37:22 UTC
+++ src/plotting_contour.cpp
@@ -789,8 +789,8 @@ namespace lib
               1, value, 
               static_cast<PLFLT>(( *thick )[i%thick->N_Elements()]),
               0,0,0,0,
-              (plstream::fill), (oneDim),
-              (oneDim)?(plstream::tr1):(plstream::tr2), (oneDim)?(void *)&cgrid1:(void *)&cgrid2);
+              (plcallback::fill), (oneDim),
+              (oneDim)?(plcallback::tr1):(plcallback::tr2), (oneDim)?(void *)&cgrid1:(void *)&cgrid2);
             }
             actStream->psty(0);
 //            if (docolors) gdlSetGraphicsForegroundColorFromKw( e, actStream );
@@ -808,8 +808,8 @@ namespace lib
               clevel[i], maxmax, 
               1,value,
               0,0,0,0,0,
-                  plstream::fill, (oneDim), //Onedim is accelerator since rectangles are kept rectangles see plplot doc
-                  (oneDim)?(plstream::tr1):(plstream::tr2), (oneDim)?(void *)&cgrid1:(void *)&cgrid2);
+                  plcallback::fill, (oneDim), //Onedim is accelerator since rectangles are kept rectangles see plplot doc
+                  (oneDim)?(plcallback::tr1):(plcallback::tr2), (oneDim)?(void *)&cgrid1:(void *)&cgrid2);
                 }
           } else {  //every other case of fill 
             // note that plshades is not protected against 1 level (color formula is
@@ -818,8 +818,8 @@ namespace lib
             if (nlevel>2 && !(docolors)) { //acceleration with shades when no c_colors are given. use continuous table1, decomposed or not.
               //acceleration is most sensible when a (x,y) transform (rotate, stretch) is in place since plplot does not recompute the map.
               actStream->shades( map, xEl, yEl, isLog?doIt:NULL, xStart, xEnd, yStart, yEnd,
-                                clevel, nlevel, 1, 0, 0, plstream::fill, (oneDim),
-                                (oneDim)?(plstream::tr1):(plstream::tr2),
+                                clevel, nlevel, 1, 0, 0, plcallback::fill, (oneDim),
+                                (oneDim)?(plcallback::tr1):(plcallback::tr2),
                                 (oneDim)?(void *)&cgrid1:(void *)&cgrid2);
             }
             else { //fill with colors defined with c_colors or n<=2
@@ -832,8 +832,8 @@ namespace lib
                 clevel[i], maxmax,
                 1,value,
                 0,0,0,0,0,
-                plstream::fill, (oneDim), //Onedim is accelerator since rectangles are kept rectangles see plplot doc
-                (oneDim)?(plstream::tr1):(plstream::tr2), (oneDim)?(void *)&cgrid1:(void *)&cgrid2);
+                plcallback::fill, (oneDim), //Onedim is accelerator since rectangles are kept rectangles see plplot doc
+                (oneDim)?(plcallback::tr1):(plcallback::tr2), (oneDim)?(void *)&cgrid1:(void *)&cgrid2);
               } else
 		        printf(" Problem, sorry! plplot doesn't like to FILL with a single level!");
             }
@@ -854,7 +854,7 @@ namespace lib
             if (doT3d) { //no label in T3D , bug in plplot...
               actStream->setcontlabelparam ( LABELOFFSET, (PLFLT) label_size, LABELSPACING, 0 );
               actStream->cont ( map, xEl, yEl, 1, xEl, 1, yEl, &( clevel[i] ), 1,
-                (oneDim)?(plstream::tr1):(plstream::tr2), (oneDim)?(void *)&cgrid1:(void *)&cgrid2);
+                (oneDim)?(plcallback::tr1):(plcallback::tr2), (oneDim)?(void *)&cgrid1:(void *)&cgrid2);
             } else {
               if (dolabels && i<labels->N_Elements()) 
               {
@@ -862,16 +862,16 @@ namespace lib
                                                               //else (lables thicker than contours) impossible with plplot...
                   actStream->setcontlabelparam ( LABELOFFSET, (PLFLT) label_size, LABELSPACING, 0 ); 
                   actStream->cont ( map, xEl, yEl, 1, xEl, 1, yEl, &( clevel[i] ), 1,
-                  (oneDim)?(plstream::tr1):(plstream::tr2), (oneDim)?(void *)&cgrid1:(void *)&cgrid2); //thick contours, no label
+                  (oneDim)?(plcallback::tr1):(plcallback::tr2), (oneDim)?(void *)&cgrid1:(void *)&cgrid2); //thick contours, no label
                   actStream->Thick(label_thick);
                 } 
                 actStream->setcontlabelparam ( LABELOFFSET, (PLFLT) label_size, LABELSPACING*sqrt(label_size),(PLINT)(*labels)[i] ); 
                 actStream->cont ( map, xEl, yEl, 1, xEl, 1, yEl, &( clevel[i] ), 1,
-                (oneDim)?(plstream::tr1):(plstream::tr2), (oneDim)?(void *)&cgrid1:(void *)&cgrid2);
+                (oneDim)?(plcallback::tr1):(plcallback::tr2), (oneDim)?(void *)&cgrid1:(void *)&cgrid2);
                 if (!dothick) gdlSetPenThickness(e, actStream);
               } else {
                 actStream->cont ( map, xEl, yEl, 1, xEl, 1, yEl, &( clevel[i] ), 1,
-                (oneDim)?(plstream::tr1):(plstream::tr2), (oneDim)?(void *)&cgrid1:(void *)&cgrid2);
+                (oneDim)?(plcallback::tr1):(plcallback::tr2), (oneDim)?(void *)&cgrid1:(void *)&cgrid2);
               }
             }
           }
