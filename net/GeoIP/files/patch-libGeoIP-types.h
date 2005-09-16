--- libGeoIP/types.h.orig	Fri Apr  8 06:32:43 2005
+++ libGeoIP/types.h	Fri Sep 16 02:12:40 2005
@@ -59,8 +59,6 @@
 #endif
 
 #ifndef HAVE_USHORT_TYPEDEF
-#undef ushort     /* maybe there is a macro with this name */
-typedef unsigned short ushort;
 #define HAVE_USHORT_TYPEDEF
 #endif
 
