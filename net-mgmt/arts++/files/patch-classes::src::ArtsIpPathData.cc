--- ./classes/src/ArtsIpPathData.cc.orig	Mon Oct  2 13:05:25 2000
+++ ./classes/src/ArtsIpPathData.cc	Wed Sep 25 16:38:10 2002
@@ -187,7 +187,7 @@
 //............................................................................
 //  
 //----------------------------------------------------------------------------
-uint32_t ArtsIpPathData::Length(uint8_t version = 0) const
+uint32_t ArtsIpPathData::Length(uint8_t version) const
 {
   uint32_t len =  sizeof(this->_src) + sizeof(this->_dst) +
     sizeof(this->_rtt) + sizeof(this->_hopDistance) + sizeof(this->_numHops);
@@ -209,28 +209,28 @@
 //------------------------------------------------------------------------
 //   ostream& ArtsIpPathData::write(ostream& os, uint8_t version = 0)
 //------------------------------------------------------------------------
-ostream& ArtsIpPathData::write(ostream& os, uint8_t version = 0)
+ostream& ArtsIpPathData::write(ostream& os, uint8_t version)
 {
   uint32_t  timeDatum;
   uint8_t   completeAndNumHops;
 
-  os.write(&this->_src,sizeof(this->_src));
-  os.write(&this->_dst,sizeof(this->_dst));
+  os.write((char *)&this->_src,sizeof(this->_src));
+  os.write((char *)&this->_dst,sizeof(this->_dst));
 
   timeDatum = htonl(this->_rtt.tv_sec);
-  os.write(&timeDatum,sizeof(timeDatum));
+  os.write((char *)&timeDatum,sizeof(timeDatum));
   timeDatum = htonl(this->_rtt.tv_usec);
-  os.write(&timeDatum,sizeof(timeDatum));
+  os.write((char *)&timeDatum,sizeof(timeDatum));
 
-  os.write(&this->_hopDistance,sizeof(this->_hopDistance));
+  os.write((char *)&this->_hopDistance,sizeof(this->_hopDistance));
   
   completeAndNumHops = (this->_isComplete << 7) | this->_numHops;
-  os.write(&completeAndNumHops,sizeof(completeAndNumHops));
+  os.write((char *)&completeAndNumHops,sizeof(completeAndNumHops));
 
   if (version == 1) {
     if (! this->_isComplete) {
-      os.write(&this->_incompleteReason,sizeof(this->_incompleteReason));
-      os.write(&this->_incompleteFlags,sizeof(this->_incompleteFlags));
+      os.write((char *)&this->_incompleteReason,sizeof(this->_incompleteReason));
+      os.write((char *)&this->_incompleteFlags,sizeof(this->_incompleteFlags));
     }
   }
 
@@ -251,7 +251,7 @@
 //.........................................................................
 //                                                                         
 //-------------------------------------------------------------------------
-int ArtsIpPathData::write(int fd, uint8_t version = 0)
+int ArtsIpPathData::write(int fd, uint8_t version)
 {
   uint32_t  timeDatum;
   uint8_t   completeAndNumHops;
@@ -334,30 +334,30 @@
 //------------------------------------------------------------------------
 //    istream& ArtsIpPathData::read(istream& is, uint8_t version = 0)
 //------------------------------------------------------------------------
-istream& ArtsIpPathData::read(istream& is, uint8_t version = 0)
+istream& ArtsIpPathData::read(istream& is, uint8_t version)
 {
   uint32_t  timeDatum;
   uint8_t   completeAndNumHops;
   size_t    hopNum;
   
-  is.read(&this->_src,sizeof(this->_src));
-  is.read(&this->_dst,sizeof(this->_dst));
+  is.read((char *)&this->_src,sizeof(this->_src));
+  is.read((char *)&this->_dst,sizeof(this->_dst));
 
-  is.read(&timeDatum,sizeof(timeDatum));
+  is.read((char *)&timeDatum,sizeof(timeDatum));
   this->_rtt.tv_sec = ntohl(timeDatum);
-  is.read(&timeDatum,sizeof(timeDatum));
+  is.read((char *)&timeDatum,sizeof(timeDatum));
   this->_rtt.tv_usec = ntohl(timeDatum);
 
-  is.read(&this->_hopDistance,sizeof(this->_hopDistance));
+  is.read((char *)&this->_hopDistance,sizeof(this->_hopDistance));
   
-  is.read(&completeAndNumHops,sizeof(completeAndNumHops));
+  is.read((char *)&completeAndNumHops,sizeof(completeAndNumHops));
   this->_isComplete = completeAndNumHops >> 7;
   this->_numHops = completeAndNumHops & 0x7f;
 
   if (version == 1) {
     if (! this->_isComplete) {
-      is.read(&this->_incompleteReason,sizeof(this->_incompleteReason));
-      is.read(&this->_incompleteFlags,sizeof(this->_incompleteFlags));
+      is.read((char *)&this->_incompleteReason,sizeof(this->_incompleteReason));
+      is.read((char *)&this->_incompleteFlags,sizeof(this->_incompleteFlags));
     }
   }
   
@@ -384,7 +384,7 @@
 //.........................................................................
 //                                                                         
 //-------------------------------------------------------------------------
-int ArtsIpPathData::read(int fd, uint8_t version = 0)
+int ArtsIpPathData::read(int fd, uint8_t version)
 {
   uint32_t  timeDatum;
   uint8_t   completeAndNumHops;
