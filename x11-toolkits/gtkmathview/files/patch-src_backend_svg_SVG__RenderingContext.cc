SVG_RenderingContext.cc:67:25: error: invalid suffix on literal; C++11 requires a
      space between literal and identifier [-Wreserved-user-defined-literal]
  metadata("Created by "PACKAGE" version "VERSION);
                        ^

--- src/backend/svg/SVG_RenderingContext.cc.orig	2018-08-25 14:04:53 UTC
+++ src/backend/svg/SVG_RenderingContext.cc
@@ -64,7 +64,7 @@ void
 SVG_RenderingContext::documentStart(const BoundingBox& bbox)
 {
   beginDocument(bbox);
-  metadata("Created by "PACKAGE" version "VERSION);
+  metadata("Created by " PACKAGE " version " VERSION);
 }
 
 void
