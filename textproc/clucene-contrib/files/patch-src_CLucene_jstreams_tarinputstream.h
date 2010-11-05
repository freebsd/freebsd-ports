--- src/CLucene/jstreams/tarinputstream.h	Sat Feb 10 13:56:34 2007
+++ src/CLucene/jstreams/tarinputstream.h.orig	Fri Nov 24 13:42:02 2006
@@ -28,7 +28,6 @@
 class TarInputStream : public SubStreamProvider {
 private:
     // information relating to the current entry
-    StreamBase<char> *output;
     int32_t numPaddingBytes;
 
     void readFileName(int32_t len);
@@ -37,10 +36,13 @@
     int32_t readOctalField(const char *b, int32_t offset);
     void readLongLink(const char *b);
 public:
-    TarInputStream(StreamBase<char> *input);
+    explicit TarInputStream(StreamBase<char> *input);
     ~TarInputStream();
     StreamBase<char>* nextEntry();
     static bool checkHeader(const char* data, int32_t datasize);
+    static SubStreamProvider* factory(StreamBase<char>* input) {
+        return new TarInputStream(input);
+    }
 };
 
 } // end namespace jstreams
