--- src/finger.h.orig	Thu Apr 26 01:39:28 2001
+++ src/finger.h	Thu Apr 26 01:39:38 2001
@@ -21,12 +21,12 @@
 #ifndef FINGER_H
 #define FINGER_H
 
+#include <sys/types.h>
 #include <utmp.h>
 #ifndef UT_NAMESIZE
 #define UT_NAMESIZE 16
 #endif
 
-#include <sys/types.h>
 
 /* This structure contains information about the user
  * 
