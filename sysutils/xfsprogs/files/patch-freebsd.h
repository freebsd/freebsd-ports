--- include/freebsd.h.orig	Mon Jan 16 22:46:48 2006
+++ include/freebsd.h	Sat May 27 08:57:20 2006
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
@@ -39,15 +45,6 @@
 #define	fdatasync	fsync
 #define memalign(a,size)	valloc(size)
 
-typedef u_int8_t	__u8;
-typedef int8_t		__s8;
-typedef u_int16_t	__u16;
-typedef int16_t		__s16;
-typedef u_int32_t	__u32;
-typedef int32_t		__s32;
-typedef u_int64_t	__u64;
-typedef int64_t		__s64;
-
 #define constpp	char * const *
 
 #define EFSCORRUPTED	990	/* Filesystem is corrupted */
@@ -84,7 +81,7 @@
 	struct statfs buf;
 	if (fstatfs(fd, &buf) < 0)
 		return 0;
-	return strcpy(buf.f_fstypename, "xfs") == 0;
+	return strncmp(buf.f_fstypename, "xfs", 4) == 0;
 }
 
 static __inline__ int platform_test_xfs_path(const char *path)
@@ -92,7 +89,7 @@
 	struct statfs buf;
 	if (statfs(path, &buf) < 0)
 		return 0;
-	return strcpy(buf.f_fstypename, "xfs") == 0;
+	return strncmp(buf.f_fstypename, "xfs", 4) == 0;
 }
 
 static __inline__ int platform_fstatfs(int fd, struct statfs *buf)
