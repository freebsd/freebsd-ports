--- dcpp/TigerHash.cpp.orig	2015-04-19 21:57:16 UTC
+++ dcpp/TigerHash.cpp
@@ -32,7 +32,7 @@
 
 #include <algorithm>
 #include <cstring>
-#include <boost/detail/endian.hpp>
+#include <boost/predef.h>
 
 #include "debug.h"
 
