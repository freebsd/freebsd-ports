--- src/endian_types.h.orig	Sat Apr  2 01:02:46 2005
+++ src/endian_types.h	Thu Jul 14 20:35:49 2005
@@ -30,14 +30,45 @@
 /* Needed for BYTE_ORDER and BIG/LITTLE_ENDIAN macros. */
 #ifndef _BSD_SOURCE
 # define _BSD_SOURCE
-# include <endian.h>
+# include <sys/endian.h>
 # undef  _BSD_SOURCE
 #else
-# include <endian.h>
+# include <sys/endian.h>
 #endif
 
 #include <sys/types.h>
-#include <byteswap.h>
+//#include <byteswap.h>
+
+#if __FreeBSD_version__ >= 500000
+#define	bswap_16	bswap16
+#define	bswap_32	bswap32
+#define	bswap_64	bswap64
+#else
+static inline int16_t bswap_16(const int16_t& x)
+{
+	return (x>>8)|((x&255)<<8);
+}
+
+static inline int32_t bswap_32(const int32_t& x)
+{
+	return (x>>24)|((x&0xff0000)>>8)|((x&0xff00)<<8)|((x&255)<<8);
+}
+
+static inline int64_t bswap_64(const int64_t& x)
+{
+	union {
+		unsigned char x[8];
+		int64_t x64;
+	} u;
+	unsigned char t;
+	u.x64 = x;
+	t = u.x[7]; u.x[7] = u.x[0]; u.x[0] =t;
+	t = u.x[6]; u.x[6] = u.x[1]; u.x[1] =t;
+	t = u.x[5]; u.x[5] = u.x[2]; u.x[2] =t;
+	t = u.x[4]; u.x[4] = u.x[3]; u.x[3] =t;
+	return u.x64;
+}
+#endif
 
 static inline int8_t bswap(const int8_t& x)
 {
