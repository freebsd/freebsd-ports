--- modules/vuln-msdtc/vuln-msdtc.cpp.orig
+++ modules/vuln-msdtc/vuln-msdtc.cpp
@@ -27,7 +27,8 @@
 
  /* $Id: vuln-msdtc.cpp 550 2006-05-04 10:25:35Z common $ */
 
-#include <ctype.h>
+#include <cctype>
+#include <cstdlib>
 
 #include "vuln-msdtc.hpp"
 #include "MSDTCDialogue.hpp"
