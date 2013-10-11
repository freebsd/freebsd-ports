--- src/plotting_xyouts.cpp.orig	2013-10-11 11:26:06.000000000 +0200
+++ src/plotting_xyouts.cpp	2013-10-11 11:27:24.000000000 +0200
@@ -339,7 +339,7 @@
         //plot!
         if (docharsize) actStream->sizeChar(( *size )[i%size->N_Elements ( )]);
         if (docolor) actStream->Color ( ( *color )[i%color->N_Elements ( )], decomposed, 2);
-        if (docharthick) actStream->wid ( ( *charthick )[i%charthick->N_Elements ( )]);
+        if (docharthick) actStream->width ( ( *charthick )[i%charthick->N_Elements ( )]);
         //orientation word is not orientation page depending on axes increment direction [0..1] vs. [1..0]
         PLFLT oriD=(( *orientation )[i%orientation->N_Elements ( )]); //ori DEVICE
         PLFLT oriW=oriD; //ori WORLD
