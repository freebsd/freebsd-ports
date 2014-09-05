--- modules/shellemu-winnt/VFSCommandFTP.cpp.orig
+++ modules/shellemu-winnt/VFSCommandFTP.cpp
@@ -27,7 +27,8 @@
 
 /* $Id: VFSCommandFTP.cpp 1410 2007-10-12 13:07:23Z common $ */
 
-#include <ctype.h>
+#include <cctype>
+#include <cstring>
  
 #include "VFSCommandFTP.hpp"
 #include "VFSNode.hpp"
