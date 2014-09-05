--- modules/vuln-asn1/SMBDialogue.cpp.orig
+++ modules/vuln-asn1/SMBDialogue.cpp
@@ -27,7 +27,8 @@
 
  /* $Id: SMBDialogue.cpp 836 2007-02-06 15:16:50Z common $ */
 
-#include <ctype.h>
+#include <cctype>
+#include <cstring>
 
 #include "SMBDialogue.hpp"
 #include "asn1-shellcodes.h"
