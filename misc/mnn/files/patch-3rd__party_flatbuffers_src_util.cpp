Reference:	https://github.com/google/flatbuffers/commit/6748c373be9ef54e221265a502a3cee3bbf8cef1

FAILED: tools/converter/CMakeFiles/MNNConvertDeps.dir/__/__/3rd_party/flatbuffers/src/util.cpp.o 
/usr/local/libexec/ccache/c++ -DGOOGLE_PROTOBUF_NO_RTTI -DMNNConvertDeps_EXPORTS -DMNN_SUPPORT_TFLITE_QUAN -DMNN_USE_THREAD_POOL -DMNN_VERSION=\"0.2.1.5git\" -DMNN_VERSION_MAJOR=0 -DMNN_VERSION_MINOR=2 -DMNN_VERSION_PATCH=1 -I/wrkdirs/usr/ports/misc/mnn/work/MNN-1.2.0/include -I/wrkdirs/usr/ports/misc/mnn/work/MNN-1.2.0/source -I/wrkdirs/usr/ports/misc/mnn/work/MNN-1.2.0/express -I/wrkdirs/usr/ports/misc/mnn/work/MNN-1.2.0/tools -I/wrkdirs/usr/ports/misc/mnn/work/MNN-1.2.0/codegen -I/wrkdirs/usr/ports/misc/mnn/work/MNN-1.2.0/schema/current -I/wrkdirs/usr/ports/misc/mnn/work/MNN-1.2.0/3rd_party -I/wrkdirs/usr/ports/misc/mnn/work/MNN-1.2.0/3rd_party/half -I/wrkdirs/usr/ports/misc/mnn/work/MNN-1.2.0/3rd_party/imageHelper -I/wrkdirs/usr/ports/misc/mnn/work/MNN-1.2.0/3rd_party/OpenCLHeaders -I/wrkdirs/usr/ports/misc/mnn/work/MNN-1.2.0/tools/converter/include -I/wrkdirs/usr/ports/misc/mnn/work/MNN-1.2.0/tools/converter/source/tflite/schema -I/wrkdirs/usr/ports/misc/mnn/work/.build/tools/converter -O2 -pipe -fPIC -fstack-protector-strong -isystem /usr/local/include -fno-strict-aliasing  -pthread -fPIC -isystem /usr/local/include -std=c++11 -O3 -fvisibility-inlines-hidden -fvisibility=hidden -fomit-frame-pointer -fstrict-aliasing -ffunction-sections -fdata-sections -ffast-math -fno-rtti -fno-exceptions  -O2 -pipe -fPIC -fstack-protector-strong -isystem /usr/local/include -fno-strict-aliasing  -pthread -fPIC -isystem /usr/local/include -fPIC -std=gnu++11 -MD -MT tools/converter/CMakeFiles/MNNConvertDeps.dir/__/__/3rd_party/flatbuffers/src/util.cpp.o -MF tools/converter/CMakeFiles/MNNConvertDeps.dir/__/__/3rd_party/flatbuffers/src/util.cpp.o.d -o tools/converter/CMakeFiles/MNNConvertDeps.dir/__/__/3rd_party/flatbuffers/src/util.cpp.o -c /wrkdirs/usr/ports/misc/mnn/work/MNN-1.2.0/3rd_party/flatbuffers/src/util.cpp
/wrkdirs/usr/ports/misc/mnn/work/MNN-1.2.0/3rd_party/flatbuffers/src/util.cpp:150:37: error: use of undeclared identifier 'string_back'
    char &filepath_last_character = string_back(filepath);
                                    ^
/wrkdirs/usr/ports/misc/mnn/work/MNN-1.2.0/3rd_party/flatbuffers/src/util.cpp:227:18: error: use of undeclared identifier 'string_back'
          (ch == string_back(s)))
                 ^
2 errors generated.

--- 3rd_party/flatbuffers/src/util.cpp.orig	2021-06-11 09:17:13 UTC
+++ 3rd_party/flatbuffers/src/util.cpp
@@ -147,7 +147,7 @@ std::string ConCatPathFileName(const std::string &path
                                const std::string &filename) {
   std::string filepath = path;
   if (filepath.length()) {
-    char &filepath_last_character = string_back(filepath);
+    char &filepath_last_character = filepath.back();
     if (filepath_last_character == kPathSeparatorWindows) {
       filepath_last_character = kPathSeparator;
     } else if (filepath_last_character != kPathSeparator) {
@@ -224,7 +224,7 @@ ClassicLocale ClassicLocale::instance_;
 std::string RemoveStringQuotes(const std::string &s) {
   auto ch = *s.c_str();
   return ((s.size() >= 2) && (ch == '\"' || ch == '\'') &&
-          (ch == string_back(s)))
+          (ch == s.back()))
              ? s.substr(1, s.length() - 2)
              : s;
 }
