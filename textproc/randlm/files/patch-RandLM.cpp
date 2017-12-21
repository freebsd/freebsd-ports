--- src/RandLM/RandLM.cpp.orig	2017-03-07 02:01:18 UTC
+++ src/RandLM/RandLM.cpp
@@ -66,7 +66,7 @@ namespace randlm {
       smoothing_name = kStupidBackoffSmoothing;
       break;
     case kWittenBellSmoothingCode:
-      smoothing_name == kWittenBellSmoothing;
+      smoothing_name = kWittenBellSmoothing;
       break;
     case  kBackoffSmoothingCode:
       smoothing_name = kBackoffSmoothing;
