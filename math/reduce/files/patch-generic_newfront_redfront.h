--- generic/newfront/redfront.h.orig	2018-06-17 19:20:00 UTC
+++ generic/newfront/redfront.h
@@ -114,8 +114,11 @@ typedef void (*sig_t)(int);
  * version is different...
  */
 #ifndef NATIVE_WINDOWS
+
 #include "sys.h"
+#ifndef wcwidth
 extern int wcwidth(wchar_t c);
+#endif
 #include "chartype.h"
 #endif
 
