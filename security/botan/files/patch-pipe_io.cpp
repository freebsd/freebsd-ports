--- src/pipe_io.cpp.orig	Fri May 10 10:10:27 2002
+++ src/pipe_io.cpp	Fri May 10 10:10:57 2002
@@ -33,12 +33,12 @@
    {
    static const u32bit BUFFERSIZE = DEFAULT_BUFFERSIZE;
    SecureBuffer<byte, BUFFERSIZE> buffer;
-   while(!std::ferror(stream) && pipe.remaining())
+   while(!ferror(stream) && pipe.remaining())
       {
       u32bit got = pipe.read(buffer, BUFFERSIZE);
-      std::fwrite(buffer, 1, got, stream);
+      fwrite(buffer, 1, got, stream);
       }
-   if(std::ferror(stream))
+   if(ferror(stream))
       throw Stream_IO_Error("Pipe output operator (stdio) has failed");
    return stream;
    }
@@ -67,12 +67,12 @@
    {
    static const u32bit BUFFERSIZE = DEFAULT_BUFFERSIZE;
    SecureBuffer<byte, BUFFERSIZE> buffer;
-   while(!std::ferror(stream) && !std::feof(stream))
+   while(!ferror(stream) && !feof(stream))
       {
-      u32bit got = std::fread(buffer, 1, BUFFERSIZE, stream);
+      u32bit got = fread(buffer, 1, BUFFERSIZE, stream);
       pipe.write(buffer, got);
       }
-   if(std::ferror(stream))
+   if(ferror(stream))
       throw Stream_IO_Error("Pipe input operator (stdio) has failed");
    return stream;
    }
