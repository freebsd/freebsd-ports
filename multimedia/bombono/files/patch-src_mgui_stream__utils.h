--- src/mgui/stream_utils.h.orig	2013-03-07 21:20:45 UTC
+++ src/mgui/stream_utils.h
@@ -42,8 +42,8 @@ class stream
                 stream(std::iostream& strm): io_strm(strm) {}
 
  std::iostream& strm() { return io_strm; }
-                operator void*() const { return (void*)io_strm; }
-          bool  operator!() const { return !operator void*(); }
+                operator bool() const { return static_cast<bool> (io_strm); }
+          bool  operator!() const { return !operator bool(); }
         stream& seekg(streamoff off, ios_base::seekdir dir)
                 { io_strm.seekg(off, dir); return *this; }
         stream& seekp(streamoff off, ios_base::seekdir dir)
