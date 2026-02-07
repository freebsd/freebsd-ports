--- lencod/src/rdopt.c.orig	2020-09-29 10:35:54 UTC
+++ lencod/src/rdopt.c
@@ -834,7 +834,7 @@ distblk rdcost_for_8x8blocks (Macroblock *currMB, // -
   }
 
   //----- coded block pattern (for CABAC only) -----
-  if (!currSlice->symbol_mode == CAVLC)
+  if (!(currSlice->symbol_mode == CAVLC))
   {
     dataPart = &(currSlice->partArr[partMap[SE_CBP]]);
     eep_dp   = &(dataPart->ee_cabac);
