--- address.hpp.orig	2010-09-28 18:12:26 UTC
+++ address.hpp
@@ -28,7 +28,7 @@
 #include <sys/socket.h>
 
 #include <arpa/inet.h>
-#ifdef __FreeBSD__
+#if defined(__FreeBSD__) || defined(__DragonFly__)
   #include <netinet/if_ether.h>
 #endif
 #ifdef __linux__
@@ -44,7 +44,7 @@
 std::string textToEthernet(const std::string &textEthernetAddress) {
   ether_addr binaryEthernetAddress;
   ether_aton_r(textEthernetAddress.c_str(), &binaryEthernetAddress);
-  #ifdef __FreeBSD__
+  #if defined(__FreeBSD__) || defined(__DragonFly__)
     return std::string((char*)binaryEthernetAddress.octet, ETHER_ADDR_LEN);
   #endif
   #ifdef __linux__
@@ -60,7 +60,7 @@ std::string textToEthernet(const std::string &textEthe
 std::string ethernetToText(const char *binaryEthernetAddress) {
   ether_addr _binaryEthernetAddress;
   char textEthernetAddress[17];
-  #ifdef __FreeBSD__
+  #if defined(__FreeBSD__) || defined(__DragonFly__)
     memcpy(_binaryEthernetAddress.octet, binaryEthernetAddress, ETHER_ADDR_LEN);
   #endif
   #ifdef __linux__
