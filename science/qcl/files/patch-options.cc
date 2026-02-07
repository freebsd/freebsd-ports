--- options.cc.orig
+++ options.cc
@@ -13,8 +13,9 @@
 ************************************************************************/
 
 
-#include <stdio.h>
-#include <time.h>
+#include <cstdio>
+#include <cstring>
+#include <ctime>
 
 #include "options.h"
 #include "error.h"
