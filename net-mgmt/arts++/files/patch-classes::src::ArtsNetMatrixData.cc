--- ./classes/src/ArtsNetMatrixData.cc.orig	Mon Oct  2 13:05:25 2000
+++ ./classes/src/ArtsNetMatrixData.cc	Wed Sep 25 16:38:10 2002
@@ -83,7 +83,7 @@
 //.........................................................................
 //                                                                         
 //-------------------------------------------------------------------------
-istream & ArtsNetMatrixData::read(istream& is, uint8_t version = 2)
+istream & ArtsNetMatrixData::read(istream& is, uint8_t version)
 {
   uint32_t           entryNum;
   ArtsNetMatrixEntry  netEntry;
@@ -108,7 +108,7 @@
 //.........................................................................
 //                                                                         
 //-------------------------------------------------------------------------
-int ArtsNetMatrixData::read(int fd, uint8_t version = 2)
+int ArtsNetMatrixData::read(int fd, uint8_t version)
 {
   uint32_t           entryNum;
   ArtsNetMatrixEntry  netEntry;
@@ -163,7 +163,7 @@
 //.........................................................................
 //                                                                         
 //-------------------------------------------------------------------------
-ostream & ArtsNetMatrixData::write(ostream& os, uint8_t version = 2)
+ostream & ArtsNetMatrixData::write(ostream& os, uint8_t version)
 {
   uint32_t       entryNum;
 
@@ -185,7 +185,7 @@
 //.........................................................................
 //
 //-------------------------------------------------------------------------
-int ArtsNetMatrixData::write(int fd, uint8_t version = 2)
+int ArtsNetMatrixData::write(int fd, uint8_t version)
 {
   uint32_t       entryNum;
   int            rc;
@@ -237,7 +237,7 @@
 //.........................................................................
 //                                                                         
 //-------------------------------------------------------------------------
-uint32_t ArtsNetMatrixData::Length(uint8_t version = 2) const
+uint32_t ArtsNetMatrixData::Length(uint8_t version) const
 {
   uint32_t  length = 0;
 
