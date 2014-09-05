--- texk/dvisvgm/dvisvgm-1.6/src/FontEncoding.cpp.orig	2014-01-13 17:24:56.000000000 +0900
+++ texk/dvisvgm/dvisvgm-1.6/src/FontEncoding.cpp	2014-08-20 23:41:52.000000000 +0900
@@ -19,6 +19,7 @@
 *************************************************************************/
 
 #include <config.h>
+#include <sys/time.h>
 #include "CMap.h"
 #include "CMapManager.h"
 #include "EncFile.h"
