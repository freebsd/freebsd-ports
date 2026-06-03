--- core/DesktopEditor/raster/heif/heif.h.orig	2025-10-13 15:33:25 UTC
+++ core/DesktopEditor/raster/heif/heif.h
@@ -1,5 +1,5 @@
 #include "../BgraFrame.h"
-#include "../../Common/3dParty/heif/libheif/libheif/api/libheif/heif.h"
+#include <heif.h>
 #include "../../UnicodeConverter/UnicodeConverter.h"
 
 namespace NSHeif {
