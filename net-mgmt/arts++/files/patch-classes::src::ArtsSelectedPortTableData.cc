--- ./classes/src/ArtsSelectedPortTableData.cc.orig	Mon Oct  2 13:05:29 2000
+++ ./classes/src/ArtsSelectedPortTableData.cc	Wed Sep 25 16:38:10 2002
@@ -188,7 +188,7 @@
 //  
 //-------------------------------------------------------------------------
 uint32_t
-ArtsSelectedPortTableData::ComputeLength(uint8_t version = 0) const
+ArtsSelectedPortTableData::ComputeLength(uint8_t version) const
 {
   this->_length = 0;
   
@@ -214,7 +214,7 @@
 //.........................................................................
 //  
 //-------------------------------------------------------------------------
-uint32_t ArtsSelectedPortTableData::Length(uint8_t version = 0) const
+uint32_t ArtsSelectedPortTableData::Length(uint8_t version) const
 {
   this->ComputeLength(version);
   return(this->_length);
@@ -227,7 +227,7 @@
 //  
 //-------------------------------------------------------------------------
 istream& ArtsSelectedPortTableData::read(istream& is,
-                                         uint8_t version = 0)
+                                         uint8_t version)
 {
   uint32_t            numPorts;
   uint32_t            portNum;
@@ -251,7 +251,7 @@
 //.........................................................................
 //  
 //-------------------------------------------------------------------------
-int ArtsSelectedPortTableData::read(int fd, uint8_t version = 0)
+int ArtsSelectedPortTableData::read(int fd, uint8_t version)
 {
   uint32_t            numPorts;
   uint32_t            portNum;
@@ -298,7 +298,7 @@
 //  
 //-------------------------------------------------------------------------
 ostream& ArtsSelectedPortTableData::write(ostream& os,
-                                  uint8_t version = 0) const
+                                  uint8_t version) const
 {
   uint32_t                                    numPorts;
   vector<ArtsPortTableEntry>::const_iterator  portEntry;
@@ -323,7 +323,7 @@
 //.........................................................................
 //  
 //-------------------------------------------------------------------------
-int ArtsSelectedPortTableData::write(int fd, uint8_t version = 0) const
+int ArtsSelectedPortTableData::write(int fd, uint8_t version) const
 {
   uint32_t      numPorts;
   int           rc;
