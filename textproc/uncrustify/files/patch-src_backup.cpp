--- src/backup.cpp.orig	2021-05-13 14:53:40 UTC
+++ src/backup.cpp
@@ -29,9 +29,7 @@
 #include "md5.h"
 #include "unc_ctype.h"
 
-#ifdef __APPLE__
-#include <cerrno>                // is needed under OSX
-#endif
+#include <cerrno>
 
 using namespace std;
 
