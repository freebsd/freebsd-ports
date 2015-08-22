--- trio/triodef.h.orig	2015-07-19 03:20:32.007345000 +0900
+++ trio/triodef.h	2015-07-19 03:27:30.381863000 +0900
@@ -185,12 +185,13 @@
 # endif
 #endif
 
-#if (_XOPEN_VERSION - 0 >= 3) || defined(_XOPEN_XPG3)
+#if (defined(_XOPEN_VERSION) && (_XOPEN_VERSION - 0 >= 3)) || defined(_XOPEN_XPG3)
 # define PREDEF_STANDARD_XPG3
 #endif
-#if (_XOPEN_VERSION - 0 >= 4) || defined(_XOPEN_XPG4)
+#if (defined(_XOPEN_VERSION) && (_XOPEN_VERSION - 0 >= 4)) || defined(_XOPEN_XPG4)
 # define PREDEF_STANDARD_XPG4
 #endif
+#if defined(_XOPEN_VERSION)
 #if (_XOPEN_VERSION - 0 > 4) \
  || (defined(_XOPEN_UNIX) && (_XOPEN_VERSION - 0 == 4))
 # define PREDEF_STANDARD_UNIX95
@@ -201,6 +202,7 @@
 #if (_XOPEN_VERSION - 0 >= 600)
 # define PREDEF_STANDARD_UNIX03
 #endif
+#endif
 
 /*************************************************************************
  * Generic defines
