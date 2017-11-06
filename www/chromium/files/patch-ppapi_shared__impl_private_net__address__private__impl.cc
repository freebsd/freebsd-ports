--- ppapi/shared_impl/private/net_address_private_impl.cc.orig	2017-07-25 21:04:59.000000000 +0200
+++ ppapi/shared_impl/private/net_address_private_impl.cc	2017-08-02 15:39:26.715080000 +0200
@@ -29,7 +29,7 @@
 #include <sys/types.h>
 #endif
 
-#if defined(OS_MACOSX)
+#if defined(OS_MACOSX) || defined(OS_BSD)
 // This is a bit evil, but it's standard operating procedure for |s6_addr|....
 #define s6_addr16 __u6_addr.__u6_addr16
 #endif
