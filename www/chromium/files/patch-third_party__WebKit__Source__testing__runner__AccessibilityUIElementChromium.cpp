--- third_party/WebKit/Source/testing/runner/AccessibilityUIElementChromium.cpp.orig	2013-09-28 19:19:17.000000000 +0200
+++ third_party/WebKit/Source/testing/runner/AccessibilityUIElementChromium.cpp	2013-10-11 11:03:56.000000000 +0200
@@ -37,6 +37,8 @@
 #include "public/platform/WebString.h"
 #include "public/web/WebAccessibilityObject.h"
 
+#include <stdlib.h>
+
 using namespace WebKit;
 using namespace std;
 
