--- src/CLucene/jstreams/inputstreamreader.h	Sat Feb 10 13:56:34 2007
+++ src/CLucene/jstreams/inputstreamreader.h.orig	Fri Nov 24 13:42:02 2006
@@ -29,7 +29,7 @@
     void readFromStream();
     int32_t decode(wchar_t* start, int32_t space);
 public:
-    InputStreamReader(StreamBase<char> *i, const char *enc=0);
+    explicit InputStreamReader(StreamBase<char> *i, const char *enc=0);
     ~InputStreamReader();
     int32_t fillBuffer(wchar_t* start, int32_t space);
 };
