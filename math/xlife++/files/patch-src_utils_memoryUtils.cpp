--- src/utils/memoryUtils.cpp.orig	2019-05-20 17:06:38 UTC
+++ src/utils/memoryUtils.cpp
@@ -27,8 +27,8 @@ XLiFE++ is an extended library of finite elements writ
 #include "utils.h"
 
 #ifdef OS_IS_UNIX
-#include <sys/sysctl.h>
 #include <sys/types.h>
+#include <sys/sysctl.h>
 #include <sys/resource.h>
 #endif
 
