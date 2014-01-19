--- src/resource.cpp.orig
+++ src/resource.cpp
@@ -22,6 +22,7 @@
 #include "bbmail.h"
 #include "resource.h"
 #include "blackboxstyle.h"
+#include <cstdlib>
 
 Resource::Resource(ToolWindow *toolwindow, const std::string &rc_file):
 		BaseResource(*toolwindow, toolwindow->getCurrentScreen(), rc_file), 
