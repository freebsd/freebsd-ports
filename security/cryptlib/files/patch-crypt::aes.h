--- crypt/aes.h.orig	Tue Jun 17 09:52:19 2003
+++ crypt/aes.h	Tue Jun 17 10:04:23 2003
@@ -42,7 +42,11 @@
    half the AES code it's the best we can do */
 
 #if ( defined( __GNUC__ ) && ( __GNUC__ >= 2 ) ) || defined( HAS_STDINT_H )
-  #include <stdint.h>
+  #if defined(__FreeBSD__)
+	#include <unistd.h>
+  #elif 
+	#include <stdint.h>
+  #endif
 #else
   #include "itypes.h"
 #endif /* Systems with C99 headers */
