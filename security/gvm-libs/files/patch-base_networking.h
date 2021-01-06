--- base/networking.h	2020-12-31 00:01:35.140537000 -0500
+++ base/networking.h	2020-12-31 00:04:13.003782000 -0500
@@ -27,6 +27,7 @@
 
 #include "array.h" /* for array_t */
 
+#include <netinet/in.h>
 #include <netdb.h> /* for struct in6_addr */
 
 /**
