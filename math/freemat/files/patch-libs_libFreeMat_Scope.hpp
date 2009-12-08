--- libs/libFreeMat/Scope.hpp.orig	2009-10-08 09:40:36.000000000 +0700
+++ libs/libFreeMat/Scope.hpp	2009-10-08 09:40:55.000000000 +0700
@@ -25,6 +25,7 @@
  */
 #include <string>
 #include <QMutex>
+#include <algorithm>
 
 #include "Array.hpp"
 #include "SymbolTable.hpp"
