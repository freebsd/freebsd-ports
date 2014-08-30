--- modules/vuln-asn1/IISDialogue.cpp.orig
+++ modules/vuln-asn1/IISDialogue.cpp
@@ -27,7 +27,8 @@
 
  /* $Id: IISDialogue.cpp 836 2007-02-06 15:16:50Z common $ */
 
-#include <ctype.h>
+#include <cctype>
+#include <cstring>
 
 #include "IISDialogue.hpp"
 
