--- include/freebsd.h.orig	Mon Jan 16 22:46:48 2006
+++ include/freebsd.h	Sat May 27 03:35:21 2006
@@ -27,7 +27,13 @@
 #include <paths.h>
 #include <uuid.h>
 
-#include <machine/endian.h>
+#include <sys/endian.h>
+#define __BYTE_ORDER    BYTE_ORDER
+#define __BIG_ENDIAN    BIG_ENDIAN
+#define __LITTLE_ENDIAN LITTLE_ENDIAN
+#define __swab16(x)	bswap16(x)
+#define __swab32(x)	bswap32(x)
+#define __swab64(x)	bswap64(x)
 
 /* FreeBSD file API is 64-bit aware */
 #define	fstat64		fstat
@@ -38,15 +44,6 @@
 #define	pread64		pread
 #define	fdatasync	fsync
 #define memalign(a,size)	valloc(size)
-
-typedef u_int8_t	__u8;
-typedef int8_t		__s8;
-typedef u_int16_t	__u16;
-typedef int16_t		__s16;
-typedef u_int32_t	__u32;
-typedef int32_t		__s32;
-typedef u_int64_t	__u64;
-typedef int64_t		__s64;
 
 #define constpp	char * const *
 
