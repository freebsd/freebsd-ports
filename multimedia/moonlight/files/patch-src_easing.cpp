
$FreeBSD$

--- src/easing.cpp.orig
+++ src/easing.cpp
@@ -16,7 +16,9 @@
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
+#ifndef __FreeBSD__
 #include <malloc.h>
+#endif
 #include <math.h>
 
 #include <runtime.h>
