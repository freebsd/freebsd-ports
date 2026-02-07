Fixes FreeBSD 10 build error:

QXPBlockParser.cpp:60:12: error: use of undeclared identifier 'abs'; did you mean 'fabs'?
--- src/lib/QXPBlockParser.cpp.orig	2018-02-07 14:08:00 UTC
+++ src/lib/QXPBlockParser.cpp
@@ -13,6 +13,7 @@
 #include <algorithm>
 #include <memory>
 #include <vector>
+#include <cstdlib>
 
 #include "QXPHeader.h"
 
