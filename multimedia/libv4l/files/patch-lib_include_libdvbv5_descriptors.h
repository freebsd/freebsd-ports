--- lib/include/libdvbv5/descriptors.h.orig	2020-05-21 11:22:05 UTC
+++ lib/include/libdvbv5/descriptors.h
@@ -87,6 +87,9 @@ typedef void (*dvb_table_init_func)(struct dvb_v5_fe_p
 extern const dvb_table_init_func dvb_table_initializers[256];
 
 #ifndef _DOXYGEN
+#ifdef __FreeBSD__
+#include <sys/endian.h>
+#else
 #define bswap16(b) do {\
 	b = ntohs(b); \
 } while (0)
@@ -94,6 +97,7 @@ extern const dvb_table_init_func dvb_table_initializer
 #define bswap32(b) do {\
 	b = ntohl(b); \
 } while (0)
+#endif
 
 /* Deprecated */
 #define DVB_DESC_HEADER() \
