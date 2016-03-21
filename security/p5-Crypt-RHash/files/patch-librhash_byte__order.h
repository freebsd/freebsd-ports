--- librhash/byte_order.h.orig	2014-01-29 13:28:04 UTC
+++ librhash/byte_order.h
@@ -40,7 +40,7 @@ extern "C" {
 		__BYTE_ORDER == __LITTLE_ENDIAN) || \
 	defined(CPU_IA32) || defined(CPU_X64) || \
 	defined(__ia64) || defined(__ia64__) || defined(__alpha__) || defined(_M_ALPHA) || \
-	defined(vax) || defined(MIPSEL) || defined(_ARM_)
+	defined(vax) || defined(MIPSEL) || defined(_ARM_) || defined(__arm__)
 # define CPU_LITTLE_ENDIAN
 # define IS_BIG_ENDIAN 0
 # define IS_LITTLE_ENDIAN 1
