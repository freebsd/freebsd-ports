--- include/types.h.orig	Wed Dec 25 23:26:52 2002
+++ include/types.h	Wed Dec 25 23:27:14 2002
@@ -13,7 +13,7 @@
 #ifndef __TYPES_H
 #define __TYPES_H
 
-#ifdef __linux__
+#ifdef __FreeBSD__
 typedef bool		BOOL;
 typedef float 		double32;
 typedef double 		double64;
@@ -29,7 +29,7 @@
 
 typedef signed short	sint16;
 typedef unsigned short	uint16;
-#endif // __linux__
+#endif // __FreeBSD__
 
 #ifdef __sparc__
 typedef bool            BOOL;
