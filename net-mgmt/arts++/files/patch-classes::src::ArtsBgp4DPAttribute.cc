--- ./classes/src/ArtsBgp4DPAttribute.cc.orig	Mon Oct  2 13:05:23 2000
+++ ./classes/src/ArtsBgp4DPAttribute.cc	Wed Sep 25 16:38:10 2002
@@ -132,7 +132,7 @@
 //............................................................................
 //  
 //----------------------------------------------------------------------------
-istream & ArtsBgp4DPAttribute::read(istream & is, uint8_t version = 0)
+istream & ArtsBgp4DPAttribute::read(istream & is, uint8_t version)
 {
   g_ArtsLibInternal_Primitive.ReadUint16(is,this->_as,sizeof(this->_as));
   g_ArtsLibInternal_Primitive.ReadUint32(is,this->_value,
@@ -145,7 +145,7 @@
 //............................................................................
 //  
 //----------------------------------------------------------------------------
-int ArtsBgp4DPAttribute::read(int fd, uint8_t version = 0)
+int ArtsBgp4DPAttribute::read(int fd, uint8_t version)
 {
   int   rc;
   int   bytesRead = 0;
@@ -169,7 +169,7 @@
 //............................................................................
 //  
 //----------------------------------------------------------------------------
-ostream & ArtsBgp4DPAttribute::write(ostream & os, uint8_t version = 0) const
+ostream & ArtsBgp4DPAttribute::write(ostream & os, uint8_t version) const
 {
   g_ArtsLibInternal_Primitive.WriteUint16(os,this->_as,sizeof(this->_as));
   g_ArtsLibInternal_Primitive.WriteUint32(os,this->_value,
@@ -182,7 +182,7 @@
 //............................................................................
 //  
 //----------------------------------------------------------------------------
-int ArtsBgp4DPAttribute::write(int fd, uint8_t version = 0) const
+int ArtsBgp4DPAttribute::write(int fd, uint8_t version) const
 {
   int   rc;
   int   bytesWritten = 0;
