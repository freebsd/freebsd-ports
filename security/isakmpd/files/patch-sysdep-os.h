--- sysdep/freebsd/sysdep-os.h~	Fri Jan 25 14:55:21 2002
+++ sysdep/freebsd/sysdep-os.h	Tue Nov 26 14:40:03 2002
@@ -56,7 +56,7 @@
 /* FreeBSD 4.2 */
 #define SADB_X_EALG_BLF			SADB_EALG_BLOWFISHCBC
 #define SADB_X_EALG_CAST		SADB_EALG_CAST128CBC
-#else if ( SADB_EALG_MAX == 12 )
+#elif ( SADB_EALG_MAX == 12 )
 /* FreeBSD 4.4 */
 #define SADB_X_EALG_BLF			SADB_X_EALG_BLOWFISHCBC
 #define SADB_X_EALG_CAST		SADB_X_EALG_CAST128CBC
@@ -79,6 +79,13 @@
   memcpy ((o), (i), BLOCKSIZE); \
   CAST_decrypt ((CAST_LONG *)(o), (k)); \
 }
+#endif
+
+#ifndef CPI_RESERVED_MAX
+#define CPI_RESERVED_MIN	1
+#define CPI_RESERVED_MAX	255
+#define CPI_PRIVATE_MIN		61440
+#define CPI_PRIVATE_MAX		65536
 #endif
 
 #endif /* _SYSDEP_OS_H_ */
