--- ../usr/share/tribler/Tribler/SwiftEngine/httpgw.cpp.orig	2012-10-12 14:17:32.000000000 +0900
+++ ../usr/share/tribler/Tribler/SwiftEngine/httpgw.cpp	2012-11-01 02:10:53.000000000 +0900
@@ -11,6 +11,11 @@
 #include <event2/bufferevent.h>
 #include <sstream>
 
+#include <sys/param.h>
+#if __FreeBSD_version <= 704100 || (__FreeBSD_version >= 800000 && __FreeBSD_vesion < 802502) || (__FreeBSD_version >= 900000 && __FreeBSD_version < 900027)
+#define log2(x) (log(x) / log(2))
+#endif
+
 using namespace swift;
 
 #define HTTPGW_PROGRESS_STEP_BYTES 		(256*1024)
