--- src/include/util/gcry/types.h.orig	Fri Aug 22 09:57:16 2003
+++ src/include/util/gcry/types.h	Fri Aug 22 09:57:24 2003
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
