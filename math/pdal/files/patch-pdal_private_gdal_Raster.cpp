--- pdal/private/gdal/Raster.cpp.orig	2026-10-16 09:55:00 UTC
+++ pdal/private/gdal/Raster.cpp
@@ -696,7 +696,7 @@ MetadataNode Raster::getMetadata(std::string domain) c
 
 MetadataNode Raster::getMetadata(std::string domain) const
 {
-    char **papszMetadata = NULL;
+    CSLConstList papszMetadata = NULL;
 
     MetadataNode output("raster");
 
