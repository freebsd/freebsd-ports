--- serialized_buffer.h.orig	2008-11-05 08:54:15.000000000 +0800
+++ serialized_buffer.h	2009-03-15 01:53:39.000000000 +0800
@@ -19,13 +19,12 @@
 
 #else // Linux byteswap defs
 
-#include <byteswap.h>
-#include <endian.h>
+#include <sys/endian.h>
 
 #if __BYTE_ORDER == __LITTLE_ENDIAN
-  #define BE16(x) __bswap_16(x)
-  #define BE32(x) __bswap_32(x)
-  #define BE64(x) __bswap_64(x)
+  #define BE16(x) __bswap16(x)
+  #define BE32(x) __bswap32(x)
+  #define BE64(x) __bswap64(x)
   #define LE16(x) (x)
   #define LE32(x) (x)
   #define LE64(x) (x)
@@ -33,9 +32,9 @@
   #define BE16(x) (x)
   #define BE32(x) (x)
   #define BE64(x) (x)
-  #define LE16(x) __bswap_16(x)
-  #define LE32(x) __bswap_32(x)
-  #define LE64(x) __bswap_64(x)
+  #define LE16(x) __bswap16(x)
+  #define LE32(x) __bswap32(x)
+  #define LE64(x) __bswap64(x)
 #endif
 
 #endif
