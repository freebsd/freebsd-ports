--- ./classes/src/ArtsPortMatrixAggregator.cc.orig	Mon Oct  2 13:05:27 2000
+++ ./classes/src/ArtsPortMatrixAggregator.cc	Wed Sep 25 16:38:10 2002
@@ -327,7 +327,7 @@
 //----------------------------------------------------------------------------
 ArtsSelectedPortTable *
 ArtsPortMatrixAggregator::
-ConvertToArtsSelectedPortTable(int numTopPorts, bool byPkts = false) const
+ConvertToArtsSelectedPortTable(int numTopPorts, bool byPkts) const
 {
   ArtsPortTableEntry  portEntry;
   map<ArtsPortMatrixKeyValue,counter_t,less<ArtsPortMatrixKeyValue> >::const_iterator  portCounter;
