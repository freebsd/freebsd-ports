--- src/CLucene/jstreams/zipinputstream.h	Sat Feb 10 13:56:34 2007
+++ src/CLucene/jstreams/zipinputstream.h.orig	Fri Nov 24 13:42:02 2006
@@ -27,7 +27,6 @@
     // information relating to the current entry
     StreamBase<char>* compressedEntryStream;
     GZipInputStream *uncompressionStream;
-    StreamBase<char>* uncompressedEntryStream;
     int32_t entryCompressedSize;
     int32_t compressionMethod;
 
@@ -36,10 +35,13 @@
     static int32_t read2bytes(const unsigned char *b);
     static int32_t read4bytes(const unsigned char *b);
 public:
-    ZipInputStream(StreamBase<char>* input);
+    explicit ZipInputStream(StreamBase<char>* input);
     ~ZipInputStream();
     StreamBase<char>* nextEntry();
     static bool checkHeader(const char* data, int32_t datasize);
+    static SubStreamProvider* factory(StreamBase<char>* input) {
+        return new ZipInputStream(input);
+    }
 };
 
 } // end namespace jstreams
