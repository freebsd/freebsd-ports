--- ./classes/src/ArtsBgp4AsPathAttribute.cc.orig	Mon Oct  2 13:05:22 2000
+++ ./classes/src/ArtsBgp4AsPathAttribute.cc	Wed Sep 25 16:38:10 2002
@@ -117,7 +117,7 @@
 //............................................................................
 //  
 //----------------------------------------------------------------------------
-istream & ArtsBgp4AsPathAttribute::read(istream & is, uint8_t version = 0)
+istream & ArtsBgp4AsPathAttribute::read(istream & is, uint8_t version)
 {
   ArtsBgp4AsPathSegment  asPathSegment;
   uint8_t                numSegments;
@@ -125,7 +125,7 @@
   if (this->_segments.size() > 0)
     this->_segments.erase(this->_segments.begin(),this->_segments.end());
   
-  is.read(&numSegments,sizeof(numSegments));
+  is.read((char *)&numSegments,sizeof(numSegments));
   if (numSegments > 0) {
     this->_segments.reserve(numSegments);
     for (uint8_t segmentNum = 0; segmentNum < numSegments; segmentNum++) {
@@ -144,7 +144,7 @@
 //............................................................................
 //  
 //----------------------------------------------------------------------------
-int ArtsBgp4AsPathAttribute::read(int fd, uint8_t version = 0)
+int ArtsBgp4AsPathAttribute::read(int fd, uint8_t version)
 {
   int                    rc;
   int                    bytesRead = 0;
@@ -175,10 +175,10 @@
 //  
 //----------------------------------------------------------------------------
 ostream & ArtsBgp4AsPathAttribute::write(ostream & os,
-                                         uint8_t version = 0) const
+                                         uint8_t version) const
 {
   uint8_t                numSegments = this->_segments.size();
-  os.write(&numSegments,sizeof(numSegments));
+  os.write((char *)&numSegments,sizeof(numSegments));
   for (uint8_t segmentNum = 0; segmentNum < numSegments; segmentNum++) {
     this->_segments[segmentNum].write(os,version);
   }
@@ -190,7 +190,7 @@
 //............................................................................
 //  
 //----------------------------------------------------------------------------
-int ArtsBgp4AsPathAttribute::write(int fd, uint8_t version = 0) const
+int ArtsBgp4AsPathAttribute::write(int fd, uint8_t version) const
 {
   int        rc;
   int        bytesWritten = 0;
@@ -232,7 +232,7 @@
 //............................................................................
 //  
 //----------------------------------------------------------------------------
-uint32_t ArtsBgp4AsPathAttribute::Length(uint8_t version = 0) const
+uint32_t ArtsBgp4AsPathAttribute::Length(uint8_t version) const
 {
   uint32_t  length = sizeof(uint8_t);
 
