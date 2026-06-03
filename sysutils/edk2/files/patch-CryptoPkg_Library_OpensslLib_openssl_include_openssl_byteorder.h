--- CryptoPkg/Library/OpensslLib/openssl/include/openssl/byteorder.h.orig	2025-07-01 11:52:08 UTC
+++ CryptoPkg/Library/OpensslLib/openssl/include/openssl/byteorder.h
@@ -59,6 +59,12 @@
 #  if defined(__OpenBSD__)
 #   include <sys/types.h>
 #  else
+#  if defined(OPENSSL_SYS_UEFI)
+#   define _UINT8_T_DECLARED
+#   define _UINT16_T_DECLARED
+#   define _UINT32_T_DECLARED
+#   define _UINT64_T_DECLARED
+#  endif
 #   include <sys/endian.h>
 #  endif
 #  define OSSL_HTOBE16(x) htobe16(x)
