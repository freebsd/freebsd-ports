--- modules/vuln-netdde/NETDDEDialogue.cpp.orig
+++ modules/vuln-netdde/NETDDEDialogue.cpp
@@ -27,7 +27,8 @@
 
  /* $Id: NETDDEDialogue.cpp 836 2007-02-06 15:16:50Z common $ */
 
-#include <ctype.h>
+#include <cctype>
+#include <cstring>
 
 #include "NETDDEDialogue.hpp"
 #include "vuln-netdde.hpp"
