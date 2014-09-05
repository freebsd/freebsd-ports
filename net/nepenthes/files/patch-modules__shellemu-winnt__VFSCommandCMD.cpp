--- modules/shellemu-winnt/VFSCommandCMD.cpp.orig
+++ modules/shellemu-winnt/VFSCommandCMD.cpp
@@ -27,6 +27,8 @@
 
 /* $Id: VFSCommandCMD.cpp 1956 2005-09-10 15:32:08Z common $ */
  
+#include <cstring>
+
 #include "VFSCommandCMD.hpp"
 #include "VFSNode.hpp"
 #include "VFSDir.hpp"
