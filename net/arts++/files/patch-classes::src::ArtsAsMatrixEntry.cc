--- ./classes/src/ArtsAsMatrixEntry.cc.orig	Mon Oct  2 13:05:22 2000
+++ ./classes/src/ArtsAsMatrixEntry.cc	Wed Sep 25 16:38:10 2002
@@ -180,7 +180,7 @@
 //.........................................................................
 //                                                                         
 //-------------------------------------------------------------------------
-uint32_t ArtsAsMatrixEntry::Length(uint8_t version = 0) const
+uint32_t ArtsAsMatrixEntry::Length(uint8_t version) const
 {
   uint32_t   length;
 
@@ -197,14 +197,14 @@
 //.........................................................................
 //                                                                         
 //-------------------------------------------------------------------------
-istream& ArtsAsMatrixEntry::read(istream& is, uint8_t version = 0)
+istream& ArtsAsMatrixEntry::read(istream& is, uint8_t version)
 {
   uint8_t        bytesize,
                  pktsize,
                  srcsize,
                  dstsize;
   
-  is.read(&this->_descriptor,sizeof(this->_descriptor));
+  is.read((char *)&this->_descriptor,sizeof(this->_descriptor));
 
   srcsize = (this->_descriptor & 0x01) + 1;
   dstsize  = ((this->_descriptor >> 1) & 0x01) + 1;
@@ -224,7 +224,7 @@
 //.........................................................................
 //                                                                         
 //-------------------------------------------------------------------------
-int ArtsAsMatrixEntry::read(int fd, uint8_t version = 0)
+int ArtsAsMatrixEntry::read(int fd, uint8_t version)
 {
   uint8_t        bytesize,
                  pktsize,
@@ -277,14 +277,14 @@
 //.........................................................................
 //                                                                         
 //-------------------------------------------------------------------------
-ostream & ArtsAsMatrixEntry::write(ostream & os, uint8_t version = 0) const
+ostream & ArtsAsMatrixEntry::write(ostream & os, uint8_t version) const
 {
   uint8_t        bytesize,
                  pktsize,
                  srcsize,
                  dstsize;
 
-  os.write(&this->_descriptor,sizeof(this->_descriptor));
+  os.write((char *)&this->_descriptor,sizeof(this->_descriptor));
 
   srcsize = (this->_descriptor & 0x01) + 1;
   dstsize  = ((this->_descriptor >> 1) & 0x01) + 1;
@@ -304,7 +304,7 @@
 //.........................................................................
 //                                                                         
 //-------------------------------------------------------------------------
-int ArtsAsMatrixEntry::write(int fd, uint8_t version = 0) const
+int ArtsAsMatrixEntry::write(int fd, uint8_t version) const
 {
   uint8_t        bytesize,
                  pktsize,
