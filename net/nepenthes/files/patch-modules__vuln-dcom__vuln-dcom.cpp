--- modules/vuln-dcom/vuln-dcom.cpp.orig
+++ modules/vuln-dcom/vuln-dcom.cpp
@@ -28,7 +28,8 @@
  /* $Id: vuln-dcom.cpp 550 2006-05-04 10:25:35Z common $ */
 
 
-#include <ctype.h>
+#include <cctype>
+#include <cstdlib>
 
 #include "vuln-dcom.hpp"
 
