--- a/transponders.c
+++ b/transponders.c
@@ -285,7 +285,7 @@ cTerrTransponder::cTerrTransponder(int C
     fec_h_ = FEC_AUTO;
     fec_l_ = FEC_AUTO;
     hierarchy_ = HIERARCHY_NONE;
-    modulation_ = FE_OFDM;
+    modulation_ = QAM_AUTO;
     guard_ = GUARD_INTERVAL_AUTO;
     transmission_ = TRANSMISSION_MODE_AUTO;
 }
