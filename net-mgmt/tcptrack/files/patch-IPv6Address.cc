--- src/IPv6Address.cc.orig	2010-09-28 03:35:16 UTC
+++ src/IPv6Address.cc
@@ -7,6 +7,8 @@
 #include "IPv6Address.h"
 #include "util.h"
 
+#define s6_addr16 __u6_addr.__u6_addr16
+
 uint16_t IPv6Address::GetShort( int index ) const
 {
 	assert(index >= 0);
