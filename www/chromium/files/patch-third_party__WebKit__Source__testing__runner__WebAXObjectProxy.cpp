--- third_party/WebKit/Source/testing/runner/WebAXObjectProxy.cpp.orig	2014-01-07 21:06:22.000000000 +0100
+++ third_party/WebKit/Source/testing/runner/WebAXObjectProxy.cpp	2014-01-13 13:22:53.000000000 +0100
@@ -37,6 +37,10 @@
 #include "public/platform/WebString.h"
 #include "public/web/WebAXObject.h"
 
+#if defined(OS_FREEBSD)
+#include <stdlib.h> // atoi()
+#endif
+
 using namespace WebKit;
 using namespace std;
 
