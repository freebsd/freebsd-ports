--- libs/libFreeMat/Array.cpp.orig	2009-10-08 09:37:54.000000000 +0700
+++ libs/libFreeMat/Array.cpp	2009-10-08 09:38:20.000000000 +0700
@@ -27,6 +27,8 @@
 #include <math.h>
 #include <stdio.h>
 #include <set>
+#include <algorithm>
+#include <functional>
 
 #include "FunctionDef.hpp"
 #include "NumericArray.hpp"
