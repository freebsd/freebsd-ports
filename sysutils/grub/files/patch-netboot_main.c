--- netboot/main.c.orig	Sat Jan 18 21:13:02 2003
+++ netboot/main.c	Sat Jan 18 21:13:27 2003
@@ -82,6 +82,7 @@
   RFC2132_MSG_TYPE, 1, DHCPDISCOVER,	
   RFC2132_MAX_SIZE,2,	/* request as much as we can */
   ETH_MAX_MTU / 256, ETH_MAX_MTU % 256,
+  RFC2132_VENDOR_CLASS_ID,4,'G','R','U','B',
   RFC2132_PARAM_LIST, 4, RFC1533_NETMASK, RFC1533_GATEWAY,
   RFC1533_HOSTNAME, RFC1533_EXTENSIONPATH
 };
@@ -93,6 +94,7 @@
   RFC2132_REQ_ADDR, 4, 0, 0, 0, 0,
   RFC2132_MAX_SIZE, 2,	/* request as much as we can */
   ETH_MAX_MTU / 256, ETH_MAX_MTU % 256,
+  RFC2132_VENDOR_CLASS_ID,4,'G','R','U','B',
   /* request parameters */
   RFC2132_PARAM_LIST,
   /* 4 standard + 2 vendortags */
