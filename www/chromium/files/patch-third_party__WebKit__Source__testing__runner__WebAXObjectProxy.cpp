--- third_party/WebKit/Source/testing/runner/WebAXObjectProxy.cpp.orig	2014-01-07 21:06:22.000000000 +0100
+++ third_party/WebKit/Source/testing/runner/WebAXObjectProxy.cpp	2014-01-13 13:22:53.000000000 +0100
@@ -36,6 +36,10 @@
 #include "public/platform/WebRect.h"
 #include "public/platform/WebString.h"
 
+#if defined(OS_FREEBSD)
+#include <stdlib.h> // atoi()
+#endif
+
 using namespace blink;
 using namespace std;
 
