--- ./src/mp/MprToSpkr.cpp.orig	Thu Dec 28 19:39:15 2006
+++ ./src/mp/MprToSpkr.cpp	Thu Dec 28 19:39:33 2006
@@ -17,7 +17,7 @@
 #include <assert.h>
 
 #ifdef __pingtel_on_posix__
-#  ifdef __linux__
+#  if defined(__linux__) || defined(__FreeBSD__)
 #     include <stdlib.h>
       typedef __int64_t __int64;
 #  elif defined(sun)
