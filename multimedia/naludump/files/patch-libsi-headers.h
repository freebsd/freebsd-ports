--- a/libsi/headers.h
+++ b/libsi/headers.h
@@ -17,7 +17,11 @@
 #ifndef LIBSI_HEADERS_H
 #define LIBSI_HEADERS_H
 
+#ifdef __FreeBSD__
+#include <sys/endian.h>
+#else
 #include <endian.h>
+#endif
 
 namespace SI {
 
