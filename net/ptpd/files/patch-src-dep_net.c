--- dep/net.c.orig
+++ dep/net.c
@@ -8,26 +8,26 @@
   
   /* set multicast group address based on subdomainName */
   if (!memcmp(subdomainName, DEFAULT_PTP_DOMAIN_NAME, PTP_SUBDOMAIN_NAME_LENGTH))
-    memcpy(subdomainAddress, DEFAULT_PTP_DOMAIN_ADDRESS, NET_ADDRESS_LENGTH);
+    strncpy(subdomainAddress, DEFAULT_PTP_DOMAIN_ADDRESS, NET_ADDRESS_LENGTH);
   else if(!memcmp(subdomainName, ALTERNATE_PTP_DOMAIN1_NAME, PTP_SUBDOMAIN_NAME_LENGTH))
-    memcpy(subdomainAddress, ALTERNATE_PTP_DOMAIN1_ADDRESS, NET_ADDRESS_LENGTH);
+    strncpy(subdomainAddress, ALTERNATE_PTP_DOMAIN1_ADDRESS, NET_ADDRESS_LENGTH);
   else if(!memcmp(subdomainName, ALTERNATE_PTP_DOMAIN2_NAME, PTP_SUBDOMAIN_NAME_LENGTH))
-    memcpy(subdomainAddress, ALTERNATE_PTP_DOMAIN2_ADDRESS, NET_ADDRESS_LENGTH);
+    strncpy(subdomainAddress, ALTERNATE_PTP_DOMAIN2_ADDRESS, NET_ADDRESS_LENGTH);
   else if(!memcmp(subdomainName, ALTERNATE_PTP_DOMAIN3_NAME, PTP_SUBDOMAIN_NAME_LENGTH))
-    memcpy(subdomainAddress, ALTERNATE_PTP_DOMAIN3_ADDRESS, NET_ADDRESS_LENGTH);
+    strncpy(subdomainAddress, ALTERNATE_PTP_DOMAIN3_ADDRESS, NET_ADDRESS_LENGTH);
   else
   {
     h = crc_algorithm(subdomainName, PTP_SUBDOMAIN_NAME_LENGTH) % 3;
     switch(h)
     {
     case 0:
-      memcpy(subdomainAddress, ALTERNATE_PTP_DOMAIN1_ADDRESS, NET_ADDRESS_LENGTH);
+      strncpy(subdomainAddress, ALTERNATE_PTP_DOMAIN1_ADDRESS, NET_ADDRESS_LENGTH);
       break;
     case 1:
-      memcpy(subdomainAddress, ALTERNATE_PTP_DOMAIN2_ADDRESS, NET_ADDRESS_LENGTH);
+      strncpy(subdomainAddress, ALTERNATE_PTP_DOMAIN2_ADDRESS, NET_ADDRESS_LENGTH);
       break;
     case 2:
-      memcpy(subdomainAddress, ALTERNATE_PTP_DOMAIN3_ADDRESS, NET_ADDRESS_LENGTH);
+      strncpy(subdomainAddress, ALTERNATE_PTP_DOMAIN3_ADDRESS, NET_ADDRESS_LENGTH);
       break;
     default:
       ERROR("handle out of range for '%s'!\n", subdomainName);
