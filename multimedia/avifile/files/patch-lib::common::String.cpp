--- lib/common/String.cpp.orig	Wed Nov 19 10:51:12 2003
+++ lib/common/String.cpp	Wed Nov 19 10:52:01 2003
@@ -3,6 +3,7 @@
 #include <ctype.h>
 #include <stdio.h>
 #include <stdarg.h>
+#include <stdlib.h>
 
 AVM_BEGIN_NAMESPACE;
 
@@ -170,7 +171,7 @@
 #else
     // a bit poor hack but should be sufficient
     // eventually write full implementation
-    s = malloc(1000);
+    s = (char *)malloc(1000);
     r = vsnprintf(str, 999, fmt, ap);
 #endif
     if (s)
