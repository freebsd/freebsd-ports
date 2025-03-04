'vector_downward &operator=(vector_downward &&other)' wants an rvalue.
other.buf_ is a lvalue.

Newer clang compilers are stricter about this.
clang++19 and later complain:

include/flatbuffers/flatbuffers.h:1866:12: error: overload resolution selected deleted operator '='
 1866 |       buf_ = other.buf_;
      |       ~~~~ ^ ~~~~~~~~~~

For this py-tflite-support port, if you comment out TableKeyComparator &operator=(),
it builds.

Another fix is to convert the lvalue to an rvalue using std::move()
which is not an expensive operation.  That also builds with older
or newe clang++.


--- include/flatbuffers/flatbuffers.h.orig	2020-03-20 02:52:36 UTC
+++ include/flatbuffers/flatbuffers.h
@@ -1862,10 +1862,12 @@ class FlatBufferBuilder {
     vector_downward &buf_;
 
    private:
+#if 1
     TableKeyComparator &operator=(const TableKeyComparator &other) {
-      buf_ = other.buf_;
+      buf_ = std::move(other.buf_);
       return *this;
     }
+#endif
   };
   /// @endcond
 
