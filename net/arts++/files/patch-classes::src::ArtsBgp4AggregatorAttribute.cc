--- ./classes/src/ArtsBgp4AggregatorAttribute.cc.orig	Mon Oct  2 13:05:22 2000
+++ ./classes/src/ArtsBgp4AggregatorAttribute.cc	Wed Sep 25 16:38:10 2002
@@ -154,10 +154,10 @@
 //  
 //----------------------------------------------------------------------------
 istream & ArtsBgp4AggregatorAttribute::read(istream & is,
-                                            uint8_t version = 0)
+                                            uint8_t version)
 {
   g_ArtsLibInternal_Primitive.ReadUint16(is,this->_AS,sizeof(this->_AS));
-  is.read(&this->_ipAddr,sizeof(this->_ipAddr));
+  is.read((char *)&this->_ipAddr,sizeof(this->_ipAddr));
   return(is);
 }
 
@@ -166,7 +166,7 @@
 //............................................................................
 //  
 //----------------------------------------------------------------------------
-int ArtsBgp4AggregatorAttribute::read(int fd, uint8_t version = 0)
+int ArtsBgp4AggregatorAttribute::read(int fd, uint8_t version)
 {
   int  rc;
   int  bytesRead = 0;
@@ -190,10 +190,10 @@
 //
 //----------------------------------------------------------------------------
 ostream & ArtsBgp4AggregatorAttribute::write(ostream & os,
-                                             uint8_t version = 0) const
+                                             uint8_t version) const
 {
   g_ArtsLibInternal_Primitive.WriteUint16(os,this->_AS,sizeof(this->_AS));
-  os.write(&this->_ipAddr,sizeof(this->_ipAddr));
+  os.write((char *)&this->_ipAddr,sizeof(this->_ipAddr));
   return(os);
 }
 
@@ -202,7 +202,7 @@
 //............................................................................
 //  
 //----------------------------------------------------------------------------
-int ArtsBgp4AggregatorAttribute::write(int fd, uint8_t version = 0) const
+int ArtsBgp4AggregatorAttribute::write(int fd, uint8_t version) const
 {
   int  rc;
   int  bytesWritten = 0;
@@ -225,7 +225,7 @@
 //............................................................................
 //  
 //----------------------------------------------------------------------------
-uint32_t ArtsBgp4AggregatorAttribute::Length(uint8_t version = 0) const
+uint32_t ArtsBgp4AggregatorAttribute::Length(uint8_t version) const
 {
   return(sizeof(this->_AS) + sizeof(this->_ipAddr));
 }
