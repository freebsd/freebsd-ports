
$FreeBSD$

--- src/mozilla/TOCProtocolHandler.cpp	2001/10/08 16:33:57	1.1
+++ src/mozilla/TOCProtocolHandler.cpp	2001/10/08 16:34:17
@@ -21,11 +21,7 @@
 #include "outputbuffer.h"
 
 #include <algorithm>
-#if (GCC_VERSION < VERSION2(3,0)) && (GCC_VERSION >= VERSION2(2,95))
-#include <g++-3/string>
-#else
 #include <string>
-#endif
 #include <list>
 #include <dirent.h>
 #include <sys/stat.h>
