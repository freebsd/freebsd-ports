- see https://github.com/coin-or/CHiPPS-ALPS/issues/26

--- Alps/src/AlpsSearchStrategyBase.h.orig	2021-05-03 02:01:12 UTC
+++ Alps/src/AlpsSearchStrategyBase.h
@@ -98,7 +98,7 @@ class AlpsSearchStrategy (public)
     int getType(){ return type_; }
 
     /** Set type of strategy */
-    void setType(int t) { type_ = t; }
+    void setType(int t) { type_ = (AlpsSearchType)t; }
 };
 
 //#############################################################################
