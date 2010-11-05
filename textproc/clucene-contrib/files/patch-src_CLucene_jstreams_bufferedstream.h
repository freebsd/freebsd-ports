--- src/CLucene/jstreams/bufferedstream.h	Sat Feb 10 13:56:34 2007
+++ src/CLucene/jstreams/bufferedstream.h.orig	Sat Nov 25 11:03:58 2006
@@ -9,6 +9,7 @@
 
 #include "streambase.h"
 #include "inputstreambuffer.h"
+#include <cassert>
 
 namespace jstreams {
 
@@ -32,10 +33,9 @@
     virtual int32_t fillBuffer(T* start, int32_t space) = 0;
     // this function might be useful if you want to reuse a bufferedstream
     void resetBuffer() {printf("implement 'resetBuffer'\n");}
-public:
     BufferedInputStream<T>();
+public:
     int32_t read(const T*& start, int32_t min, int32_t max);
-    int64_t mark(int32_t readlimit);
     int64_t reset(int64_t);
     virtual int64_t skip(int64_t ntoskip);
 };
@@ -55,6 +55,7 @@
         space = buffer.makeSpace(missing);
         T* start = buffer.readPos + buffer.avail;
         nwritten = fillBuffer(start, space);
+        assert(StreamBase<T>::status != Eof);
         if (nwritten > 0) {
             buffer.avail += nwritten;
             missing = ntoread - buffer.avail;
@@ -75,15 +76,9 @@
         // do we have enough space in the buffer?
         writeToBuffer(min);
         if (StreamBase<T>::status == Error) return -2;
-        if (StreamBase<T>::status == Eof) return -1;
     }
 
     int32_t nread = buffer.read(start, max);
-/*    if (nread == 0) {
-        printf("bis: start %p min %i max %i nread %i avail %i bsize %i pos %lli size %lli\n",
-        start, min, max, nread, buffer.avail, buffer.size, BufferedInputStream<T>::position, BufferedInputStream<T>::size);
-        printf("buf: start %p readpos %p marpos %p\n", buffer.start, buffer.readPos, buffer.markPos);
-    }*/
 
     BufferedInputStream<T>::position += nread;
     if (BufferedInputStream<T>::position > BufferedInputStream<T>::size
@@ -97,6 +92,9 @@
     } else if (BufferedInputStream<T>::status == Ok && buffer.avail == 0
             && finishedWritingToBuffer) {
         BufferedInputStream<T>::status = Eof;
+        if (BufferedInputStream<T>::size == -1) {
+            BufferedInputStream<T>::size = BufferedInputStream<T>::position;
+        }
         // save one call to read() by already returning -1 if no data is there
         if (nread == 0) nread = -1;
     }
@@ -104,13 +102,8 @@
 }
 template <class T>
 int64_t
-BufferedInputStream<T>::mark(int32_t readlimit) {
-    buffer.mark(readlimit);
-    return StreamBase<T>::position;
-}
-template <class T>
-int64_t
 BufferedInputStream<T>::reset(int64_t newpos) {
+    assert(newpos >= 0);
     if (StreamBase<T>::status == Error) return -2;
     // check to see if we have this position
     int64_t d = BufferedInputStream<T>::position - newpos;
