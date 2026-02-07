--- ldap-ethers.h.orig
+++ ldap-ethers.h
@@ -32,7 +32,7 @@
 
 #ifndef HAVE_STRUCT_ETHER_ADDR
 struct ether_addr {
-  u_char ether_addr_octet[6];
+  u_char octet[6];
 };
 #endif
 
