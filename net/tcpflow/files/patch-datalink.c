--- src/datalink.c.orig     Mon May  9 12:00:38 2005
+++ src/datalink.c  Mon May  9 12:23:47 2005
@@ -42,6 +42,13 @@

 #include "tcpflow.h"

+/*
+ * Byte-swap a 32-bit number.
+ * ("htonl()" or "ntohl()" won't work - we want to byte-swap even on
+ * big-endian platforms.)
+ */
+#define SWAPLONG(y) \
+((((y)&0xff)<<24) | (((y)&0xff00)<<8) | (((y)&0xff0000)>>8) | (((y)>>24)&0xff))


 /* The DLT_NULL packet header is 4 bytes long. It contains a network
@@ -71,7 +78,8 @@
 #ifndef DLT_NULL_BROKEN
   /* make sure this is AF_INET */
   memcpy((char *)&family, (char *)p, sizeof(family));
-  family = ntohl(family);
+  // family = ntohl(family);
+  if ((family & 0xFFFF0000) != 0) family = SWAPLONG(family);
   if (family != AF_INET) {
     DEBUG(6) ("warning: received non-AF_INET null frame (type %d)", family);
     return;
