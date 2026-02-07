--- contrib/xxhash/xxhash.h.orig	2024-12-16 14:04:14 UTC
+++ contrib/xxhash/xxhash.h
@@ -3062,6 +3062,7 @@ enum XXH_VECTOR_TYPE /* fake enum */ {
 #    if defined(__GNUC__) && !defined(__APPLE_ALTIVEC__)
 #      define __APPLE_ALTIVEC__
 #    endif
+#    define vector __vector
 #    include <altivec.h>
 #  endif
 
