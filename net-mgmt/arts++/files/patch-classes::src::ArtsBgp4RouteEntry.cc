--- ./classes/src/ArtsBgp4RouteEntry.cc.orig	Mon Oct  2 13:05:23 2000
+++ ./classes/src/ArtsBgp4RouteEntry.cc	Wed Sep 25 16:38:10 2002
@@ -122,7 +122,7 @@
 //............................................................................
 //  
 //----------------------------------------------------------------------------
-istream & ArtsBgp4RouteEntry::read(istream & is, uint8_t version = 0)
+istream & ArtsBgp4RouteEntry::read(istream & is, uint8_t version)
 {
   ArtsBgp4Attribute  bgp4Attribute;
 
@@ -186,7 +186,7 @@
 //............................................................................
 //  
 //----------------------------------------------------------------------------
-int ArtsBgp4RouteEntry::read(int fd, uint8_t version = 0)
+int ArtsBgp4RouteEntry::read(int fd, uint8_t version)
 {
   int                rc;
   ArtsBgp4Attribute  bgp4Attribute;
@@ -291,7 +291,7 @@
 //............................................................................
 //  
 //----------------------------------------------------------------------------
-ostream & ArtsBgp4RouteEntry::write(ostream & os, uint8_t version = 0) const
+ostream & ArtsBgp4RouteEntry::write(ostream & os, uint8_t version) const
 {
   g_ArtsLibInternal_Primitive.WriteUint32(os,this->_attrIndex,
                                           sizeof(this->_attrIndex));
@@ -309,7 +309,7 @@
 //............................................................................
 //  
 //----------------------------------------------------------------------------
-int ArtsBgp4RouteEntry::write(int fd, uint8_t version = 0) const
+int ArtsBgp4RouteEntry::write(int fd, uint8_t version) const
 {
   int   rc;
   int   bytesWritten = 0;
@@ -337,7 +337,7 @@
 //............................................................................
 //  
 //----------------------------------------------------------------------------
-uint32_t ArtsBgp4RouteEntry::Length(uint8_t version = 0) const
+uint32_t ArtsBgp4RouteEntry::Length(uint8_t version) const
 {
   uint32_t  length = sizeof(this->_attrIndex);
   vector<ArtsBgp4Attribute>::const_iterator  bgp4AttrIter;
