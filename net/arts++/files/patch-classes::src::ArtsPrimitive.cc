--- ./classes/src/ArtsPrimitive.cc.orig	Mon Oct  2 13:05:28 2000
+++ ./classes/src/ArtsPrimitive.cc	Wed Sep 25 16:38:10 2002
@@ -150,11 +150,11 @@
   switch (len) {
     case 1:
       val8 = value;
-      os.write(&val8,sizeof(val8));
+      os.write((char *)&val8,sizeof(val8));
       break;
     case 2:
       val16 = htons(value);
-      os.write(&val16,sizeof(val16));
+      os.write((char *)&val16,sizeof(val16));
       break;
     default:
       #ifdef ARTS_DEBUG_DO_ASSERTIONS
@@ -218,11 +218,11 @@
 
   switch (len) {
     case 1:
-      is.read(&val8,sizeof(val8));
+      is.read((char *)&val8,sizeof(val8));
       value = val8;
       break;
     case 2:
-      is.read(&val16,sizeof(val16));
+      is.read((char *)&val16,sizeof(val16));
       value = ntohs(val16);
       break;
     default:
@@ -289,23 +289,23 @@
   switch (len) {
     case 1:
       val8 = value;
-      os.write(&val8,sizeof(val8));
+      os.write((char *)&val8,sizeof(val8));
       break;
     case 2:
       val16 = value;
       val16 = htons(val16);
-      os.write(&val16,sizeof(val16));
+      os.write((char *)&val16,sizeof(val16));
       break;
     case 3:
       val8 = (value >> 16);
-      os.write(&val8,sizeof(val8));
+      os.write((char *)&val8,sizeof(val8));
       val16 = htons((value & 0x0000ffff));
-      os.write(&val16,sizeof(val16));
+      os.write((char *)&val16,sizeof(val16));
       break;
     case 4:
       val32 = value;
       val32 = htonl(value);
-      os.write(&val32,sizeof(val32));
+      os.write((char *)&val32,sizeof(val32));
       break;
     default:
       #ifdef ARTS_DEBUG_DO_ASSERTIONS
@@ -384,21 +384,21 @@
 
   switch (len) {
     case 1:
-      is.read(&val8,sizeof(val8));
+      is.read((char *)&val8,sizeof(val8));
       value = val8;
       break;
     case 2:
-      is.read(&val16,sizeof(val16));
+      is.read((char *)&val16,sizeof(val16));
       value = ntohs(val16);
       break;
     case 3:
-      is.read(&val8,sizeof(val8));
+      is.read((char *)&val8,sizeof(val8));
       value = ((uint32_t)val8) << 16;
-      is.read(&val16,sizeof(val16));
+      is.read((char *)&val16,sizeof(val16));
       value |= ntohs(val16);
       break;
     case 4:
-      is.read(&val32,sizeof(val32));
+      is.read((char *)&val32,sizeof(val32));
       value = ntohl(val32);
       break;
     default:
@@ -483,22 +483,22 @@
   switch (len) {
     case 1:
       val8 = value;
-      os.write(&val8,sizeof(val8));
+      os.write((char *)&val8,sizeof(val8));
       break;
     case 2:
       val16 = value;
       val16 = htons(val16);
-      os.write(&val16,sizeof(val16));
+      os.write((char *)&val16,sizeof(val16));
       break;
     case 4:
       valuePart[0] = value;
       valuePart[0] = htonl(value);
-      os.write(&valuePart[0],sizeof(uint32_t));
+      os.write((char *)&valuePart[0],sizeof(uint32_t));
       break;
     case 8:
       valuePart[0] = htonl(value >> 32);
       valuePart[1] = htonl(value & 0xffffffff);
-      os.write(valuePart,sizeof(valuePart));
+      os.write((char *)valuePart,sizeof(valuePart));
       break;
     default:
       #ifdef ARTS_DEBUG_DO_ASSERTIONS
@@ -575,19 +575,19 @@
 
   switch (len) {
     case 1:
-      is.read(&val8,sizeof(val8));
+      is.read((char *)&val8,sizeof(val8));
       value = val8;
       break;
     case 2:
-      is.read(&val16,sizeof(val16));
+      is.read((char *)&val16,sizeof(val16));
       value = ntohs(val16);
       break;
     case 4:
-      is.read(&valuePart[0],sizeof(uint32_t));
+      is.read((char *)&valuePart[0],sizeof(uint32_t));
       value = ntohl(valuePart[0]);
       break;
     case 8:
-      is.read(valuePart,sizeof(valuePart));
+      is.read((char *)valuePart,sizeof(valuePart));
       value = ((uint64_t)ntohl(valuePart[0])) << 32;
       value += ntohl(valuePart[1]);
       break;
@@ -667,24 +667,24 @@
   
   switch (len) {
     case 1:
-      is.read(&octet1,sizeof(octet1));
+      is.read((char *)&octet1,sizeof(octet1));
       value = htonl((ipv4addr_t)octet1 << 24);
       break;
     case 2:
-      is.read(&octet1,sizeof(octet1));
-      is.read(&octet2,sizeof(octet2));
+      is.read((char *)&octet1,sizeof(octet1));
+      is.read((char *)&octet2,sizeof(octet2));
       value = htonl(((ipv4addr_t)octet1 << 24) | ((ipv4addr_t)octet2 << 16));
       break;
     case 3:
-      is.read(&octet1,sizeof(octet1));
-      is.read(&octet2,sizeof(octet2));
-      is.read(&octet3,sizeof(octet3));
+      is.read((char *)&octet1,sizeof(octet1));
+      is.read((char *)&octet2,sizeof(octet2));
+      is.read((char *)&octet3,sizeof(octet3));
       value = htonl(((ipv4addr_t)octet1 << 24) |
                     ((ipv4addr_t)octet2 << 16) |
                     ((ipv4addr_t)octet3 << 8));
       break;
     case 4:
-      is.read(&ipAddr,sizeof(ipAddr));
+      is.read((char *)&ipAddr,sizeof(ipAddr));
       value = ipAddr;
       break;
     default:
@@ -766,26 +766,26 @@
   switch (len) {
     case 1:
       octet1 = ntohl(value) >> 24;
-      os.write(&octet1,sizeof(octet1));
+      os.write((char *)&octet1,sizeof(octet1));
       break;
     case 2:
       netaddr = ntohl(value);
       octet1 = (ipv4addr_t)(netaddr >> 24) & 0xff;
       octet2 = (ipv4addr_t)(netaddr >> 16) & 0xff;
-      os.write(&octet1,sizeof(octet1));
-      os.write(&octet2,sizeof(octet2));
+      os.write((char *)&octet1,sizeof(octet1));
+      os.write((char *)&octet2,sizeof(octet2));
       break;
     case 3:
       netaddr = ntohl(value);
       octet1 = (ipv4addr_t)(netaddr >> 24) & 0xff;
       octet2 = (ipv4addr_t)(netaddr >> 16) & 0xff;
       octet3 = (ipv4addr_t)(netaddr >> 8) & 0xff;
-      os.write(&octet1,sizeof(octet1));
-      os.write(&octet2,sizeof(octet2));
-      os.write(&octet3,sizeof(octet3));
+      os.write((char *)&octet1,sizeof(octet1));
+      os.write((char *)&octet2,sizeof(octet2));
+      os.write((char *)&octet3,sizeof(octet3));
       break;
     case 4:
-      os.write(&value,4);
+      os.write((char *)&value,4);
       break;
     default:
       #ifdef ARTS_DEBUG_DO_ASSERTIONS
