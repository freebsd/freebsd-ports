
$FreeBSD$

--- src/mozilla/TOCProtocolHandler.cpp	2001/10/23 11:27:00	1.1
+++ src/mozilla/TOCProtocolHandler.cpp	2001/10/23 11:27:21
@@ -21,17 +21,7 @@
 #include "outputbuffer.h"
 
 #include <algorithm>
-#if (GCC_VERSION < VERSION2(3,0))
-
-#ifndef STRING_HEADER
-#define STRING_HEADER <string>
-#endif
-
-#include STRING_HEADER
-
-#else
-#include <string>
-#endif
+#include <g++/string>
 
 #include <list>
 #include <dirent.h>
