--- libGeoIP/GeoIPUpdate.c.orig	Tue Oct  8 11:12:17 2002
+++ libGeoIP/GeoIPUpdate.c	Tue Oct  8 11:12:41 2002
@@ -21,9 +21,9 @@
 #include "global.h"
 #include "md5.h"
 #include "GeoIP.h"
+#include <sys/types.h>
 #include <netinet/in.h>
 #include <arpa/inet.h>
-#include <sys/types.h>
 #include <sys/socket.h>
 #include "zlib.h"
 #include "time.h"
