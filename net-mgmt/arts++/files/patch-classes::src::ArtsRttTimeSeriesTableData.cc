--- classes/src/ArtsRttTimeSeriesTableData.cc.orig	Thu Oct 19 16:37:14 2000
+++ classes/src/ArtsRttTimeSeriesTableData.cc	Thu Jul 17 19:17:37 2003
@@ -192,7 +192,7 @@
 ostream & ArtsRttTimeSeriesTableEntry::write(ostream & os,
                                              uint32_t timeBase,
                                              uint32_t prevSecsOffset,
-                                             uint8_t version = 0) const
+                                             uint8_t version) const
 {
   uint8_t         rleFlags = 0;
   uint8_t         timestampSecsLength = 0;
@@ -217,7 +217,7 @@
 
   timestampUsecsLength = BytesNeededForUint32(this->_timestamp.tv_usec);
   rleFlags |= (timestampUsecsLength - 1);
-  os.write(&rleFlags,sizeof(rleFlags));
+  os.write((char *)&rleFlags,sizeof(rleFlags));
   if (rttLength > 0)
     g_ArtsLibInternal_Primitive.WriteUint32(os,this->_rtt,rttLength);
   if (timestampSecsLength > 0)
@@ -232,14 +232,14 @@
 //     int ArtsRttTimeSeriesTableEntry::write(int fd, 
 //                                            uint32_t timeBase, 
 //                                            uint32_t prevSecsOffset, 
-//                                            uint8_t version = 0) const 
+//                                            uint8_t version) const 
 //............................................................................
 //  
 //----------------------------------------------------------------------------
 int ArtsRttTimeSeriesTableEntry::write(int fd,
                                        uint32_t timeBase,
                                        uint32_t prevSecsOffset,
-                                       uint8_t version = 0) const
+                                       uint8_t version) const
 {
   uint8_t         rleFlags = 0;
   uint8_t         timestampSecsLength = 0;
@@ -302,7 +302,7 @@
 //----------------------------------------------------------------------------
 uint32_t ArtsRttTimeSeriesTableEntry::Length(uint32_t timeBase,
                                              uint32_t prevSecsOffset,
-                                             uint8_t version = 0) const
+                                             uint8_t version) const
 {
   uint32_t length = sizeof(uint8_t);  // always have rleFlags
   if (this->_rtt != k_droppedPacketRtt) {
@@ -330,13 +330,13 @@
 istream & ArtsRttTimeSeriesTableEntry::read(istream & is,
                                             uint32_t timeBase,
                                             uint32_t prevSecsOffset,
-                                            uint8_t version = 0)
+                                            uint8_t version)
 {
   uint8_t         rleFlags = 0;
   uint8_t         timestampUsecsLength = 0;
   uint32_t        timeVal;
   
-  is.read(&rleFlags,sizeof(rleFlags));
+  is.read((char *)&rleFlags,sizeof(rleFlags));
 
   if (rleFlags & 0x80) {
     //  it's a dropped packet; RTT length is 0
@@ -374,7 +374,7 @@
 //----------------------------------------------------------------------------
 int ArtsRttTimeSeriesTableEntry::read(int fd, uint32_t timeBase,
                                       uint32_t prevSecsOffset,
-                                      uint8_t version = 0)
+                                      uint8_t version)
 {
   uint8_t         rleFlags = 0;
   uint8_t         timestampUsecsLength = 0;
@@ -594,7 +594,7 @@
 //............................................................................
 //  
 //----------------------------------------------------------------------------
-istream & ArtsRttTimeSeriesTableData::read(istream& is, uint8_t version = 0)
+istream & ArtsRttTimeSeriesTableData::read(istream& is, uint8_t version)
 {
   uint32_t numRttEntries, rttEntryNum;
   ArtsRttTimeSeriesTableEntry  rttEntry;
@@ -623,7 +623,7 @@
 //............................................................................
 //  
 //----------------------------------------------------------------------------
-int ArtsRttTimeSeriesTableData::read(int fd, uint8_t version = 0)
+int ArtsRttTimeSeriesTableData::read(int fd, uint8_t version)
 {
   uint32_t numRttEntries, rttEntryNum;
   ArtsRttTimeSeriesTableEntry  rttEntry;
@@ -664,7 +664,7 @@
 //............................................................................
 //  
 //----------------------------------------------------------------------------
-uint32_t ArtsRttTimeSeriesTableData::Length(uint8_t version = 0) const
+uint32_t ArtsRttTimeSeriesTableData::Length(uint8_t version) const
 {
   uint32_t    length = 0;
   uint32_t    rttEntryNum, numRttEntries;
@@ -693,7 +693,7 @@
 //  
 //----------------------------------------------------------------------------
 ostream & ArtsRttTimeSeriesTableData::write(ostream & os,
-                                            uint8_t version = 0) const
+                                            uint8_t version) const
 {
   uint32_t             numRttEntries, rttEntryNum;
   uint32_t             rttUsecs;
@@ -729,7 +729,7 @@
 //............................................................................
 //  
 //----------------------------------------------------------------------------
-int ArtsRttTimeSeriesTableData::write(int fd, uint8_t version = 0) const
+int ArtsRttTimeSeriesTableData::write(int fd, uint8_t version) const
 {
   uint32_t             numRttEntries, rttEntryNum;
   uint32_t             rttUsecs;
