--- ./classes/src/ArtsNetMatrixEntry.cc.orig	Mon Oct  2 13:05:25 2000
+++ ./classes/src/ArtsNetMatrixEntry.cc	Wed Sep 25 16:38:10 2002
@@ -186,7 +186,7 @@
 //.........................................................................
 //                                                                         
 //-------------------------------------------------------------------------
-uint32_t ArtsNetMatrixEntry::Length(uint8_t version = 2) const
+uint32_t ArtsNetMatrixEntry::Length(uint8_t version) const
 {
   uint32_t   length;
 
@@ -203,7 +203,7 @@
 //.........................................................................
 //                                                                         
 //-------------------------------------------------------------------------
-istream& ArtsNetMatrixEntry::read(istream& is, uint8_t version = 2)
+istream& ArtsNetMatrixEntry::read(istream& is, uint8_t version)
 {
   uint8_t        bytesize,
                  pktsize,
@@ -212,7 +212,7 @@
                  dstsize,
                  dstmasklen;
   
-  is.read(&this->_descriptor,sizeof(this->_descriptor));
+  is.read((char *)&this->_descriptor,sizeof(this->_descriptor));
   this->_descriptor = ntohs(this->_descriptor);
   
   srcmasklen = ((this->_descriptor >> 5) & 0x1f) + 1;
@@ -237,7 +237,7 @@
 //.........................................................................
 //                                                                         
 //-------------------------------------------------------------------------
-int ArtsNetMatrixEntry::read(int fd, uint8_t version = 2)
+int ArtsNetMatrixEntry::read(int fd, uint8_t version)
 {
   uint8_t        bytesize,
                  pktsize,
@@ -298,7 +298,7 @@
 //.........................................................................
 //                                                                         
 //-------------------------------------------------------------------------
-ostream & ArtsNetMatrixEntry::write(ostream & os, uint8_t version = 2) const
+ostream & ArtsNetMatrixEntry::write(ostream & os, uint8_t version) const
 {
   uint8_t        bytesize,
                  pktsize,
@@ -309,7 +309,7 @@
   uint16_t       tmpDescriptor;
 
   tmpDescriptor = htons(this->_descriptor);
-  os.write(&tmpDescriptor,sizeof(tmpDescriptor));
+  os.write((char *)&tmpDescriptor,sizeof(tmpDescriptor));
 
   srcmasklen = ((this->_descriptor >> 5) & 0x1f) + 1;
   srcsize = (srcmasklen + 7) / 8;
@@ -333,7 +333,7 @@
 //.........................................................................
 //                                                                         
 //-------------------------------------------------------------------------
-int ArtsNetMatrixEntry::write(int fd, uint8_t version = 2) const
+int ArtsNetMatrixEntry::write(int fd, uint8_t version) const
 {
   uint8_t        bytesize,
                  pktsize,
