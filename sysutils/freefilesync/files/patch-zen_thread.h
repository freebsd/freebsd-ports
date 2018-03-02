--- ../../zen/thread.h.orig	2018-03-01 11:48:04.473377000 +0200
+++ ../../zen/thread.h	2018-03-01 11:48:51.214192000 +0200
@@ -12,8 +12,7 @@
 #include "scope_guard.h"
 #include "type_traits.h"
 #include "optional.h"
-    #include <sys/prctl.h>
-
+#include <pthread_np.h>
 
 namespace zen
 {
@@ -407,7 +406,7 @@
 inline
 void setCurrentThreadName(const char* threadName)
 {
-    ::prctl(PR_SET_NAME, threadName, 0, 0, 0);
+    pthread_set_name_np(pthread_self(), threadName);
 
 }
 
