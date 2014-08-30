--- modules/vuln-dameware/vuln-dameware.cpp.orig
+++ modules/vuln-dameware/vuln-dameware.cpp
@@ -27,7 +27,8 @@
 
  /* $Id: vuln-dameware.cpp 550 2006-05-04 10:25:35Z common $ */
 
-#include <ctype.h>
+#include <cctype>
+#include <cstdlib>
 
 #include "vuln-dameware.hpp"
 #include "DWDialogue.hpp"
