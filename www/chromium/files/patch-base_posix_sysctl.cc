--- base/posix/sysctl.cc.orig	2023-12-17 20:01:00 UTC
+++ base/posix/sysctl.cc
@@ -4,6 +4,7 @@
 
 #include "base/posix/sysctl.h"
 
+#include <sys/types.h>
 #include <sys/sysctl.h>
 
 #include <initializer_list>
