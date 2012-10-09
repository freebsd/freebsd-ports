--- test/v4l_h264/encode/capture.cpp.orig	2012-10-04 15:30:51.000000000 +0200
+++ test/v4l_h264/encode/capture.cpp	2012-10-08 22:31:01.067189237 +0200
@@ -37,7 +37,11 @@
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
@@ -451,10 +455,15 @@
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
