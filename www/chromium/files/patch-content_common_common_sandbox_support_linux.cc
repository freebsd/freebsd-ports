--- content/common/common_sandbox_support_linux.cc.orig	2018-08-04 19:46:27.654459000 +0200
+++ content/common/common_sandbox_support_linux.cc	2018-08-04 19:46:40.138833000 +0200
@@ -5,6 +5,7 @@
 #include "content/public/common/common_sandbox_support_linux.h"
 
 #include <sys/stat.h>
+#include <unistd.h>
 
 #include <limits>
 #include <memory>

