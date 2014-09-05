--- modules/vuln-mydoom/vuln-mydoom.cpp.orig
+++ modules/vuln-mydoom/vuln-mydoom.cpp
@@ -29,7 +29,8 @@
 
 
 
-#include <ctype.h>
+#include <cctype>
+#include <cstdlib>
 
 #include "vuln-mydoom.hpp"
 #include "MydoomDialogue.hpp"
