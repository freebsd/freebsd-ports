--- modules/shellemu-winnt/VFSDir.cpp.orig
+++ modules/shellemu-winnt/VFSDir.cpp
@@ -28,6 +28,8 @@
 /* $Id: VFSDir.cpp 1947 2005-09-08 17:30:06Z common $ */
 
 
+#include <cstring>
+
 #include "VFSDir.hpp"
 #include "VFSFile.hpp"
 #include "LogManager.hpp"
