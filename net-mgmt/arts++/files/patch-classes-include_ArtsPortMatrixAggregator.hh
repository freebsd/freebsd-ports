--- classes/include/ArtsPortMatrixAggregator.hh.orig	2007-11-12 16:17:18.000000000 +0100
+++ classes/include/ArtsPortMatrixAggregator.hh	2007-11-12 16:17:28.000000000 +0100
@@ -166,7 +166,6 @@
   //  
   //--------------------------------------------------------------------------
   ArtsSelectedPortTable *
-  ArtsPortMatrixAggregator::
   ConvertToArtsSelectedPortTable(int numTopPorts,
                                  bool byPkts = false) const;
   
