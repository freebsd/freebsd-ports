--- ./classes/src/ArtsInterfaceMatrixData.cc.orig	Mon Oct  2 13:05:24 2000
+++ ./classes/src/ArtsInterfaceMatrixData.cc	Wed Sep 25 16:38:10 2002
@@ -81,7 +81,7 @@
 //.........................................................................
 //                                                                         
 //-------------------------------------------------------------------------
-istream & ArtsInterfaceMatrixData::read(istream& is, uint8_t version = 0)
+istream & ArtsInterfaceMatrixData::read(istream& is, uint8_t version)
 {
   uint32_t                  entryNum;
   ArtsInterfaceMatrixEntry  interfaceEntry;
@@ -106,7 +106,7 @@
 //.........................................................................
 //                                                                         
 //-------------------------------------------------------------------------
-int ArtsInterfaceMatrixData::read(int fd, uint8_t version = 0)
+int ArtsInterfaceMatrixData::read(int fd, uint8_t version)
 {
   uint32_t                  entryNum;
   //  ArtsPrimitive             ioHelper;
@@ -163,7 +163,7 @@
 //                                                                         
 //-------------------------------------------------------------------------
 ostream & ArtsInterfaceMatrixData::write(ostream& os,
-                                         uint8_t version = 0)
+                                         uint8_t version)
 {
   uint32_t       entryNum;
 
@@ -185,7 +185,7 @@
 //.........................................................................
 //                                                                         
 //-------------------------------------------------------------------------
-int ArtsInterfaceMatrixData::write(int fd, uint8_t version = 0)
+int ArtsInterfaceMatrixData::write(int fd, uint8_t version)
 {
   uint32_t       entryNum;
   int            rc;
@@ -237,7 +237,7 @@
 //.........................................................................
 //                                                                         
 //-------------------------------------------------------------------------
-uint32_t ArtsInterfaceMatrixData::Length(uint8_t version = 0) const
+uint32_t ArtsInterfaceMatrixData::Length(uint8_t version) const
 {
   uint32_t  length = 0;
 
