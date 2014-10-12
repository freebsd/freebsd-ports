--- src/gshhs.cpp.orig	2014-10-11 19:11:00.000000000 +0200
+++ src/gshhs.cpp	2014-10-11 19:37:17.000000000 +0200
@@ -175,7 +175,7 @@
         double ss = h.south * GSHHS_SCL;
         double nn = h.north * GSHHS_SCL;
         char source = (src == 1) ? 'W' : 'C'; // Either WVS or CIA (WDBII) pedigree 
-        if ( river ) source = tolower( (int) source ); // Lower case c means river-lake 
+        if ( river ) source = std::tolower( (int) source ); // Lower case c means river-lake 
         int line = (h.area) ? 0 : 1; // Either Polygon (0) or Line (1) (if no area) 
 
 
