--- mozilla/js/src/jsnativestack.cpp~
+++ mozilla/js/src/jsnativestack.cpp
@@ -50,7 +50,8 @@
 #elif defined(XP_MACOSX) || defined(DARWIN) || defined(XP_UNIX)
 # include <pthread.h>
 
-# if defined(__FreeBSD__)
+# if defined(FREEBSD)
+#  include <cstddef>
 #  include <pthread_np.h>
 # endif
