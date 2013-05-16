--- common/packing.cc.orig	2013-05-14 11:51:52.766912852 +0000
+++ common/packing.cc	2013-05-14 11:56:57.204910871 +0000
@@ -50,7 +50,7 @@
         rhs.pack(&sa, 0);
 #ifdef _MSC_VER
         memmove(data, &sa.sin6_addr.u.Byte, 16);
-#elif defined __APPLE__
+#elif defined __APPLE__ || defined __FreeBSD__
         memmove(data, &sa.sin6_addr.__u6_addr.__u6_addr8, 16);
 #else
         memmove(data, &sa.sin6_addr.__in6_u.__u6_addr8, 16);
@@ -90,7 +90,7 @@
         in6_addr ia;
 #ifdef _MSC_VER
         memmove(ia.u.Byte, rem.data(), 16);
-#elif defined __APPLE__
+#elif defined __APPLE__ || defined __FreeBSD__
         memmove(ia.__u6_addr.__u6_addr8, rem.data(), 16);
 #else
         memmove(ia.__in6_u.__u6_addr8, rem.data(), 16);
