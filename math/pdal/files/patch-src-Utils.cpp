--- src/Utils.cpp.orig	2014-07-27 19:02:59.456832475 +0200
+++ src/Utils.cpp	2014-07-27 19:03:23.513363445 +0200
@@ -37,6 +37,7 @@
 #include <cassert>
 #include <cstdlib>
 #include <cctype>
+#include <sys/wait.h>
 
 #ifdef PDAL_COMPILER_MSVC
 #  pragma warning(disable: 4127)  // conditional expression is constant
