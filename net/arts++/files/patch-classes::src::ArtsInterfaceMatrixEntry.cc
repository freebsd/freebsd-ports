--- ./classes/src/ArtsInterfaceMatrixEntry.cc.orig	Mon Oct  2 13:05:25 2000
+++ ./classes/src/ArtsInterfaceMatrixEntry.cc	Wed Sep 25 16:38:10 2002
@@ -214,7 +214,7 @@
 //.........................................................................
 //  
 //-------------------------------------------------------------------------
-uint32_t ArtsInterfaceMatrixEntry::Length(uint8_t version = 0) const
+uint32_t ArtsInterfaceMatrixEntry::Length(uint8_t version) const
 {
   uint32_t   length;
   length = (sizeof(this->_descriptor) +
@@ -231,11 +231,11 @@
 //.........................................................................
 //  
 //-------------------------------------------------------------------------
-istream & ArtsInterfaceMatrixEntry::read(istream& is, uint8_t version = 0)
+istream & ArtsInterfaceMatrixEntry::read(istream& is, uint8_t version)
 {
   uint8_t        bytesize, pktsize, srcsize, dstsize;
 
-  is.read(&this->_descriptor,sizeof(this->_descriptor));
+  is.read((char *)&this->_descriptor,sizeof(this->_descriptor));
   
   srcsize = (this->_descriptor & 0x01) + 1;
   dstsize  = ((this->_descriptor >> 1) & 0x01) + 1;
@@ -255,7 +255,7 @@
 //.........................................................................
 //  
 //-------------------------------------------------------------------------
-int ArtsInterfaceMatrixEntry::read(int fd, uint8_t version = 0)
+int ArtsInterfaceMatrixEntry::read(int fd, uint8_t version)
 {
   uint8_t        bytesize, pktsize, srcsize, dstsize;
   int            rc;
@@ -307,11 +307,11 @@
 //  
 //-------------------------------------------------------------------------
 ostream & ArtsInterfaceMatrixEntry::write(ostream& os,
-                                          uint8_t version = 0) const
+                                          uint8_t version) const
 {
   uint8_t        bytesize, pktsize, srcsize, dstsize;
 
-  os.write(&this->_descriptor,sizeof(this->_descriptor));
+  os.write((char *)&this->_descriptor,sizeof(this->_descriptor));
 
   srcsize = (this->_descriptor & 0x01) + 1;
   dstsize  = ((this->_descriptor >> 1) & 0x01) + 1;
@@ -331,7 +331,7 @@
 //.........................................................................
 //  
 //-------------------------------------------------------------------------
-int ArtsInterfaceMatrixEntry::write(int fd, uint8_t version = 0) const
+int ArtsInterfaceMatrixEntry::write(int fd, uint8_t version) const
 {
   uint8_t        bytesize, pktsize, srcsize, dstsize;
   int            rc;
