commit 728242475838442751df999a7c77f6046006ad7a
Author: Christoph Moench-Tegeder <cmt@FreeBSD.org>

    that _POSIX_C_SOURCE=202405L hides XSI definitions
    
    like isascii (which will be needed for istream/ostream) and gives us
    nothing as we don't have posix_close()

diff --git toolkit/components/protobuf/src/google/protobuf/io/zero_copy_stream_impl.cc toolkit/components/protobuf/src/google/protobuf/io/zero_copy_stream_impl.cc
index 8f951683e8dc..9ea26c340961 100644
--- toolkit/components/protobuf/src/google/protobuf/io/zero_copy_stream_impl.cc
+++ toolkit/components/protobuf/src/google/protobuf/io/zero_copy_stream_impl.cc
@@ -9,8 +9,10 @@
 //  Based on original Protocol Buffers design by
 //  Sanjay Ghemawat, Jeff Dean, and others.
 
+#ifndef __FreeBSD__
 // We request posix_close if available. See the comment on "robust_close".
 #define _POSIX_C_SOURCE 202405L
+#endif
 
 #ifndef _MSC_VER
 #include <fcntl.h>
