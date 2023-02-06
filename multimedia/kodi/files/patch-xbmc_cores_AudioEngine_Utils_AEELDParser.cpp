--- xbmc/cores/AudioEngine/Utils/AEELDParser.cpp.orig	2022-05-22 11:38:07 UTC
+++ xbmc/cores/AudioEngine/Utils/AEELDParser.cpp
@@ -72,7 +72,7 @@ typedef struct
 #define CEA_861_FORMAT_WMAPRO    14
 #define CEA_861_FORMAT_RESERVED2 15
 
-#define rtrim(s) s.erase(std::find_if(s.rbegin(), s.rend(), std::not1(std::ptr_fun<int, int>(std::isspace))).base(), s.end())
+#define rtrim(s) s.erase(std::find_if(s.rbegin(), s.rend(), [](unsigned char c) { return !std::isspace(c); }).base(), s.end())
 
 void CAEELDParser::Parse(const uint8_t *data, size_t length, CAEDeviceInfo& info)
 {
