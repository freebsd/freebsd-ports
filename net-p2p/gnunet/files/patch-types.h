--- src/util/gcry/types.h.orig	Mon Oct  6 20:17:50 2003
+++ src/util/gcry/types.h	Mon Oct  6 20:18:10 2003
@@ -48,12 +48,6 @@
   #define HAVE_BYTE_TYPEDEF
 #endif
 
-#ifndef HAVE_USHORT_TYPEDEF
-  #undef ushort     /* maybe there is a macro with this name */
-  typedef unsigned short ushort;
-  #define HAVE_USHORT_TYPEDEF
-#endif
-
 #ifndef HAVE_ULONG_TYPEDEF
   #undef ulong	    /* maybe there is a macro with this name */
   typedef unsigned long ulong;
