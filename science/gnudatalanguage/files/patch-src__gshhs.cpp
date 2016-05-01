--- src/gshhs.cpp.orig	2016-04-29 17:03:25 UTC
+++ src/gshhs.cpp
@@ -175,7 +175,7 @@ private:
         double ss = h.south * GSHHS_SCL;
         double nn = h.north * GSHHS_SCL;
         char source = (src == 1) ? 'W' : 'C'; // Either WVS or CIA (WDBII) pedigree 
-        if ( river ) source = tolower( (int) source ); // Lower case c means river-lake 
+        if ( river ) source = std::tolower( (int) source ); // Lower case c means river-lake 
         int line = (h.area) ? 0 : 1; // Either Polygon (0) or Line (1) (if no area) 
 
 
