--- MySQL/Plugins/IndexPlugin.cpp.orig	2025-10-27 11:52:57 UTC
+++ MySQL/Plugins/IndexPlugin.cpp
@@ -30,6 +30,7 @@
 #include <Toolbox.h>
 
 #include <google/protobuf/any.h>
+#include <google/protobuf/stubs/common.h>
 
 #define ORTHANC_PLUGIN_NAME "mysql-index"
 
