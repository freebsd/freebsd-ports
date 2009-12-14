--- spserver/spioutils.cpp.orig	2009-12-14 14:44:52.000000000 +0800
+++ spserver/spioutils.cpp	2009-12-14 14:45:13.000000000 +0800
@@ -8,6 +8,7 @@
 #include <errno.h>
 #include <string.h>
 #include <assert.h>
+#include <sys/stat.h>
 
 #include "spporting.hpp"
 
