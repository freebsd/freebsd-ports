- prevent failures on 14 by using system functions instead of
- redefinitions of htobe..() and be..()

--- lib/src/segy.c.orig	2023-06-19 05:03:27 UTC
+++ lib/src/segy.c
@@ -27,6 +27,8 @@
 #include <stdlib.h>
 #include <string.h>
 
+#include <sys/endian.h>
+
 #include <segyio/segy.h>
 #include <segyio/util.h>
 
@@ -112,6 +114,7 @@ static int encode( char* dst,
                        )
 #endif // __GNUC__
 
+#if 0 // disable htobe.. and be.. functions in favor of the ones from #include <sys/endian.h>1
 static uint16_t htobe16( uint16_t v ) {
 #if HOST_LSB
     return bswap16(v);
@@ -143,6 +146,7 @@ static uint32_t be32toh( uint32_t v ) {
     return v;
 #endif
 }
+#endif
 
 /*
  * DEPRECATED
