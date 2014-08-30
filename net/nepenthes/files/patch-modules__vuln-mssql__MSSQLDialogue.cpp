--- modules/vuln-mssql/MSSQLDialogue.cpp.orig
+++ modules/vuln-mssql/MSSQLDialogue.cpp
@@ -27,7 +27,8 @@
 
  /* $Id: MSSQLDialogue.cpp 836 2007-02-06 15:16:50Z common $ */
 
-#include <ctype.h>
+#include <cctype>
+#include <cstring>
 
 #include "MSSQLDialogue.hpp"
 #include "vuln-mssql.hpp"
