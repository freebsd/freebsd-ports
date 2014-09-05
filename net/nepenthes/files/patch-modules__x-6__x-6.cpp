--- modules/x-6/x-6.cpp.orig
+++ modules/x-6/x-6.cpp
@@ -27,7 +27,9 @@
 
  /* $Id: x-6.cpp 343 2006-02-20 17:11:57Z common $ */
 
-#include <ctype.h>
+#include <cctype>
+#include <cstdlib>
+#include <cstring>
 
 #include "x-6.hpp"
 
