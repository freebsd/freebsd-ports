--- ./classes/src/ArtsAttribute.cc.orig	Mon Oct  2 13:05:22 2000
+++ ./classes/src/ArtsAttribute.cc	Wed Sep 25 16:38:10 2002
@@ -41,6 +41,7 @@
 //===========================================================================
 
 extern "C" {
+#include "artslocal.h"
 #include <sys/types.h>
 #include <sys/socket.h>
 #include <netinet/in.h>
@@ -51,7 +52,12 @@
 }
 
 #include <string>
-#include <iomanip.h>
+#if HAVE_IOMANIP
+# include <iomanip>
+  using namespace std;
+#else
+# include <iomanip.h>
+#endif
 
 #include "ArtsAttribute.hh"
 #include "ArtsPrimitive.hh"
@@ -487,10 +493,10 @@
 
   idAndFormat = (this->_identifier << 8) | this->_format;
   uIntDatum = htonl(idAndFormat);
-  os.write(&uIntDatum,sizeof(uIntDatum));
+  os.write((char *)&uIntDatum,sizeof(uIntDatum));
 
   uIntDatum = htonl(this->_length);
-  os.write(&uIntDatum,sizeof(uIntDatum));
+  os.write((char *)&uIntDatum,sizeof(uIntDatum));
 
   switch (this->_identifier) {
     case artsC_ATTR_COMMENT:
@@ -499,16 +505,16 @@
       break;
     case artsC_ATTR_CREATION:
       uIntDatum = htonl(this->_value.creation);
-      os.write(&uIntDatum,sizeof(uIntDatum));
+      os.write((char *)&uIntDatum,sizeof(uIntDatum));
       break;
     case artsC_ATTR_PERIOD:
       uIntDatum = htonl(this->_value.period[0]);
-      os.write(&uIntDatum,sizeof(uIntDatum));
+      os.write((char *)&uIntDatum,sizeof(uIntDatum));
       uIntDatum = htonl(this->_value.period[1]);
-      os.write(&uIntDatum,sizeof(uIntDatum));
+      os.write((char *)&uIntDatum,sizeof(uIntDatum));
       break;
     case artsC_ATTR_HOST:
-      os.write(&this->_value.host,sizeof(this->_value.host));
+      os.write((char *)&this->_value.host,sizeof(this->_value.host));
       break;
     case artsC_ATTR_IFDESCR:
       ptr = this->_value.ifDescr->c_str();
@@ -516,14 +522,14 @@
       break;
     case artsC_ATTR_IFINDEX:
       uShortDatum = htons(this->_value.ifIndex);
-      os.write(&uShortDatum,sizeof(uShortDatum));
+      os.write((char *)&uShortDatum,sizeof(uShortDatum));
       break;
     case artsC_ATTR_IFIPADDR:
-      os.write(&this->_value.ifIpAddr,sizeof(this->_value.ifIpAddr));
+      os.write((char *)&this->_value.ifIpAddr,sizeof(this->_value.ifIpAddr));
       break;
     case artsC_ATTR_HOSTPAIR:
-      os.write(&(this->_value.hostPair[0]),sizeof(ipv4addr_t));
-      os.write(&(this->_value.hostPair[1]),sizeof(ipv4addr_t));
+      os.write((char *)&(this->_value.hostPair[0]),sizeof(ipv4addr_t));
+      os.write((char *)&(this->_value.hostPair[1]),sizeof(ipv4addr_t));
       break;
     default:
       break;
@@ -675,12 +681,12 @@
       break;
   }
   
-  is.read(&uIntDatum,sizeof(uIntDatum));
+  is.read((char *)&uIntDatum,sizeof(uIntDatum));
   idAndFormat = ntohl(uIntDatum);
   this->_identifier = idAndFormat >> 8;
   this->_format = idAndFormat & 0xff;
 
-  is.read(&uIntDatum,sizeof(uIntDatum));
+  is.read((char *)&uIntDatum,sizeof(uIntDatum));
   this->_length = ntohl(uIntDatum);
 
   switch (this->_identifier) {
@@ -693,17 +699,17 @@
       free(ptr);
       break;
     case artsC_ATTR_CREATION:
-      is.read(&uIntDatum,sizeof(uIntDatum));
+      is.read((char *)&uIntDatum,sizeof(uIntDatum));
       this->_value.creation = ntohl(uIntDatum);
       break;
     case artsC_ATTR_PERIOD:
-      is.read(&uIntDatum,sizeof(uIntDatum));
+      is.read((char *)&uIntDatum,sizeof(uIntDatum));
       this->_value.period[0] = htonl(uIntDatum);
-      is.read(&uIntDatum,sizeof(uIntDatum));
+      is.read((char *)&uIntDatum,sizeof(uIntDatum));
       this->_value.period[1] = htonl(uIntDatum);
       break;
     case artsC_ATTR_HOST:
-      is.read(&this->_value.host,sizeof(this->_value.host));
+      is.read((char *)&this->_value.host,sizeof(this->_value.host));
       break;
     case artsC_ATTR_IFDESCR:
       ptr = (char *)malloc(this->_length - (sizeof(uint32_t) * 2));
@@ -714,15 +720,15 @@
       free(ptr);
       break;
     case artsC_ATTR_IFINDEX:
-      is.read(&this->_value.ifIndex,sizeof(this->_value.ifIndex));
+      is.read((char *)&this->_value.ifIndex,sizeof(this->_value.ifIndex));
       this->_value.ifIndex = ntohs(this->_value.ifIndex);
       break;
     case artsC_ATTR_IFIPADDR:
-      is.read(&this->_value.ifIpAddr,sizeof(this->_value.ifIpAddr));
+      is.read((char *)&this->_value.ifIpAddr,sizeof(this->_value.ifIpAddr));
       break;
     case artsC_ATTR_HOSTPAIR:
-      is.read(&(this->_value.hostPair[0]),sizeof(ipv4addr_t));
-      is.read(&(this->_value.hostPair[1]),sizeof(ipv4addr_t));
+      is.read((char *)&(this->_value.hostPair[0]),sizeof(ipv4addr_t));
+      is.read((char *)&(this->_value.hostPair[1]),sizeof(ipv4addr_t));
       break;
     default:
       break;
