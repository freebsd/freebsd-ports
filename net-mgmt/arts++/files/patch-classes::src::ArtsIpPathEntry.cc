--- ./classes/src/ArtsIpPathEntry.cc.orig	Mon Oct  2 13:05:25 2000
+++ ./classes/src/ArtsIpPathEntry.cc	Wed Sep 25 16:38:10 2002
@@ -111,13 +111,13 @@
 //------------------------------------------------------------------------
 //    istream& ArtsIpPathEntry::read(istream& is, uint8_t version = 0)
 //------------------------------------------------------------------------
-istream& ArtsIpPathEntry::read(istream& is, uint8_t version = 0)
+istream& ArtsIpPathEntry::read(istream& is, uint8_t version)
 {
-  is.read(&this->_hopNum,sizeof(this->_hopNum));
+  is.read((char *)&this->_hopNum,sizeof(this->_hopNum));
   if (! is)
     return(is);
 
-  is.read(&this->_ipAddr,sizeof(this->_ipAddr));
+  is.read((char *)&this->_ipAddr,sizeof(this->_ipAddr));
   if (! is)
     return(is);
 
@@ -130,7 +130,7 @@
     this->_rtt.tv_sec = fourBytes / 1000000;
     this->_rtt.tv_usec = fourBytes % 1000000;
 
-    is.read(&this->_numTries,sizeof(this->_numTries));
+    is.read((char *)&this->_numTries,sizeof(this->_numTries));
   }
   
   return(is);
@@ -141,7 +141,7 @@
 //.........................................................................
 //                                                                         
 //-------------------------------------------------------------------------
-int ArtsIpPathEntry::read(int fd, uint8_t version = 0)
+int ArtsIpPathEntry::read(int fd, uint8_t version)
 {
   int rc;
   int bytesRead = 0;
@@ -182,15 +182,15 @@
 //------------------------------------------------------------------------
 // ostream& ArtsIpPathEntry::write(ostream& os, uint8_t version = 0) const
 //------------------------------------------------------------------------
-ostream& ArtsIpPathEntry::write(ostream& os, uint8_t version = 0) const
+ostream& ArtsIpPathEntry::write(ostream& os, uint8_t version) const
 {
-  os.write(&this->_hopNum,sizeof(this->_hopNum));
-  os.write(&this->_ipAddr,sizeof(this->_ipAddr));
+  os.write((char *)&this->_hopNum,sizeof(this->_hopNum));
+  os.write((char *)&this->_ipAddr,sizeof(this->_ipAddr));
 
   if (version == 1) {
     uint32_t  fourBytes = (this->_rtt.tv_sec * 1000000) + this->_rtt.tv_usec;
     g_ArtsLibInternal_Primitive.WriteUint32(os,fourBytes,4);
-    os.write(&this->_numTries,sizeof(this->_numTries));
+    os.write((char *)&this->_numTries,sizeof(this->_numTries));
   }
 
   return(os);
@@ -201,7 +201,7 @@
 //.........................................................................
 //                                                                         
 //-------------------------------------------------------------------------
-int ArtsIpPathEntry::write(int fd, uint8_t version = 0) const
+int ArtsIpPathEntry::write(int fd, uint8_t version) const
 {
   int  rc;
   int  bytesWritten = 0;
