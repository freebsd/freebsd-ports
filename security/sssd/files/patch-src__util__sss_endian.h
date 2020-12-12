diff --git src/util/sss_endian.h src/util/sss_endian.h
index 834c35980..d0bc1d338 100644
--- src/util/sss_endian.h
+++ src/util/sss_endian.h
@@ -29,6 +29,18 @@
 # include <sys/endian.h>
 #endif /* !HAVE_ENDIAN_H && !HAVE_SYS_ENDIAN_H */
 
+#if defined(_BYTE_ORDER) && !defined(__BYTE_ORDER)
+#define __BYTE_ORDER _BYTE_ORDER
+#endif
+
+#if defined(_LITTLE_ENDIAN) && !defined(__LITTLE_ENDIAN)
+#define __LITTLE_ENDIAN _LITTLE_ENDIAN
+#endif
+
+#if defined(_BIG_ENDIAN) && !defined(__BIG_ENDIAN)
+#define __BIG_ENDIAN _BIG_ENDIAN
+#endif
+
 /* Endianness-compatibility for systems running older versions of glibc */
 
 #ifndef le32toh
