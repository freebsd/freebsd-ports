--- ./classes/src/ArtsPortTableEntry.cc.orig	Mon Oct  2 13:05:28 2000
+++ ./classes/src/ArtsPortTableEntry.cc	Wed Sep 25 16:38:10 2002
@@ -332,7 +332,7 @@
 //-------------------------------------------------------------------------
 //      uint32_t ArtsPortTableEntry::Length(uint8_t version = 0) const
 //-------------------------------------------------------------------------
-uint32_t ArtsPortTableEntry::Length(uint8_t version = 0) const
+uint32_t ArtsPortTableEntry::Length(uint8_t version) const
 {
   uint32_t  len = 0;
 
@@ -349,7 +349,7 @@
 //-------------------------------------------------------------------------
 //   istream& ArtsPortTableEntry::read(istream& is, uint8_t version = 0)
 //-------------------------------------------------------------------------
-istream& ArtsPortTableEntry::read(istream& is, uint8_t version = 0)
+istream& ArtsPortTableEntry::read(istream& is, uint8_t version)
 {
   uint8_t  fieldLen;
 
@@ -358,7 +358,7 @@
                                          sizeof(this->_portNum));
   
   //  descriptor
-  is.read(&this->_descriptor,sizeof(this->_descriptor));
+  is.read((char *)&this->_descriptor,sizeof(this->_descriptor));
 
   //  inPkts
   fieldLen = 1 << (this->_descriptor >> 6);
@@ -382,7 +382,7 @@
 //-------------------------------------------------------------------------
 //        int ArtsPortTableEntry::read(int fd, uint8_t version = 0)
 //-------------------------------------------------------------------------
-int ArtsPortTableEntry::read(int fd, uint8_t version = 0)
+int ArtsPortTableEntry::read(int fd, uint8_t version)
 {
   uint8_t  fieldLen;
   int      rc = 0;
@@ -421,7 +421,7 @@
 //                                        uint8_t version = 0) const          
 //-------------------------------------------------------------------------
 ostream& ArtsPortTableEntry::write(ostream& os,
-                                   uint8_t version = 0) const
+                                   uint8_t version) const
 {
   uint8_t  fieldLen;
 
@@ -430,7 +430,7 @@
                                           sizeof(this->_portNum));
   
   //  descriptor
-  os.write(&this->_descriptor,1);
+  os.write((char *)&this->_descriptor,1);
   
   //  inPkts
   fieldLen = 1 << (this->_descriptor >> 6);
@@ -454,7 +454,7 @@
 //-------------------------------------------------------------------------
 //    int ArtsPortTableEntry::write(int fd, uint8_t version = 0) const
 //-------------------------------------------------------------------------
-int ArtsPortTableEntry::write(int fd, uint8_t version = 0) const
+int ArtsPortTableEntry::write(int fd, uint8_t version) const
 {
   uint8_t  fieldLen;
   int      rc = 0;
