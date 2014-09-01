--- src/RandLM/RandLMQuantiser.h.orig	2014-09-01 18:09:32.000000000 +0400
+++ src/RandLM/RandLMQuantiser.h	2014-09-01 18:09:51.000000000 +0400
@@ -38,7 +38,7 @@ namespace randlm {
   
   class Quantiser {
   public:
-    static const float kFloatErr = 0.00001f;
+    static constexpr float kFloatErr = 0.00001f;
 
     Quantiser(RandLMInfo* info, Stats* stats, EventType event) 
       : info_(info), event_type_(event), code_to_value_(NULL),
