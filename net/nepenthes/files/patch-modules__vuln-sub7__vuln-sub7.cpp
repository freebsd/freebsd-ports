--- modules/vuln-sub7/vuln-sub7.cpp.orig
+++ modules/vuln-sub7/vuln-sub7.cpp
@@ -27,7 +27,8 @@
 
  /* $Id: vuln-sub7.cpp 550 2006-05-04 10:25:35Z common $ */
 
-#include <ctype.h>
+#include <cctype>
+#include <cstdlib>
 
 #include "vuln-sub7.hpp"
 #include "SUB7Dialogue.hpp"
