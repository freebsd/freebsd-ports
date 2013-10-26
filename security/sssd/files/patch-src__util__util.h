From 4fb9ecea7fca68a58515e1552dfdb408ae28baeb Mon Sep 17 00:00:00 2001
From: Lukas Slebodnik <lukas.slebodnik@intrak.sk>
Date: Sat, 27 Jul 2013 14:59:04 +0200
Subject: [PATCH 29/34] patch-src__util__util.h

---
 src/util/util.h | 25 +++++++------------------
 1 file changed, 7 insertions(+), 18 deletions(-)

diff --git src/util/util.h src/util/util.h
index 1f7c6c3..82988eb 100644
--- src/util/util.h
+++ src/util/util.h
@@ -567,24 +567,13 @@ struct sss_domain_info *copy_subdomain(TALLOC_CTX *mem_ctx,
 errno_t sss_br_lock_file(int fd, size_t start, size_t len,
                          int num_tries, useconds_t wait);
 
-/* Endianness-compatibility for systems running older versions of glibc */
-
-#ifndef le32toh
-#include <byteswap.h>
-
-/* Copied from endian.h on glibc 2.15 */
-#ifdef __USE_BSD
-/* Conversion interfaces.  */
-# if __BYTE_ORDER == __LITTLE_ENDIAN
-#  define le32toh(x) (x)
-#  define htole32(x) (x)
-# else
-#  define le32toh(x) __bswap_32 (x)
-#  define htole32(x) __bswap_32 (x)
-# endif
-#endif /* __USE_BSD */
-
-#endif /* le32toh */
+#define BSD_ERR_MASK (0xB5DE <<16)
+#ifndef EUCLEAN
+#define EUCLEAN (BSD_ERR_MASK | 117)
+#endif
+#ifndef EMEDIUMTYPE
+#define EMEDIUMTYPE (BSD_ERR_MASK | 124)
+#endif
 
 #ifdef HAVE_PAC_RESPONDER
 #define BUILD_WITH_PAC_RESPONDER true
-- 
1.8.0

