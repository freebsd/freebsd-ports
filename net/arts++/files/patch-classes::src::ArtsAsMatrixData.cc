--- ./classes/src/ArtsAsMatrixData.cc.orig	Mon Oct  2 13:05:22 2000
+++ ./classes/src/ArtsAsMatrixData.cc	Wed Sep 25 16:38:10 2002
@@ -81,7 +81,7 @@
 //.........................................................................
 //                                                                         
 //-------------------------------------------------------------------------
-istream & ArtsAsMatrixData::read(istream& is, uint8_t version = 0)
+istream & ArtsAsMatrixData::read(istream& is, uint8_t version)
 {
   uint32_t           entryNum;
   ArtsAsMatrixEntry  asEntry;
@@ -106,7 +106,7 @@
 //.........................................................................
 //                                                                         
 //-------------------------------------------------------------------------
-int ArtsAsMatrixData::read(int fd, uint8_t version = 0)
+int ArtsAsMatrixData::read(int fd, uint8_t version)
 {
   uint32_t           entryNum;
   ArtsAsMatrixEntry  asEntry;
@@ -161,7 +161,7 @@
 //.........................................................................
 //                                                                         
 //-------------------------------------------------------------------------
-ostream & ArtsAsMatrixData::write(ostream& os, uint8_t version = 0)
+ostream & ArtsAsMatrixData::write(ostream& os, uint8_t version)
 {
   uint32_t       entryNum;
 
@@ -183,7 +183,7 @@
 //.........................................................................
 //                                                                         
 //-------------------------------------------------------------------------
-int ArtsAsMatrixData::write(int fd, uint8_t version = 0)
+int ArtsAsMatrixData::write(int fd, uint8_t version)
 {
   uint32_t       entryNum;
   int            rc;
@@ -235,7 +235,7 @@
 //.........................................................................
 //                                                                         
 //-------------------------------------------------------------------------
-uint32_t ArtsAsMatrixData::Length(uint8_t version = 0) const
+uint32_t ArtsAsMatrixData::Length(uint8_t version) const
 {
   uint32_t  length = 0;
 
