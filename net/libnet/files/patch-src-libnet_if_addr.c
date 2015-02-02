- memory leak fixed, device list needs to freed after use. [2]
- Properly set l->err_buf if libnet_ifaddrlist() fails. [3]

Obtained from:	https://github.com/sam-github/libnet/commit/18cbe497dd84afc471a5320e4ef3a7cde87c2c4e [1]
		https://github.com/sam-github/libnet/commit/2e724b2f5cd614d7362f8dcbc57dc1fca6e437b3 [2]

--- src/libnet_if_addr.c.orig	2012-03-20 00:59:50.000000000 +0800
+++ src/libnet_if_addr.c	2015-01-18 03:09:08.169400000 +0800
@@ -330,6 +330,8 @@
         ++nipaddr;
     }
 
+    pcap_freealldevs(alldevs);
+
     *ipaddrp = ifaddrlist;
     return (nipaddr);
 }
@@ -339,7 +341,6 @@
 libnet_select_device(libnet_t *l)
 {
     int c, i;
-    char err_buf[LIBNET_ERRBUF_SIZE];
     struct libnet_ifaddr_list *address_list, *al;
     uint32_t addr;
 
@@ -364,7 +365,7 @@
     /*
      *  Number of interfaces.
      */
-    c = libnet_ifaddrlist(&address_list, l->device, err_buf);
+    c = libnet_ifaddrlist(&address_list, l->device, l->err_buf);
     if (c < 0)
     {
         /* err msg set in libnet_ifaddrlist() */
