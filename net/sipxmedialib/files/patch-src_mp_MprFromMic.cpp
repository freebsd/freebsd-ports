--- ./src/mp/MprFromMic.cpp.orig	Thu Dec 28 19:37:48 2006
+++ ./src/mp/MprFromMic.cpp	Thu Dec 28 19:38:44 2006
@@ -16,7 +16,7 @@
 #include <assert.h>
 
 #ifdef __pingtel_on_posix__
-#  ifdef __linux__
+#  if defined(__linux__) || defined(__FreeBSD__)
 #     include <stdlib.h>
       typedef __int64_t __int64;
 #  elif defined(sun)
