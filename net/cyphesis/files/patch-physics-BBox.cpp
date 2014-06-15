--- physics/BBox.cpp.orig	2014-06-15 17:53:14.000000000 +0200
+++ physics/BBox.cpp	2014-06-15 17:51:40.000000000 +0200
@@ -19,7 +19,7 @@
 #include "BBox.h"
 
 #include "common/const.h"
-
+#include <algorithm>
 #include <wfmath/axisbox.h>
 #include <wfmath/point.h>
 
