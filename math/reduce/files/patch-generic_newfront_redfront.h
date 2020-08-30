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
 
@@ -133,8 +133,8 @@ extern int wcwidth(wchar_t c);
 #define HANDLE_T int
 #endif
 
-HANDLE_T MeToReduce[2];
-HANDLE_T ReduceToMe[2];
+extern HANDLE_T MeToReduce[2];
+extern HANDLE_T ReduceToMe[2];
 extern int redread(HANDLE_T h, void *buffer, int len);
 extern int redwrite(HANDLE_T h, void *buffer, int len);
 extern void redclose(HANDLE_T h);
