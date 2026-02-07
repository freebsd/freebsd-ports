--- core/DesktopEditor/raster/Metafile/Wmf/WmfObjects.h.orig	2021-09-30 12:13:32 UTC
+++ core/DesktopEditor/raster/Metafile/Wmf/WmfObjects.h
@@ -37,7 +37,7 @@
 
 #include "WmfTypes.h"
 
-#ifdef __linux__
+#ifdef __linux__ || __FreeBSD__
     #include <string.h> //memset oO
 #endif
 namespace MetaFile
