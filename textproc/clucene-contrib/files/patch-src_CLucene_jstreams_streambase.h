--- src/CLucene/jstreams/streambase.h	Sat Feb 10 13:56:34 2007
+++ src/CLucene/jstreams/streambase.h.orig	Sat Nov 25 11:03:58 2006
@@ -17,13 +17,14 @@
 
 /**
  * @short Base class for stream read access to many different file types.
- * 
+ *
  * This class is based on the interface java.io.InputStream. It allows
  * for uniform access to streamed resources.
  * The main difference with the java equivalent is a performance improvement.
  * When reading data, data is not copied into a buffer provided by the caller,
- * but a pointer to the read data is provided. This makes this interface especially
- * useful for deriving from it and implementing filterers or transformers.
+ * but a pointer to the read data is provided. This makes this interface
+ * especially useful for deriving from it and implementing filterers or
+ * transformers.
  */
 // java mapping: long=int64, int=int32, byte=uint8_t
 template <class T>
@@ -37,29 +38,24 @@
     StreamBase() :size(-1), position(0), status(Ok){ }
     virtual ~StreamBase(){}
     /**
-     * Return a string representation of the last error that has occurred.
+     * @brief  Return a string representation of the last error.
      * If no error has occurred, an empty string is returned.
      **/
     const char* getError() const { return error.c_str(); }
     StreamStatus getStatus() const { return status; }
+    /**
+     * @brief Get the current position in the stream.
+     * The value obtained from this function can be used to reset the stream.
+     **/
     int64_t getPosition() const { return position; }
-    int64_t getSize() const { return size; }
-    /** 
-     * @brief Reads @p ntoread characters from the stream and sets \a start to
-     * the first character that was read.
-     *
-     * If @p ntoread is @c 0, then at least one character will be read.
-     *
-     * @param start Pointer passed by reference that will be set to point to
-     *              the retrieved array of characters. If the end of the stream
-     *              is encountered or an error occurs, the value of @p start
-     *              is undefined.
-     * @return the number of characters that were read. If 0 is returned, the
-     *         end of the stream has been reached. If -1 is returned, an error
-     *         has occured.
+    /**
+     * @brief Return the size of the stream.
+     * If the size of the stream is unknown, -1
+     * is returned. If the end of the stream has been reached the size is
+     * always known.
      **/
- //   virtual int32_t read(const T*& start) = 0;
-    /** 
+    int64_t getSize() const { return size; }
+    /**
      * @brief Reads characters from the stream and sets \a start to
      * the first character that was read.
      *
@@ -73,61 +69,34 @@
      *                @p is @c 0 the stream reads at least 1 character.
      * @return the number of characters that were read. If -1 is returned, the
      *         end of the stream has been reached. If -2 is returned, an error
-     *         has occured.
+     *         has occurred.
      **/
     virtual int32_t read(const T*& start, int32_t min, int32_t max) = 0;
     /**
-     * Same as read(const T*& start, int32_t ntoread), but may read more.
-     **/
-//    virtual int32_t readAtLeast(const T*& start, int32_t ntoread) = 0;
-    /* the available value may be greater than the actual value if
-      the encoding is a variable one (such as utf8 or unicode) */
-    /**
      * Skip @param ntoskip bytes. Unless an error occurs or the end of file is
      * encountered, this amount of bytes is skipped.
-     * The optional @param skipped can be use to find out how many bites were skipped.
-     * If the end of stream is reached, Eof is returned.
-     * If an error occured, Error is returned.
+     * This function returns new position in the stream.
      **/
     virtual int64_t skip(int64_t ntoskip);
-     /**
-      * \short Marks the current position in this input stream.
-      * A subsequent call to the reset method repositions this stream at the
-      * last marked position so that subsequent reads re-read the same bytes.
-      *
-      * The readlimit arguments tells this input stream to allow that many
-      * bytes to be read before the mark position gets invalidated.
-      * The stream somehow remembers all the bytes read after the call to mark
-      * and stands ready to supply those same bytes again if and whenever the
-      * method reset is called. However, the stream is not required to remember
-      * any data at all if more than readlimit bytes are read from the stream
-      * before reset is called.
-      *
-      * When calling the method mark more than once at the same position in the
-      * stream, the call with the largest value for \p readlimit is defining.
-      **/
-    virtual int64_t mark(int32_t readlimit) = 0;
       /**
-       * \short Repositions this stream to given requested position.
-       * The general contract of reset is:
-       * - Reset is guaranteed to work after a successfull call to read(),
-       *   when new position is in the range of the data returned by read().
-       *   This means that @p pos must lie between than the position
-       *   corresponding to the @p start parameter (x) of the @r read function
-       *   and the position corresponding to the last position in the returned
-       *   buffer (x + @p nread).
-       * if If the method mark has not been called since the stream was created,
-       *   or the number of bytes read from the stream since mark was last
-       *   called is larger than the argument to mark at that last call, then
-       *   Error is returned.
-       * - Otherwise the stream is reset to a state such that all the bytes
-       *   read since the most recent call to mark (or since the start of the
-       *   file, if mark has not been called) will be resupplied to subsequent
-       *   callers of the read method, followed by any bytes that otherwise
-       *   would have been the next input data as of the time of the call to
-       *   reset.
+       * @brief Repositions this stream to given requested position.
+       * Reset is guaranteed to work after a successful call to read(),
+       * when the new position is in the range of the data returned by read().
+       * This means that @p pos must lie between than the position
+       * corresponding to the @p start parameter (x) of the @r read function
+       * and the position corresponding to the last position in the returned
+       * buffer (x + @p nread).
        **/
     virtual int64_t reset(int64_t pos) = 0;
+    /**
+     * deprecated function
+     **/
+    int64_t mark(int32_t readlimit) {
+        int64_t p = getPosition();
+        const T* ptr;
+        read(ptr, readlimit, -1);
+        return reset(p);
+    }
 };
 #define SKIPSTEP 1024
 template <class T>
