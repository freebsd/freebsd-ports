--- OrthancServer/Sources/OrthancInitialization.cpp.orig	2025-02-09 22:16:55 UTC
+++ OrthancServer/Sources/OrthancInitialization.cpp
@@ -60,6 +60,7 @@
 #    define __FILE__ __ORTHANC_FILE__
 #  endif
 #  include <google/protobuf/any.h>
+#  include <google/protobuf/stubs/common.h>
 #endif
 
 
