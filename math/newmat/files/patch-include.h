--- include.h.orig	Sat Sep  7 00:26:44 2002
+++ include.h	Fri Sep  6 23:59:21 2002
@@ -30,8 +30,9 @@
 
 #define bool_LIB 0
 
-
-//#define _STANDARD_                    // using standard library
+#if defined __GNUG__ && __GNUG__ >= 3
+#define _STANDARD_                    // using standard library
+#endif
 
 //#define use_float_h                   // use float.h for precision data
 
