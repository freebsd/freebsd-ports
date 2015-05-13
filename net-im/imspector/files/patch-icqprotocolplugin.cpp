--- icqprotocolplugin.cpp.orig	2010-11-23 17:53:29.000000000 +0300
+++ icqprotocolplugin.cpp	2011-11-08 19:13:36.000000000 +0400
@@ -10,6 +10,7 @@
  * in the README file. */
 
 #include "imspector.h"
+#include <sys/endian.h>
 
 #define PLUGIN_NAME "ICQ-AIM IMSpector protocol plugin"
 #define PROTOCOL_NAME "ICQ-AIM"
@@ -810,7 +811,7 @@
 	GET_TYPE(uint16_t)
 
 # if __BYTE_ORDER == __BIG_ENDIAN
-	*rc = __bswap_16(*rc);
+	*rc = bswap16(*rc);
 #endif
 
 	return true;
