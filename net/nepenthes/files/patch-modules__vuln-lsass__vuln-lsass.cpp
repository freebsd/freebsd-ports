--- modules/vuln-lsass/vuln-lsass.cpp.orig
+++ modules/vuln-lsass/vuln-lsass.cpp
@@ -27,7 +27,8 @@
 
  /* $Id: vuln-lsass.cpp 550 2006-05-04 10:25:35Z common $ */
 
-#include <ctype.h>
+#include <cctype>
+#include <cstdlib>
 
 #include "vuln-lsass.hpp"
 #include "LSASSDialogue.hpp"
