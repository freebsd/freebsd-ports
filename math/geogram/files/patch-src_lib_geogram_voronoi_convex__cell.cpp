--- src/lib/geogram/voronoi/convex_cell.cpp.orig	2024-06-14 05:04:18 UTC
+++ src/lib/geogram/voronoi/convex_cell.cpp
@@ -274,7 +274,6 @@ namespace VBW {
     /***********************************************************************/
 
     void ConvexCell::save(const std::string& filename, double shrink) const {
-	std::cerr << "====> Saving " << filename << std::endl;	
 	std::ofstream out(filename.c_str());
 	save(out, 1, shrink);
     }
