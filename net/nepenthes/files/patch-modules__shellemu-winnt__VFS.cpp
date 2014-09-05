--- modules/shellemu-winnt/VFS.cpp.orig
+++ modules/shellemu-winnt/VFS.cpp
@@ -21,7 +21,9 @@
  *******************************************************************************/
 
 
-#include <ctype.h>
+#include <cctype>
+#include <cstdio>
+#include <cstring>
 
 #include "VFS.hpp"
 #include "VFSNode.hpp"
