--- ./classes/include/ArtsFileUtil.hh.orig	Mon Oct  2 13:05:15 2000
+++ ./classes/include/ArtsFileUtil.hh	Wed Sep 25 16:38:10 2002
@@ -43,9 +43,16 @@
 #ifndef _ARTSFILEUTIL_HH_
 #define _ARTSFILEUTIL_HH_
 
+#include "artslocal.h"
+
 #include <string>
 #include <vector>
-#include <fstream.h>
+
+#ifdef HAVE_FSTREAM
+# include <fstream> 
+#else
+# include <fstream.h>
+#endif
 
 #include "ArtsProtocolTableAggregatorMap.hh"
 #include "ArtsInterfaceMatrixAggregatorMap.hh"
