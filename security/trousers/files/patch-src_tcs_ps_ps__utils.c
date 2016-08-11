--- src/tcs/ps/ps_utils.c.orig	2016-06-20 15:21:26 UTC
+++ src/tcs/ps/ps_utils.c
@@ -16,10 +16,18 @@
 #if defined(HAVE_BYTEORDER_H)
 #include <sys/byteorder.h>
 #elif defined(HTOLE_DEFINED)
+#if defined(HAVE_ENDIAN_H)
 #include <endian.h>
 #define LE_16 htole16
 #define LE_32 htole32
 #define LE_64 htole64
+#endif
+#if defined(HAVE_SYS_ENDIAN_H)
+#include <sys/endian.h>
+#define LE_16 htole16
+#define LE_32 htole32
+#define LE_64 htole64
+#endif
 #else
 #define LE_16(x) (x)
 #define LE_32(x) (x)
@@ -42,11 +50,7 @@
 struct key_disk_cache *key_disk_cache_head = NULL;
 
 
-#ifdef SOLARIS
 TSS_RESULT
-#else
-inline TSS_RESULT
-#endif
 read_data(int fd, void *data, UINT32 size)
 {
 	int rc;
@@ -64,11 +68,7 @@ read_data(int fd, void *data, UINT32 siz
 }
 
 
-#ifdef SOLARIS
 TSS_RESULT
-#else
-inline TSS_RESULT
-#endif
 write_data(int fd, void *data, UINT32 size)
 {
 	int rc;
