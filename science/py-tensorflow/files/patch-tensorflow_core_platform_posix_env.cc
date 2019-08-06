--- tensorflow/core/platform/posix/env.cc.orig	2019-06-18 23:48:23.000000000 +0100
+++ tensorflow/core/platform/posix/env.cc	2019-07-06 21:03:28.090735000 +0100
@@ -28,6 +28,10 @@
 #include <thread>
 #include <vector>
 
+#ifdef __FREEBSD__
+#include <pthread.h>
+#endif
+
 #include "tensorflow/core/lib/core/error_codes.pb.h"
 #include "tensorflow/core/platform/env.h"
 #include "tensorflow/core/platform/load_library.h"
@@ -113,7 +117,7 @@
     // Has to be casted to long first, else this error appears:
     // static_cast from 'pthread_t' (aka 'pthread *') to 'int32' (aka 'int')
     // is not allowed
-    return static_cast<int32>(static_cast<int64>(pthread_self()));
+    return static_cast<int32>((int64)(pthread_self()));
 #else
     return static_cast<int32>(pthread_self());
 #endif
@@ -129,7 +133,7 @@
         return true;
       }
     }
-#if defined(__ANDROID__) || defined(__EMSCRIPTEN__)
+#if defined(__ANDROID__) || defined(__EMSCRIPTEN__) || defined(__FreeBSD__)
     return false;
 #else
     char buf[100];
