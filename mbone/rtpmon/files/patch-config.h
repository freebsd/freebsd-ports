--- config.h.orig	Sun Sep 29 10:53:58 2002
+++ config.h	Sun Sep 29 10:54:13 2002
@@ -43,20 +43,6 @@
 # include <sys/bitypes.h>
 #endif
 
-#ifndef __BIT_TYPES_DEFINED__
-/*XXX*/
-# ifdef sco
-typedef char int8_t;
-# else
-typedef signed char int8_t;
-# endif
-typedef unsigned char u_int8_t;
-typedef short int16_t;
-typedef unsigned short u_int16_t;
-typedef unsigned int u_int32_t;
-typedef int int32_t;
-#endif
-
 #ifdef _AIX41
 typedef int bool;
 #define true 1
