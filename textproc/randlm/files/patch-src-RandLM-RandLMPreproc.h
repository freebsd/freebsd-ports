--- src/RandLM/RandLMPreproc.h.orig	2014-09-01 18:11:27.000000000 +0400
+++ src/RandLM/RandLMPreproc.h	2014-09-01 18:11:43.000000000 +0400
@@ -407,7 +407,7 @@ namespace randlm {
   // Concrete subclass of NormalisedNgramFile for backoff model data
   class BackoffModelFile : public NormalisedNgramFile {
   public:
-    static const float kNullBackoffWeight = 0; // indicates lack of backoff weight
+    static constexpr float kNullBackoffWeight = 0; // indicates lack of backoff weight
     static bool ValidWeight(float boweight);
     // creation at start of pipeline (i.e. load a preprocess backoff model)
     BackoffModelFile(const std::string & input_path, const std::string & input_type,
