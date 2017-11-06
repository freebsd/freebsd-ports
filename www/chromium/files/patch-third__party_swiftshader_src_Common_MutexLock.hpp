--- third_party/swiftshader/src/Common/MutexLock.hpp.orig	2017-06-26 22:06:54.283201000 +0200
+++ third_party/swiftshader/src/Common/MutexLock.hpp	2017-06-26 22:07:18.656810000 +0200
@@ -17,7 +17,7 @@
 
 #include "Thread.hpp"
 
-#if defined(__linux__)
+#if defined(__linux__) || defined(__FreeBSD__)
 // Use a pthread mutex on Linux. Since many processes may use SwiftShader
 // at the same time it's best to just have the scheduler overhead.
 #include <pthread.h>
