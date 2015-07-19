--- texk/dvisvgm/dvisvgm-1.9.2/src/FontEncoding.cpp.orig	2015-03-02 08:48:21 UTC
+++ texk/dvisvgm/dvisvgm-1.9.2/src/FontEncoding.cpp
@@ -19,6 +19,7 @@
 *************************************************************************/
 
 #include <config.h>
+#include <sys/time.h>
 #include "CMap.h"
 #include "CMapManager.h"
 #include "EncFile.h"
