--- ./classes/src/ArtsNextHopTableEntry.cc.orig	Mon Oct  2 13:05:26 2000
+++ ./classes/src/ArtsNextHopTableEntry.cc	Wed Sep 25 16:38:10 2002
@@ -192,7 +192,7 @@
 //-------------------------------------------------------------------------
 //   uint32_t ArtsNextHopTableEntry::Length(uint8_t version = 0) const
 //-------------------------------------------------------------------------
-uint32_t ArtsNextHopTableEntry::Length(uint8_t version = 0) const
+uint32_t ArtsNextHopTableEntry::Length(uint8_t version) const
 {
   uint32_t  len = 0;
 
@@ -207,15 +207,15 @@
 //-------------------------------------------------------------------------
 // istream& ArtsNextHopTableEntry::read(istream& is, uint8_t version = 0)
 //-------------------------------------------------------------------------
-istream& ArtsNextHopTableEntry::read(istream& is, uint8_t version = 0)
+istream& ArtsNextHopTableEntry::read(istream& is, uint8_t version)
 {
   uint8_t  fieldLen;
 
   //  IP address
-  is.read(&this->_ipAddr,sizeof(this->_ipAddr));
+  is.read((char *)&this->_ipAddr,sizeof(this->_ipAddr));
   
   //  descriptor
-  is.read(&this->_descriptor,sizeof(this->_descriptor));
+  is.read((char *)&this->_descriptor,sizeof(this->_descriptor));
 
   //  pkts
   fieldLen = (this->_descriptor >> 3) + 1;
@@ -231,7 +231,7 @@
 //-------------------------------------------------------------------------
 //      int ArtsNextHopTableEntry::read(int fd, uint8_t version = 0)
 //-------------------------------------------------------------------------
-int ArtsNextHopTableEntry::read(int fd, uint8_t version = 0)
+int ArtsNextHopTableEntry::read(int fd, uint8_t version)
 {
   uint8_t  fieldLen;
   int      rc = 0;
@@ -262,15 +262,15 @@
 //                                           uint8_t version = 0) const
 //-------------------------------------------------------------------------
 ostream& ArtsNextHopTableEntry::write(ostream& os,
-                                       uint8_t version = 0) const
+                                       uint8_t version) const
 {
   uint8_t  fieldLen;
 
   //  IP address
-  os.write(&this->_ipAddr,sizeof(this->_ipAddr));
+  os.write((char *)&this->_ipAddr,sizeof(this->_ipAddr));
   
   //  descriptor
-  os.write(&this->_descriptor,1);
+  os.write((char *)&this->_descriptor,1);
   
   //  pkts
   fieldLen = (this->_descriptor >> 3) + 1;
@@ -286,7 +286,7 @@
 //-------------------------------------------------------------------------
 //  int ArtsNextHopTableEntry::write(int fd, uint8_t version = 0) const
 //-------------------------------------------------------------------------
-int ArtsNextHopTableEntry::write(int fd, uint8_t version = 0) const
+int ArtsNextHopTableEntry::write(int fd, uint8_t version) const
 {
   uint8_t  fieldLen;
   int      rc = 0;
