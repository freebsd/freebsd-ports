--- src/Writer.cpp.orig	2009-04-21 00:43:33.000000000 +0900
+++ src/Writer.cpp	2010-10-05 00:43:15.000000000 +0900
@@ -197,7 +197,8 @@
       width = NSAppUnitsToIntPixels(cutout.width, p2a);
       height = NSAppUnitsToIntPixels(cutout.height, p2a);
 
-      rv = presShell->RenderDocument(cutout, PR_FALSE, PR_TRUE,
+      rv = presShell->RenderDocument(cutout,
+                                     nsIPresShell::RENDER_IGNORE_VIEWPORT_SCROLLING,
                                      NS_RGB(255, 255, 255), context);
       if (NS_SUCCEEDED(rv)) {
         imgContext->DrawSurface(surface, gfxSize(width, height));
