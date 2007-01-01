--- vamps/requant.c.orig	Mon Mar  6 16:50:05 2006
+++ vamps/requant.c	Sat Dec 16 13:48:39 2006
@@ -66,6 +66,7 @@
 #include <string.h>
 #include <assert.h>
 #include <math.h>
+#include <inttypes.h>
 
 #ifndef USE_FD
 #include <unistd.h>
@@ -98,37 +99,6 @@
 	#define unlikely(x) (x)
 #endif
 
-// user defined types
-//typedef unsigned int		uint;
-typedef unsigned char		uint8;
-typedef unsigned short		uint16;
-typedef unsigned int		uint32;
-#ifdef WIN
-typedef __int64				uint64;
-#else
-typedef unsigned long long	uint64;
-#endif
-
-typedef char				int8;
-typedef short				int16;
-typedef int					int32;
-#ifdef WIN
-typedef __int64				int64;
-#else
-typedef long long			int64;
-#endif
-
-
-typedef signed int			sint;
-typedef signed char			sint8;
-typedef signed short		sint16;
-typedef signed int			sint32;
-#ifdef WIN
-typedef __int64				sint64;
-#else
-typedef signed long long	sint64;
-#endif
-
 #define BITS_IN_BUF (8)
 
 
@@ -661,7 +631,7 @@
 	{
 		putbits(1l, 6); /* Escape */
 		putbits(run, 6); /* 6 bit code for run */
-		putbits(((uint)signed_level) & 0xFFF, 12);
+		putbits(((unsigned int)signed_level) & 0xFFF, 12);
 	}
 	
 	return 0;
