--- modules/vuln-iis/vuln-iis.cpp.orig
+++ modules/vuln-iis/vuln-iis.cpp
@@ -27,7 +27,8 @@
 
  /* $Id: vuln-iis.cpp 550 2006-05-04 10:25:35Z common $ */
 
-#include <ctype.h>
+#include <cctype>
+#include <cstdlib>
 
 #include "vuln-iis.hpp"
 #include "IISDialogue.hpp"
