--- ./classes/src/ArtsBgp4RouteTableData.cc.orig	Mon Oct  2 13:05:23 2000
+++ ./classes/src/ArtsBgp4RouteTableData.cc	Wed Sep 25 16:38:10 2002
@@ -114,7 +114,7 @@
 //............................................................................
 //  
 //----------------------------------------------------------------------------
-istream & ArtsBgp4RouteTableData::read(istream & is, uint8_t version = 0)
+istream & ArtsBgp4RouteTableData::read(istream & is, uint8_t version)
 {
   uint32_t            numRoutes;
   ArtsBgp4RouteEntry  routeEntry;
@@ -134,7 +134,7 @@
 //............................................................................
 //  
 //----------------------------------------------------------------------------
-int ArtsBgp4RouteTableData::read(int fd, uint8_t version = 0)
+int ArtsBgp4RouteTableData::read(int fd, uint8_t version)
 {
   uint32_t            numRoutes;
   ArtsBgp4RouteEntry  routeEntry;
@@ -165,7 +165,7 @@
 //  
 //----------------------------------------------------------------------------
 ostream & ArtsBgp4RouteTableData::write(ostream & os,
-                                        uint8_t version = 0) const
+                                        uint8_t version) const
 {
   Ipv4PrefixPatricia<ArtsBgp4RouteEntry>::iterator  routeIter;
 
@@ -185,7 +185,7 @@
 //............................................................................
 //  
 //----------------------------------------------------------------------------
-int ArtsBgp4RouteTableData::write(int fd, uint8_t version = 0) const
+int ArtsBgp4RouteTableData::write(int fd, uint8_t version) const
 {
   Ipv4PrefixPatricia<ArtsBgp4RouteEntry>::iterator  routeIter;
   int    rc;
@@ -216,7 +216,7 @@
 //............................................................................
 //  
 //----------------------------------------------------------------------------
-uint32_t ArtsBgp4RouteTableData::Length(uint8_t version = 0) const
+uint32_t ArtsBgp4RouteTableData::Length(uint8_t version) const
 {
   uint32_t  length = sizeof(uint32_t);
   Ipv4PrefixPatricia<ArtsBgp4RouteEntry>::iterator  routeIter;
