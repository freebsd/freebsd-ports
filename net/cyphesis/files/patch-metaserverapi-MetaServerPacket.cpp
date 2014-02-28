--- metaserverapi/MetaServerPacket.cpp.orig	2014-02-28 09:25:55.000000000 +0100
+++ metaserverapi/MetaServerPacket.cpp	2014-02-28 09:26:13.000000000 +0100
@@ -20,6 +20,8 @@
  */
 
 
+#include <cstdlib>
+#include <cstdio>
 #include "MetaServerPacket.hpp"
 
 MetaServerPacket::MetaServerPacket() :
