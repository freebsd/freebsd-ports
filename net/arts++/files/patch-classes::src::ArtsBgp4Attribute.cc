--- ./classes/src/ArtsBgp4Attribute.cc.orig	Mon Oct  2 13:05:23 2000
+++ ./classes/src/ArtsBgp4Attribute.cc	Wed Sep 25 16:38:10 2002
@@ -444,26 +444,26 @@
 //............................................................................
 //  
 //----------------------------------------------------------------------------
-istream & ArtsBgp4Attribute::read(istream & is, uint8_t version = 0)
+istream & ArtsBgp4Attribute::read(istream & is, uint8_t version)
 {
   uint8_t      numCommunities;
   uint32_t     community;
 
   this->DeleteValue();
   
-  is.read(&this->_flags,sizeof(this->_flags));
-  is.read(&this->_type,sizeof(this->_type));
+  is.read((char *)&this->_flags,sizeof(this->_flags));
+  is.read((char *)&this->_type,sizeof(this->_type));
   
   switch (this->_type) {
     case Bgp4_Attribute_Origin:
-      is.read(&this->_value._origin,sizeof(this->_value._origin));
+      is.read((char *)&this->_value._origin,sizeof(this->_value._origin));
       break;
     case Bgp4_Attribute_AsPath:
       this->_value._asPath = new ArtsBgp4AsPathAttribute;
       this->_value._asPath->read(is,version);
       break;
     case Bgp4_Attribute_NextHop:
-      is.read(&this->_value._nextHop,sizeof(this->_value._nextHop));
+      is.read((char *)&this->_value._nextHop,sizeof(this->_value._nextHop));
       break;
     case Bgp4_Attribute_MultiExitDisc:
       g_ArtsLibInternal_Primitive.ReadUint32(is,this->_value._MED,
@@ -480,7 +480,7 @@
       this->_value._aggregator->read(is,version);
       break;
     case Bgp4_Attribute_Community:
-      is.read(&numCommunities,sizeof(numCommunities));
+      is.read((char *)&numCommunities,sizeof(numCommunities));
       this->_value._community = new vector<uint32_t>;
       this->_value._community->reserve((int)numCommunities);
       for (int commNum = 0; commNum < numCommunities; commNum++) {
@@ -507,7 +507,7 @@
 //............................................................................
 //  
 //----------------------------------------------------------------------------
-int ArtsBgp4Attribute::read(int fd, uint8_t version = 0)
+int ArtsBgp4Attribute::read(int fd, uint8_t version)
 {
   uint8_t      numCommunities;
   uint32_t     community;
@@ -622,22 +622,22 @@
 //  
 //----------------------------------------------------------------------------
 ostream & ArtsBgp4Attribute::write(ostream & os,
-                                   uint8_t version = 0) const
+                                   uint8_t version) const
 {
   uint8_t  numCommunities;
   
-  os.write(&this->_flags,sizeof(this->_flags));
-  os.write(&this->_type,sizeof(this->_type));
+  os.write((char *)&this->_flags,sizeof(this->_flags));
+  os.write((char *)&this->_type,sizeof(this->_type));
 
     switch (this->_type) {
     case Bgp4_Attribute_Origin:
-      os.write(&this->_value._origin,sizeof(this->_value._origin));
+      os.write((char *)&this->_value._origin,sizeof(this->_value._origin));
       break;
     case Bgp4_Attribute_AsPath:
       this->_value._asPath->write(os,version);
       break;
     case Bgp4_Attribute_NextHop:
-      os.write(&this->_value._nextHop,sizeof(this->_value._nextHop));
+      os.write((char *)&this->_value._nextHop,sizeof(this->_value._nextHop));
       break;
     case Bgp4_Attribute_MultiExitDisc:
       g_ArtsLibInternal_Primitive.WriteUint32(os,this->_value._MED,
@@ -654,7 +654,7 @@
       break;
     case Bgp4_Attribute_Community:
       numCommunities = this->_value._community->size();
-      os.write(&numCommunities,sizeof(numCommunities));
+      os.write((char *)&numCommunities,sizeof(numCommunities));
       for (int commNum = 0; commNum < numCommunities; commNum++) {
         g_ArtsLibInternal_Primitive.WriteUint32(os,
                                         (*(this->_value._community))[commNum],
@@ -680,7 +680,7 @@
 //............................................................................
 //  
 //----------------------------------------------------------------------------
-int ArtsBgp4Attribute::write(int fd, uint8_t version = 0) const
+int ArtsBgp4Attribute::write(int fd, uint8_t version) const
 {
   uint8_t  numCommunities;
   int      rc;
@@ -855,7 +855,7 @@
 //............................................................................
 //  
 //----------------------------------------------------------------------------
-uint16_t ArtsBgp4Attribute::Length(uint8_t version = 0) const
+uint16_t ArtsBgp4Attribute::Length(uint8_t version) const
 {
   uint16_t  length = sizeof(this->_flags) + sizeof(this->_type);
   switch (this->_type) {
