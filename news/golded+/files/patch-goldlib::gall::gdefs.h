--- ./goldlib/gall/gdefs.h.orig	Fri Feb 25 16:10:58 2000
+++ ./goldlib/gall/gdefs.h	Mon Oct 20 17:10:33 2003
@@ -34,14 +34,17 @@
 #include <cstddef>
 #include <gcmpall.h>
 
+using namespace std;
 
 //  ------------------------------------------------------------------
 //  Define portability and shorthand notation
 
+#if !defined(__GNUC__) || __GNUC__ < 3
 #ifndef and
 #define not      !
 #define and      &&
 #define or       ||
+#endif
 #endif
 
 #ifndef true
