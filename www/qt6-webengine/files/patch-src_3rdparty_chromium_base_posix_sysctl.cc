--- src/3rdparty/chromium/base/posix/sysctl.cc.orig	2025-08-15 18:30:00 UTC
+++ src/3rdparty/chromium/base/posix/sysctl.cc
@@ -4,6 +4,7 @@
 
 #include "base/posix/sysctl.h"
 
+#include <sys/types.h>
 #include <sys/sysctl.h>
 
 #include <initializer_list>
