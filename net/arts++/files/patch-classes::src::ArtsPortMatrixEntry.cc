--- ./classes/src/ArtsPortMatrixEntry.cc.orig	Mon Oct  2 13:05:27 2000
+++ ./classes/src/ArtsPortMatrixEntry.cc	Wed Sep 25 16:38:10 2002
@@ -176,7 +176,7 @@
 //.........................................................................
 //                                                                         
 //-------------------------------------------------------------------------
-uint32_t ArtsPortMatrixEntry::Length(uint8_t version = 0) const
+uint32_t ArtsPortMatrixEntry::Length(uint8_t version) const
 {
   uint32_t   length;
 
@@ -189,18 +189,18 @@
 }
 
 //-------------------------------------------------------------------------
-//   istream& ArtsPortMatrixEntry::read(istream& is, uint8_t version = 0)
+//   istream& ArtsPortMatrixEntry::read(istream& is, uint8_t version)
 //.........................................................................
 //                                                                         
 //-------------------------------------------------------------------------
-istream& ArtsPortMatrixEntry::read(istream& is, uint8_t version = 0)
+istream& ArtsPortMatrixEntry::read(istream& is, uint8_t version)
 {
   uint8_t        bytesize,
                  pktsize,
                  srcsize,
                  dstsize;
   
-  is.read(&this->_descriptor,sizeof(this->_descriptor));
+  is.read((char *)&this->_descriptor,sizeof(this->_descriptor));
 
   srcsize = (this->_descriptor & 0x01) + 1;
   dstsize  = ((this->_descriptor >> 1) & 0x01) + 1;
@@ -220,7 +220,7 @@
 //.........................................................................
 //                                                                         
 //-------------------------------------------------------------------------
-int ArtsPortMatrixEntry::read(int fd, uint8_t version = 0)
+int ArtsPortMatrixEntry::read(int fd, uint8_t version)
 {
   uint8_t        bytesize,
                  pktsize,
@@ -273,14 +273,14 @@
 //.........................................................................
 //                                                                         
 //-------------------------------------------------------------------------
-ostream & ArtsPortMatrixEntry::write(ostream & os, uint8_t version = 0) const
+ostream & ArtsPortMatrixEntry::write(ostream & os, uint8_t version) const
 {
   uint8_t        bytesize,
                  pktsize,
                  srcsize,
                  dstsize;
 
-  os.write(&this->_descriptor,sizeof(this->_descriptor));
+  os.write((char *)&this->_descriptor,sizeof(this->_descriptor));
 
   srcsize = (this->_descriptor & 0x01) + 1;
   dstsize  = ((this->_descriptor >> 1) & 0x01) + 1;
@@ -300,7 +300,7 @@
 //.........................................................................
 //                                                                         
 //-------------------------------------------------------------------------
-int ArtsPortMatrixEntry::write(int fd, uint8_t version = 0) const
+int ArtsPortMatrixEntry::write(int fd, uint8_t version) const
 {
   uint8_t        bytesize,
                  pktsize,
