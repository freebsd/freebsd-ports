--- src/CLucene/jstreams/subinputstream.h	Sat Feb 10 13:56:34 2007
+++ src/CLucene/jstreams/subinputstream.h.orig	Fri Nov 24 13:42:02 2006
@@ -18,7 +18,6 @@
 public:
     SubInputStream(StreamBase<char> *input, int64_t size=-1);
     int32_t read(const char*& start, int32_t min, int32_t max);
-    int64_t mark(int32_t readlimit);
     int64_t reset(int64_t newpos);
     int64_t skip(int64_t ntoskip);
 };
