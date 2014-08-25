--- ./third_party/WebKit/Source/wtf/Assertions.cpp.orig	2014-04-30 22:47:16.000000000 +0200
+++ ./third_party/WebKit/Source/wtf/Assertions.cpp	2014-05-04 14:38:48.000000000 +0200
@@ -38,6 +38,7 @@
 #include "OwnPtr.h"
 #include "PassOwnPtr.h"
 
+#include <stdlib.h>
 #include <stdio.h>
 #include <stdarg.h>
 #include <stdlib.h>
