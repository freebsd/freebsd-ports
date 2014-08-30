--- modules/vuln-wins/vuln-wins.cpp.orig
+++ modules/vuln-wins/vuln-wins.cpp
@@ -27,7 +27,8 @@
 
  /* $Id: vuln-wins.cpp 550 2006-05-04 10:25:35Z common $ */
 
-#include <ctype.h>
+#include <cctype>
+#include <cstdlib>
 
 #include "vuln-wins.hpp"
 
