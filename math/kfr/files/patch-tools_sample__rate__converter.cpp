--- tools/sample_rate_converter.cpp.orig	2025-08-02 11:51:50 UTC
+++ tools/sample_rate_converter.cpp
@@ -18,7 +18,7 @@ int main(int argc, char** argv)
     println(library_version());
     if (argc < 4)
     {
-        println("Usage: sample_rate_converter <INPUT_FILE> <OUTPUT_FILE> <TARGET_SAMPLE_RATE>");
+        println("Usage: kfr_src <INPUT_FILE> <OUTPUT_FILE> <TARGET_SAMPLE_RATE>");
         println("Supported formats: WAV/W64, 16, 24, 32-bit PCM, 32, 64-bit IEEE");
         return 1;
     }
