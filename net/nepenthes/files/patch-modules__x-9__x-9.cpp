--- modules/x-9/x-9.cpp.orig
+++ modules/x-9/x-9.cpp
@@ -27,7 +27,8 @@
 
  /* $Id: x-9.cpp 658 2006-10-08 15:04:17Z common $ */
 
-#include <ctype.h>
+#include <cctype>
+#include <cstring>
 
 #include "x-9.hpp"
 
