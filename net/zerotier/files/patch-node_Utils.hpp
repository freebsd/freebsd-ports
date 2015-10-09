--- node/Utils.hpp.orig	2015-08-25 16:55:14 UTC
+++ node/Utils.hpp
@@ -39,6 +39,10 @@
 #include <vector>
 #include <map>
 
+#if defined(__FreeBSD__)
+#include <sys/endian.h>
+#endif
+
 #include "Constants.hpp"
 
 namespace ZeroTier {
@@ -321,8 +325,12 @@ public:
 		throw()
 	{
 #if __BYTE_ORDER == __LITTLE_ENDIAN
-#if defined(__GNUC__) && (!defined(__OpenBSD__))
+#if defined(__GNUC__)
+#if defined(__FreeBSD__)
+		return bswap64(n);
+#elif (!defined(__OpenBSD__))
 		return __builtin_bswap64(n);
+#endif
 #else
 		return (
 			((n & 0x00000000000000FFULL) << 56) | 
@@ -351,8 +359,12 @@ public:
 		throw()
 	{
 #if __BYTE_ORDER == __LITTLE_ENDIAN
-#if defined(__GNUC__) && !defined(__OpenBSD__)
+#if defined(__GNUC__)
+#if defined(__FreeBSD__)
+		return bswap64(n);
+#elif (!defined(__OpenBSD__))
 		return __builtin_bswap64(n);
+#endif
 #else
 		return (
 			((n & 0x00000000000000FFULL) << 56) | 
