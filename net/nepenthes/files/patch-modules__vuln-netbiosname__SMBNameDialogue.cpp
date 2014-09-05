--- modules/vuln-netbiosname/SMBNameDialogue.cpp.orig
+++ modules/vuln-netbiosname/SMBNameDialogue.cpp
@@ -27,7 +27,8 @@
 
  /* $Id: SMBNameDialogue.cpp 836 2007-02-06 15:16:50Z common $ */
 
-#include <ctype.h>
+#include <cctype>
+#include <cstring>
 
 #include "SMBNameDialogue.hpp"
 #include "vuln-netbiosname.hpp"
