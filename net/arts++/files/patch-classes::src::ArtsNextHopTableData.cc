--- ./classes/src/ArtsNextHopTableData.cc.orig	Mon Oct  2 13:05:26 2000
+++ ./classes/src/ArtsNextHopTableData.cc	Wed Sep 25 16:38:10 2002
@@ -182,7 +182,7 @@
 //.........................................................................
 //  
 //-------------------------------------------------------------------------
-uint32_t ArtsNextHopTableData::ComputeLength(uint8_t version = 0) const
+uint32_t ArtsNextHopTableData::ComputeLength(uint8_t version) const
 {
   this->_length = 0;
   
@@ -205,7 +205,7 @@
 //.........................................................................
 //  
 //-------------------------------------------------------------------------
-uint32_t ArtsNextHopTableData::Length(uint8_t version = 0) const
+uint32_t ArtsNextHopTableData::Length(uint8_t version) const
 {
   this->ComputeLength(version);
   return(this->_length);
@@ -216,7 +216,7 @@
 //.........................................................................
 //  
 //-------------------------------------------------------------------------
-istream& ArtsNextHopTableData::read(istream& is, uint8_t version = 0)
+istream& ArtsNextHopTableData::read(istream& is, uint8_t version)
 {
   uint32_t            numNextHops;
   uint32_t            NextHopNum;
@@ -239,7 +239,7 @@
 //.........................................................................
 //  
 //-------------------------------------------------------------------------
-int ArtsNextHopTableData::read(int fd, uint8_t version = 0)
+int ArtsNextHopTableData::read(int fd, uint8_t version)
 {
   uint32_t            numNextHops;
   uint32_t            NextHopNum;
@@ -281,7 +281,7 @@
 //  
 //-------------------------------------------------------------------------
 ostream& ArtsNextHopTableData::write(ostream& os,
-                                      uint8_t version = 0) const
+                                      uint8_t version) const
 {
   uint32_t            numNextHops;
   
@@ -306,7 +306,7 @@
 //.........................................................................
 //  
 //-------------------------------------------------------------------------
-int ArtsNextHopTableData::write(int fd, uint8_t version = 0) const
+int ArtsNextHopTableData::write(int fd, uint8_t version) const
 {
   uint32_t      numNextHops;
   int           rc;
