--- modules/vuln-optix/vuln-optix.cpp.orig
+++ modules/vuln-optix/vuln-optix.cpp
@@ -29,7 +29,8 @@
 
 
 
-#include <ctype.h>
+#include <cctype>
+#include <cstdlib>
 
 #include "vuln-optix.hpp"
 #include "OPTIXShellDialogue.hpp"
