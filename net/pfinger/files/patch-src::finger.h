--- src/finger.h.orig	Sat Apr 28 14:21:17 2001
+++ src/finger.h	Sat Apr 28 14:21:43 2001
@@ -21,12 +21,12 @@
 #ifndef FINGER_H
 #define FINGER_H
 
+#include <sys/types.h>
 #include "utmplib.h"
 #ifndef UT_NAMESIZE
 #define UT_NAMESIZE 16
 #endif
 
-#include <sys/types.h>
 
 /* This structure contains information about the user
  * 
