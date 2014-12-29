--- libproxy/modules/pacrunner_webkit.cpp.orig	2010-09-01 20:23:34.000000000 +0000
+++ libproxy/modules/pacrunner_webkit.cpp
@@ -20,6 +20,7 @@
 #include "../extension_pacrunner.hpp"
 using namespace libproxy;
 
+#include <unistd.h>
 #ifdef __APPLE__
 // JavaScriptCore.h requires CoreFoundation
 // This is only found on Mac OS X
