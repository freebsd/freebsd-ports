--- src/Core/util/Buffer.cc.orig	2004-07-30 12:58:10.000000000 +0200
+++ src/Core/util/Buffer.cc
@@ -36,7 +36,11 @@
 #include <cassert>
 #include <iomanip>
 #include <cctype>
+#if (__GNUC__ > 2)
 #include <ostream>
+#else
+#include <ostream.h>
+#endif
 
 using namespace std;
 
