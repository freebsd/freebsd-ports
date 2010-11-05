--- src/CLucene/jstreams/filereader.h	Sat Feb 10 13:56:34 2007
+++ src/CLucene/jstreams/filereader.h.orig	Sat Nov 25 11:03:58 2006
@@ -11,12 +11,11 @@
     FileInputStream* input;
     InputStreamReader* reader;
 public:
-    FileReader(const char* fname, const char* encoding_scheme=NULL,
+    explicit FileReader(const char* fname, const char* encoding_scheme=NULL,
         const int32_t cachelen = 13,
         const int32_t cachebuff = 14 );
     ~FileReader();
     int32_t read(const wchar_t*& start, int32_t min, int32_t max);
-    int64_t mark(int32_t readlimit);
     int64_t reset(int64_t);
 };
 
