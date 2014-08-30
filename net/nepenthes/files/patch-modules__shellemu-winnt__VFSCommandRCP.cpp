--- modules/shellemu-winnt/VFSCommandRCP.cpp.orig
+++ modules/shellemu-winnt/VFSCommandRCP.cpp
@@ -27,6 +27,8 @@
 
 /* $Id: VFSCommandRCP.cpp 550 2006-05-04 10:25:35Z common $ */
  
+#include <cstdio>
+#include <cstring>
 #include "VFSCommandRCP.hpp"
 #include "VFSNode.hpp"
 #include "VFSDir.hpp"
