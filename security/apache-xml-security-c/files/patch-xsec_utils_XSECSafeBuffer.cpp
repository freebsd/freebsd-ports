--- xsec/utils/XSECSafeBuffer.cpp.orig	2018-08-12 18:15:47.905481000 +0200
+++ xsec/utils/XSECSafeBuffer.cpp	2018-08-12 18:21:09.514664000 +0200
@@ -28,6 +28,8 @@
  *
  */
 
+#define __STDC_LIMIT_MACROS
+
 // XSEC includes
 
 #include <xsec/utils/XSECSafeBuffer.hpp>
