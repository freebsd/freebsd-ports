--- ./classes/src/ArtsPortMatrixData.cc.orig	Mon Oct  2 13:05:27 2000
+++ ./classes/src/ArtsPortMatrixData.cc	Wed Sep 25 16:38:10 2002
@@ -82,7 +82,7 @@
 //.........................................................................
 //                                                                         
 //-------------------------------------------------------------------------
-istream & ArtsPortMatrixData::read(istream& is, uint8_t version = 0)
+istream & ArtsPortMatrixData::read(istream& is, uint8_t version)
 {
   uint32_t             entryNum;
   ArtsPortMatrixEntry  portEntry;
@@ -107,7 +107,7 @@
 //.........................................................................
 //                                                                         
 //-------------------------------------------------------------------------
-int ArtsPortMatrixData::read(int fd, uint8_t version = 0)
+int ArtsPortMatrixData::read(int fd, uint8_t version)
 {
   uint32_t             entryNum;
   ArtsPortMatrixEntry  portEntry;
@@ -162,7 +162,7 @@
 //.........................................................................
 //                                                                         
 //-------------------------------------------------------------------------
-ostream & ArtsPortMatrixData::write(ostream& os, uint8_t version = 0)
+ostream & ArtsPortMatrixData::write(ostream& os, uint8_t version)
 {
   uint32_t       entryNum;
 
@@ -180,11 +180,11 @@
 }
 
 //-------------------------------------------------------------------------
-//       int ArtsPortMatrixData::write(int fd, uint8_t version = 0)
+//       int ArtsPortMatrixData::write(int fd, uint8_t version)
 //.........................................................................
 //                                                                         
 //-------------------------------------------------------------------------
-int ArtsPortMatrixData::write(int fd, uint8_t version = 0)
+int ArtsPortMatrixData::write(int fd, uint8_t version)
 {
   uint32_t       entryNum;
   int            rc;
@@ -236,7 +236,7 @@
 //.........................................................................
 //                                                                         
 //-------------------------------------------------------------------------
-uint32_t ArtsPortMatrixData::Length(uint8_t version = 0) const
+uint32_t ArtsPortMatrixData::Length(uint8_t version) const
 {
   uint32_t  length = 0;
 
