--- nepenthes-core/src/Utilities.cpp.orig
+++ nepenthes-core/src/Utilities.cpp
@@ -33,10 +33,12 @@
 #endif
 
 
-#include <string.h>
+#include <cstdio>
+#include <cstdlib>
+#include <cstring>
 #include <sys/types.h>
 #include <inttypes.h>
-#include <ctype.h>
+#include <cctype>
 
 #include "Utilities.hpp"
 #include "LogManager.hpp"
