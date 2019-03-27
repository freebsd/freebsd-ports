--- src/3rdparty/chromium/content/common/common_sandbox_support_linux.cc.orig	2018-11-13 18:25:11 UTC
+++ src/3rdparty/chromium/content/common/common_sandbox_support_linux.cc
@@ -5,6 +5,7 @@
 #include "content/public/common/common_sandbox_support_linux.h"
 
 #include <sys/stat.h>
+#include <unistd.h>
 
 #include <limits>
 #include <memory>
