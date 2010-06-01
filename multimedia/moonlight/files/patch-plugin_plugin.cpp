
$FreeBSD$

--- plugin/plugin.cpp.orig
+++ plugin/plugin.cpp
@@ -17,6 +17,7 @@
 #include <fcntl.h>
 #include <stdlib.h>
 #include <dlfcn.h>
+#include <unistd.h>
 
 #include "plugin.h"
 #include "plugin-spinner.h"
