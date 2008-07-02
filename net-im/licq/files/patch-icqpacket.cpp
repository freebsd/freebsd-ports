--- src/icqpacket.cpp.orig	2007-09-28 22:11:35.000000000 +0200
+++ src/icqpacket.cpp	2008-07-02 20:09:19.000000000 +0200
@@ -821,7 +821,7 @@
 
   // Static versioning
   buffer->PackUnsignedLongBE(0x00160002);
-  buffer->PackUnsignedShortBE(0x010A);
+  buffer->PackUnsignedShortBE(0x010B);
   // Client version major (4 == ICQ2000, 5 == ICQ2001)
   buffer->PackUnsignedLongBE(0x00170002);
   buffer->PackUnsignedShortBE(0x0014);
