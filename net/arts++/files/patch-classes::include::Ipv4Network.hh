--- ./classes/include/Ipv4Network.hh.orig	Tue Sep 12 14:26:26 2000
+++ ./classes/include/Ipv4Network.hh	Wed Sep 25 16:38:10 2002
@@ -20,7 +20,8 @@
 }
 
 #ifdef HAVE_IOSTREAM
-  #include <iostream.h>
+  #include <iostream>
+  using namespace std;
 #else
   #include <iostream.h>
 #endif
@@ -39,7 +40,7 @@
 {
 public:
   ipv4addr_t   net;
-  uint8_t      maskLen;
+  char      maskLen;
   
   //--------------------------------------------------------------------------
   //                              Ipv4Network()                              
@@ -181,10 +182,10 @@
   istream & read(istream & is)
   {
     is.read(&this->maskLen,sizeof(this->maskLen));
-    uint8_t  octet1  = 0;
-    uint8_t  octet2  = 0;
-    uint8_t  octet3  = 0;
-    uint8_t  netSize = (this->maskLen + 7) / 8;
+    char  octet1  = 0;
+    char  octet2  = 0;
+    char  octet3  = 0;
+    char  netSize = (this->maskLen + 7) / 8;
     
     switch (netSize) {
       case 1:
@@ -206,7 +207,7 @@
                           ((ipv4addr_t)octet3 << 8));
         break;
       case 4:
-        is.read(&this->net,sizeof(this->net));
+        is.read((char *)&this->net,sizeof(this->net));
         break;
       default:
         break;
@@ -295,11 +296,11 @@
     //  first we write the netmask length
     os.write(&this->maskLen,sizeof(this->maskLen));
     
-    uint8_t  octet1 = 0;
-    uint8_t  octet2 = 0;
-    uint8_t  octet3 = 0;
+    char  octet1 = 0;
+    char  octet2 = 0;
+    char  octet3 = 0;
     ipv4addr_t  netaddr;
-    uint8_t  netSize = (this->maskLen + 7) / 8;
+    char  netSize = (this->maskLen + 7) / 8;
 
     // and then write the network prefix
     switch (netSize) {
@@ -324,7 +325,7 @@
         os.write(&octet3,sizeof(octet3));
         break;
       case 4:
-        os.write(&this->net,sizeof(this->net));
+        os.write((char *)&this->net,sizeof(this->net));
         break;
       default:
         break;
