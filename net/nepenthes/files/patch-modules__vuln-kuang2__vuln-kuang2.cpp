--- modules/vuln-kuang2/vuln-kuang2.cpp.orig
+++ modules/vuln-kuang2/vuln-kuang2.cpp
@@ -27,7 +27,8 @@
 
  /* $Id: vuln-kuang2.cpp 550 2006-05-04 10:25:35Z common $ */
 
-#include <ctype.h>
+#include <cctype>
+#include <cstdlib>
 
 #include "vuln-kuang2.hpp"
 #include "Kuang2Dialogue.hpp"
