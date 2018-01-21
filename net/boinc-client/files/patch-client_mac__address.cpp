--- client/mac_address.cpp.orig	2018-01-21 22:41:16 UTC
+++ client/mac_address.cpp
@@ -262,6 +262,9 @@ int get_mac_address(char* address) {
             return -1;
         }
         hw_addr = (struct ether_addr *)&(item->lifr_lifru.lifru_enaddr);  
+#else
+	/* Need to teach this how on FreeBSD, but for now don't crash */
+	return -1;
 #endif
         strcpy(address, ether_ntoa(hw_addr));
 #ifdef HAVE_STRUCT_LIFCONF
