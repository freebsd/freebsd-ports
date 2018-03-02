--- lib/dir_lock.h.orig	2018-03-02 05:46:44 UTC
+++ lib/dir_lock.h
@@ -11,6 +11,7 @@
 #include <chrono>
 #include <functional>
 #include <zen/file_error.h>
+#include <zen/warn_static.h>
 
 
 namespace fff
