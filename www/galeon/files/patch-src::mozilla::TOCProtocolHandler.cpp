
$FreeBSD$

--- src/mozilla/TOCProtocolHandler.cpp	2001/10/16 07:21:34	1.1
+++ src/mozilla/TOCProtocolHandler.cpp	2001/10/16 07:21:49
@@ -21,13 +21,7 @@
 #include "outputbuffer.h"
 
 #include <algorithm>
-#if (GCC_VERSION < VERSION2(3,0)) && (GCC_VERSION >= VERSION2(2,95))
-#include <g++-3/string>
-#elif (GCC_VERSION < VERSION2(3,0)) && (GCC_VERSION > VERSION2(2,90))
-#include <g++-2/string>
-#else
 #include <string>
-#endif
 #include <list>
 #include <dirent.h>
 #include <sys/stat.h>
