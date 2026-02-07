--- ./core/DesktopEditor/raster/Metafile/Common/MetaFileUtils.h.orig	2023-10-30 16:47:10.672867000 +0100
+++ ./core/DesktopEditor/raster/Metafile/Common/MetaFileUtils.h	2023-10-30 16:47:42.379902000 +0100
@@ -953,7 +953,7 @@ namespace MetaFile
 			}
 			else
 			{
-				pRegion->shScanCount = NULL;
+				pRegion->shScanCount = 0;
 			}
 
 
