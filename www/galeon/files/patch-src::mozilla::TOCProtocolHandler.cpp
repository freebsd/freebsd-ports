
$FreeBSD$

--- src/mozilla/TOCProtocolHandler.cpp.orig	Sat Oct 13 14:52:00 2001
+++ src/mozilla/TOCProtocolHandler.cpp	Mon Oct 22 14:36:19 2001
@@ -21,13 +21,7 @@
 #include "outputbuffer.h"
 
 #include <algorithm>
-#if (GCC_VERSION < VERSION2(3,0)) && (GCC_VERSION >= VERSION2(2,95))
-#include <g++-3/string>
-#elif (GCC_VERSION < VERSION2(3,0)) && (GCC_VERSION > VERSION2(2,90))
-#include <g++-2/string>
-#else
-#include <string>
-#endif
+#include <g++/string>
 #include <list>
 #include <dirent.h>
 #include <sys/stat.h>
