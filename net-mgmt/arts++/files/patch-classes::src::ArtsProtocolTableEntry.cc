--- ./classes/src/ArtsProtocolTableEntry.cc.orig	Mon Oct  2 13:05:28 2000
+++ ./classes/src/ArtsProtocolTableEntry.cc	Wed Sep 25 16:38:10 2002
@@ -189,7 +189,7 @@
 //-------------------------------------------------------------------------
 //   uint32_t ArtsProtocolTableEntry::Length(uint8_t version = 0) const
 //-------------------------------------------------------------------------
-uint32_t ArtsProtocolTableEntry::Length(uint8_t version = 0) const
+uint32_t ArtsProtocolTableEntry::Length(uint8_t version) const
 {
   uint32_t  len = 0;
 
@@ -204,15 +204,15 @@
 //-------------------------------------------------------------------------
 // istream& ArtsProtocolTableEntry::read(istream& is, uint8_t version = 0)
 //-------------------------------------------------------------------------
-istream& ArtsProtocolTableEntry::read(istream& is, uint8_t version = 0)
+istream& ArtsProtocolTableEntry::read(istream& is, uint8_t version)
 {
   uint8_t  fieldLen;
 
   //  protocol number
-  is.read(&this->_protocolNum,sizeof(this->_protocolNum));
+  is.read((char *)&this->_protocolNum,sizeof(this->_protocolNum));
   
   //  descriptor
-  is.read(&this->_descriptor,sizeof(this->_descriptor));
+  is.read((char *)&this->_descriptor,sizeof(this->_descriptor));
 
   //  pkts
   fieldLen = (this->_descriptor >> 3) + 1;
@@ -228,7 +228,7 @@
 //-------------------------------------------------------------------------
 //      int ArtsProtocolTableEntry::read(int fd, uint8_t version = 0)
 //-------------------------------------------------------------------------
-int ArtsProtocolTableEntry::read(int fd, uint8_t version = 0)
+int ArtsProtocolTableEntry::read(int fd, uint8_t version)
 {
   uint8_t  fieldLen;
   int      rc = 0;
@@ -259,15 +259,15 @@
 //                                           uint8_t version = 0) const
 //-------------------------------------------------------------------------
 ostream& ArtsProtocolTableEntry::write(ostream& os,
-                                       uint8_t version = 0) const
+                                       uint8_t version) const
 {
   uint8_t  fieldLen;
 
   //  protocol number
-  os.write(&this->_protocolNum,sizeof(this->_protocolNum));
+  os.write((char *)&this->_protocolNum,sizeof(this->_protocolNum));
   
   //  descriptor
-  os.write(&this->_descriptor,1);
+  os.write((char *)&this->_descriptor,1);
   
   //  pkts
   fieldLen = (this->_descriptor >> 3) + 1;
@@ -283,7 +283,7 @@
 //-------------------------------------------------------------------------
 //  int ArtsProtocolTableEntry::write(int fd, uint8_t version = 0) const
 //-------------------------------------------------------------------------
-int ArtsProtocolTableEntry::write(int fd, uint8_t version = 0) const
+int ArtsProtocolTableEntry::write(int fd, uint8_t version) const
 {
   uint8_t  fieldLen;
   int      rc = 0;
