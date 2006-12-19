--- libs/libmythtv/videoout_xv.cpp~	Tue Aug 29 16:43:24 2006
+++ libs/libmythtv/videoout_xv.cpp	Tue Nov 14 12:23:32 2006
@@ -7,7 +7,10 @@
 #include <ctime>
 #include <cerrno>

+#ifdef __FreeBSD__
+#else
 #include <malloc.h>
+#endif
 #include <fcntl.h>
 #include <unistd.h>
 #include <sys/time.h>
