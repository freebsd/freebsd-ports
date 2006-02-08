--- include/freebsd.h.orig	Tue Feb  7 21:14:51 2006
+++ include/freebsd.h	Tue Feb  7 21:15:07 2006
@@ -39,15 +39,6 @@
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
