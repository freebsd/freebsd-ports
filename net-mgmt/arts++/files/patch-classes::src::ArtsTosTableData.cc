--- ./classes/src/ArtsTosTableData.cc.orig	Mon Oct  2 13:05:29 2000
+++ ./classes/src/ArtsTosTableData.cc	Wed Sep 25 16:38:10 2002
@@ -166,7 +166,7 @@
 //-------------------------------------------------------------------------
 //   uint32_t ArtsTosTableEntry::Length(uint8_t version = 0) const
 //-------------------------------------------------------------------------
-uint32_t ArtsTosTableEntry::Length(uint8_t version = 0) const
+uint32_t ArtsTosTableEntry::Length(uint8_t version) const
 {
   uint32_t  len = 0;
 
@@ -181,15 +181,15 @@
 //-------------------------------------------------------------------------
 // istream& ArtsTosTableEntry::read(istream& is, uint8_t version = 0)
 //-------------------------------------------------------------------------
-istream& ArtsTosTableEntry::read(istream& is, uint8_t version = 0)
+istream& ArtsTosTableEntry::read(istream& is, uint8_t version)
 {
   uint8_t  fieldLen;
 
   //  tos number
-  is.read(&this->_tosNum,sizeof(this->_tosNum));
+  is.read((char *)&this->_tosNum,sizeof(this->_tosNum));
   
   //  descriptor
-  is.read(&this->_descriptor,sizeof(this->_descriptor));
+  is.read((char *)&this->_descriptor,sizeof(this->_descriptor));
 
   //  pkts
   fieldLen = (this->_descriptor >> 3) + 1;
@@ -205,7 +205,7 @@
 //-------------------------------------------------------------------------
 //      int ArtsTosTableEntry::read(int fd, uint8_t version = 0)
 //-------------------------------------------------------------------------
-int ArtsTosTableEntry::read(int fd, uint8_t version = 0)
+int ArtsTosTableEntry::read(int fd, uint8_t version)
 {
   uint8_t  fieldLen;
   int      rc = 0;
@@ -236,15 +236,15 @@
 //                                           uint8_t version = 0) const
 //-------------------------------------------------------------------------
 ostream& ArtsTosTableEntry::write(ostream& os,
-                                       uint8_t version = 0) const
+                                       uint8_t version) const
 {
   uint8_t  fieldLen;
 
   //  tos number
-  os.write(&this->_tosNum,sizeof(this->_tosNum));
+  os.write((char *)&this->_tosNum,sizeof(this->_tosNum));
   
   //  descriptor
-  os.write(&this->_descriptor,1);
+  os.write((char *)&this->_descriptor,1);
   
   //  pkts
   fieldLen = (this->_descriptor >> 3) + 1;
@@ -260,7 +260,7 @@
 //-------------------------------------------------------------------------
 //  int ArtsTosTableEntry::write(int fd, uint8_t version = 0) const
 //-------------------------------------------------------------------------
-int ArtsTosTableEntry::write(int fd, uint8_t version = 0) const
+int ArtsTosTableEntry::write(int fd, uint8_t version) const
 {
   uint8_t  fieldLen;
   int      rc = 0;
@@ -482,7 +482,7 @@
 //.........................................................................
 //  
 //-------------------------------------------------------------------------
-uint32_t ArtsTosTableData::ComputeLength(uint8_t version = 0) const
+uint32_t ArtsTosTableData::ComputeLength(uint8_t version) const
 {
   this->_length = 0;
   
@@ -505,7 +505,7 @@
 //.........................................................................
 //  
 //-------------------------------------------------------------------------
-uint32_t ArtsTosTableData::Length(uint8_t version = 0) const
+uint32_t ArtsTosTableData::Length(uint8_t version) const
 {
   this->ComputeLength(version);
   return(this->_length);
@@ -516,7 +516,7 @@
 //.........................................................................
 //  
 //-------------------------------------------------------------------------
-istream& ArtsTosTableData::read(istream& is, uint8_t version = 0)
+istream& ArtsTosTableData::read(istream& is, uint8_t version)
 {
   uint32_t            numToss;
   uint32_t            tosNum;
@@ -539,7 +539,7 @@
 //.........................................................................
 //  
 //-------------------------------------------------------------------------
-int ArtsTosTableData::read(int fd, uint8_t version = 0)
+int ArtsTosTableData::read(int fd, uint8_t version)
 {
   uint32_t            numToss;
   uint32_t            tosNum;
@@ -581,7 +581,7 @@
 //  
 //-------------------------------------------------------------------------
 ostream& ArtsTosTableData::write(ostream& os,
-                                      uint8_t version = 0) const
+                                      uint8_t version) const
 {
   uint32_t            numToss;
   
@@ -606,7 +606,7 @@
 //.........................................................................
 //  
 //-------------------------------------------------------------------------
-int ArtsTosTableData::write(int fd, uint8_t version = 0) const
+int ArtsTosTableData::write(int fd, uint8_t version) const
 {
   uint32_t      numToss;
   int           rc;
