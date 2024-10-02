--- src/web/FileUtils.C.orig	2024-03-06 10:25:31 UTC
+++ src/web/FileUtils.C
@@ -6,6 +6,7 @@
 
 #include "web/FileUtils.h"
 
+#include <boost/filesystem/directory.hpp>
 #include <boost/filesystem/operations.hpp>
 
 #include "web/WebUtils.h"
