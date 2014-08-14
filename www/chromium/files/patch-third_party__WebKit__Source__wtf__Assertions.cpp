--- ./third_party/WebKit/Source/wtf/Assertions.cpp.orig	2014-08-12 21:07:13.000000000 +0200
+++ ./third_party/WebKit/Source/wtf/Assertions.cpp	2014-08-13 09:56:58.000000000 +0200
@@ -38,6 +38,7 @@
 #include "OwnPtr.h"
 #include "PassOwnPtr.h"
 
+#include <stdlib.h>
 #include <stdio.h>
 #include <stdarg.h>
 #include <stdlib.h>
