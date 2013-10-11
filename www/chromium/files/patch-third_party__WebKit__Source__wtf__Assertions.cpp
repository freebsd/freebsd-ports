--- third_party/WebKit/Source/wtf/Assertions.cpp.orig	2013-09-28 19:19:20.000000000 +0200
+++ third_party/WebKit/Source/wtf/Assertions.cpp	2013-10-10 11:45:33.000000000 +0200
@@ -37,6 +37,7 @@
 #include "Compiler.h"
 #include "OwnArrayPtr.h"
 
+#include <stdlib.h>
 #include <stdio.h>
 #include <stdarg.h>
 #include <string.h>
