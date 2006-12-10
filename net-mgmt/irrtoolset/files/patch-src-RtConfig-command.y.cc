--- src/RtConfig/command.y.cc.orig	2004-07-30 12:58:11.000000000 +0200
+++ src/RtConfig/command.y.cc
@@ -114,7 +114,11 @@
 
 #include "config.h"
 
+#if (__GNUC__ > 2)
 #include <ostream>
+#else
+#include <ostream.h>
+#endif
 #include <cstring>
 #include <cstdlib>
 #include <cctype>
