--- libs/libFreeMat/Scanner.cpp.orig	2009-10-08 09:51:15.000000000 +0700
+++ libs/libFreeMat/Scanner.cpp	2009-10-08 09:51:25.000000000 +0700
@@ -4,6 +4,7 @@
 #include <stdlib.h>
 #include <ctype.h>
 #include "Exception.hpp"
+#include <algorithm>
 
 extern string fm_reserved[];
 extern int fm_reserved_count;
