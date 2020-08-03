--- smm/vfalib.hpp.orig	2020-07-12 09:44:16 UTC
+++ smm/vfalib.hpp
@@ -9,7 +9,7 @@
 #include <vector>
 #include <cstdint>
 #include <cstdio>
-#include <endian.h>
+#include <sys/endian.h>
 #if (defined(__BYTE_ORDER) && __BYTE_ORDER == __BIG_ENDIAN) || \
     (defined(_BYTE_ORDER) && _BYTE_ORDER == _BIG_ENDIAN)
 	/* We need to use constexpr functions, and htole16 unfortunately is not. */
