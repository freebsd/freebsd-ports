--- src/CLucene/jstreams/substreamprovider.h	Sat Feb 10 13:56:34 2007
+++ src/CLucene/jstreams/substreamprovider.h.orig	Fri Nov 24 13:42:02 2006
@@ -16,8 +16,9 @@
     std::string filename;
     int32_t size;
     uint mtime;
-    enum Type {Dir, File};
+    enum Type {Unknown=0, Dir=1, File=2};
     Type type;
+    EntryInfo() :size(-1), mtime(0), type(Unknown) {}
 };
 
 class SubStreamProvider {
@@ -25,16 +26,18 @@
     StreamStatus status;
     std::string error;
     StreamBase<char> *input;
+    StreamBase<char> *entrystream;
     EntryInfo entryinfo;
 public:
-    SubStreamProvider(StreamBase<char> *i) :status(Ok), input(i) {}
-    virtual ~SubStreamProvider() {}
+    SubStreamProvider(StreamBase<char> *i) :status(Ok), input(i), entrystream(0)
+        {}
+    virtual ~SubStreamProvider() { if (entrystream) delete entrystream; }
     StreamStatus getStatus() const { return status; }
     virtual StreamBase<char>* nextEntry() = 0;
+    StreamBase<char>* currentEntry() { return entrystream; }
     const EntryInfo &getEntryInfo() const {
         return entryinfo;
     }
-//    std::string getEntryFileName() const { return entryfilename; }
     const char* getError() const { return error.c_str(); }
 };
 
