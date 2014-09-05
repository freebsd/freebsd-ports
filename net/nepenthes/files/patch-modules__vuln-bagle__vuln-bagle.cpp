--- modules/vuln-bagle/vuln-bagle.cpp.orig
+++ modules/vuln-bagle/vuln-bagle.cpp
@@ -27,7 +27,8 @@
 
  /* $Id: vuln-bagle.cpp 550 2006-05-04 10:25:35Z common $ */
 
-#include <ctype.h>
+#include <cctype>
+#include <cstdlib>
 
 #include "vuln-bagle.hpp"
 #include "BagleDialogue.hpp"
