--- ./classes/src/ArtsProtocolTableData.cc.orig	Mon Oct  2 13:05:28 2000
+++ ./classes/src/ArtsProtocolTableData.cc	Wed Sep 25 16:38:10 2002
@@ -182,7 +182,7 @@
 //.........................................................................
 //  
 //-------------------------------------------------------------------------
-uint32_t ArtsProtocolTableData::ComputeLength(uint8_t version = 0) const
+uint32_t ArtsProtocolTableData::ComputeLength(uint8_t version) const
 {
   this->_length = 0;
   
@@ -205,18 +205,18 @@
 //.........................................................................
 //  
 //-------------------------------------------------------------------------
-uint32_t ArtsProtocolTableData::Length(uint8_t version = 0) const
+uint32_t ArtsProtocolTableData::Length(uint8_t version) const
 {
   this->ComputeLength(version);
   return(this->_length);
 }
 
 //-------------------------------------------------------------------------
-// istream& ArtsProtocolTableData::read(istream& is, uint8_t version = 0)
+// istream& ArtsProtocolTableData::read(istream& is, uint8_t version)
 //.........................................................................
 //  
 //-------------------------------------------------------------------------
-istream& ArtsProtocolTableData::read(istream& is, uint8_t version = 0)
+istream& ArtsProtocolTableData::read(istream& is, uint8_t version)
 {
   uint32_t            numProtocols;
   uint32_t            protocolNum;
@@ -239,7 +239,7 @@
 //.........................................................................
 //  
 //-------------------------------------------------------------------------
-int ArtsProtocolTableData::read(int fd, uint8_t version = 0)
+int ArtsProtocolTableData::read(int fd, uint8_t version)
 {
   uint32_t            numProtocols;
   uint32_t            protocolNum;
@@ -281,7 +281,7 @@
 //  
 //-------------------------------------------------------------------------
 ostream& ArtsProtocolTableData::write(ostream& os,
-                                      uint8_t version = 0) const
+                                      uint8_t version) const
 {
   uint32_t            numProtocols;
   
@@ -306,7 +306,7 @@
 //.........................................................................
 //  
 //-------------------------------------------------------------------------
-int ArtsProtocolTableData::write(int fd, uint8_t version = 0) const
+int ArtsProtocolTableData::write(int fd, uint8_t version) const
 {
   uint32_t      numProtocols;
   int           rc;
