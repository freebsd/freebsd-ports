--- test/v4l_h264/encode/capture.cpp.orig	2015-07-01 07:54:24 UTC
+++ test/v4l_h264/encode/capture.cpp
@@ -30,6 +30,7 @@
 */
 
 #include <cstdlib> /* EXIT_FAILURE, EXIT_SUCCESS */
+#include <cstdio> /* printf */
 #include <string>
 #include <cstring> /* strerror() */
 #include <cassert>
@@ -37,7 +38,11 @@
 #include <fcntl.h> /* low-level i/o */
 #include <errno.h>
 #include <unistd.h>
+#ifdef __FreeBSD__
+#include <stdlib.h>
+#else
 #include <malloc.h>
+#endif
 #include <sys/stat.h>
 #include <sys/mman.h>
 #include <sys/ioctl.h>
@@ -451,10 +456,15 @@ static void init_userp (unsigned int buf
     }
     for (n_buffers = 0; n_buffers < 4; ++n_buffers) {
         buffers[n_buffers].length = buffer_size;
+#ifdef __FreeBSD__
+	if(posix_memalign(&buffers[n_buffers].start, page_size, buffer_size))
+	{
+#else
         buffers[n_buffers].start = memalign (/* boundary */ page_size,
             buffer_size);
 
         if (!buffers[n_buffers].start) {
+#endif
             std::cerr << "Out of memory\n";
             exit (EXIT_FAILURE);
         }
