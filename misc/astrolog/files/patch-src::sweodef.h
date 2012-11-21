--- src/sweodef.h.orig	2012-11-21 12:36:17.000000000 +0400
+++ src/sweodef.h	2012-11-21 12:37:03.000000000 +0400
@@ -197,10 +197,10 @@
   typedef unsigned int UINT2;	/* unsigned 16 bits */
 # define ABS4	labs		/* abs function for long */ 
 #else
-  typedef int	int32;
-  typedef long long	int64;
-  typedef unsigned int	uint32;
-  typedef short	int16;
+  typedef int32_t	int32;
+  typedef int64_t	int64;
+  typedef uint32_t	uint32;
+  typedef int16_t	int16;
   typedef double  REAL8;  /* real with at least 64 bit precision */
   typedef int     INT4;   /* signed integer with at least 32 bit precision */
   typedef unsigned int UINT4; 
