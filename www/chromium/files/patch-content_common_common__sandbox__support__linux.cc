--- content/common/common_sandbox_support_linux.cc.orig	2021-04-14 18:41:02 UTC
+++ content/common/common_sandbox_support_linux.cc
@@ -5,6 +5,7 @@
 #include "content/public/common/common_sandbox_support_linux.h"
 
 #include <sys/stat.h>
+#include <unistd.h>
 
 #include <limits>
 #include <memory>
