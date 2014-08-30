--- modules/module-portwatch/module-portwatch.cpp.orig
+++ modules/module-portwatch/module-portwatch.cpp
@@ -27,7 +27,8 @@
 
  /* $Id: module-portwatch.cpp 550 2006-05-04 10:25:35Z common $ */
 
-#include <ctype.h>
+#include <cctype>
+#include <cstdlib>
 
 #include "module-portwatch.hpp"
 #include "WatchDialogue.hpp"
