--- ./classes/src/ArtsBgp4AsPathSegment.cc.orig	Mon Oct  2 13:05:23 2000
+++ ./classes/src/ArtsBgp4AsPathSegment.cc	Wed Sep 25 16:38:10 2002
@@ -137,13 +137,13 @@
 //............................................................................
 //  
 //----------------------------------------------------------------------------
-istream & ArtsBgp4AsPathSegment::read(istream & is, uint8_t version = 0)
+istream & ArtsBgp4AsPathSegment::read(istream & is, uint8_t version)
 {
   uint8_t   numAses;
   uint16_t  as;
 
-  is.read(&this->_type,sizeof(this->_type));
-  is.read(&numAses,sizeof(numAses));
+  is.read((char *)&this->_type,sizeof(this->_type));
+  is.read((char *)&numAses,sizeof(numAses));
   if (numAses > 0) {
     this->_AS.reserve(numAses);
     for (int asNum = 0; asNum < numAses; asNum++) {
@@ -160,7 +160,7 @@
 //............................................................................
 //  
 //----------------------------------------------------------------------------
-int ArtsBgp4AsPathSegment::read(int fd, uint8_t version = 0)
+int ArtsBgp4AsPathSegment::read(int fd, uint8_t version)
 {
   int       rc;
   uint8_t   numAses;
@@ -196,12 +196,12 @@
 //  
 //----------------------------------------------------------------------------
 ostream & ArtsBgp4AsPathSegment::write(ostream & os,
-                                       uint8_t version = 0) const
+                                       uint8_t version) const
 {
-  os.write(&this->_type,sizeof(this->_type));
+  os.write((char *)&this->_type,sizeof(this->_type));
   
   uint8_t   numAses = this->_AS.size();
-  os.write(&numAses,sizeof(numAses));
+  os.write((char *)&numAses,sizeof(numAses));
   
   for (int asNum = 0; asNum < numAses; asNum++) {
     g_ArtsLibInternal_Primitive.WriteUint16(os,this->_AS[asNum],
@@ -215,7 +215,7 @@
 //............................................................................
 //  
 //----------------------------------------------------------------------------
-int ArtsBgp4AsPathSegment::write(int fd, uint8_t version = 0) const
+int ArtsBgp4AsPathSegment::write(int fd, uint8_t version) const
 {
   int       rc;
   uint8_t   numAses;
@@ -246,7 +246,7 @@
 //............................................................................
 //  
 //----------------------------------------------------------------------------
-uint32_t ArtsBgp4AsPathSegment::Length(uint8_t version = 0) const
+uint32_t ArtsBgp4AsPathSegment::Length(uint8_t version) const
 {
   return(sizeof(this->_type) + sizeof(uint8_t) +
          (sizeof(uint16_t) * this->_AS.size()));
