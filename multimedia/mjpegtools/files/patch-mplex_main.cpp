--- mplex/main.cpp.orig	Wed Jun 20 13:40:39 2007
+++ mplex/main.cpp	Wed Jun 20 13:41:49 2007
@@ -38,6 +38,7 @@
 #endif
 #include <ctype.h>
 #include <math.h>
+#include <fcntl.h>
 #include "cpu_accel.h"
 #include "mjpeg_types.h"
 #include "mjpeg_logging.h"
@@ -107,6 +108,14 @@
 	{
 		mjpeg_error_exit1( "Could not open for writing: %s", cur_filename );
 	}
+       {
+               int     flags;
+
+               (void)fcntl(fileno(strm), F_GETFL, &flags);
+               (void)fcntl(fileno(strm), F_SETFL, flags & ~O_NONBLOCK);
+       }
+
+
 
 	return 0;
 }
@@ -143,6 +152,13 @@
 		mjpeg_error_exit1( "Could not open for writing: %s", cur_filename );
 	}
     segment_len = 0;
+       {
+               int     flags;
+
+               (void)fcntl(fileno(strm), F_GETFL, &flags);
+               (void)fcntl(fileno(strm), F_SETFL, flags & ~O_NONBLOCK);
+       }
+
 }
 
 void
@@ -200,6 +216,14 @@
 	{
 		mjpeg_error_exit1( "Unable to open file %s for reading.", bs_filename);
 	}
+
+       {
+               int     flags;
+
+               (void)fcntl(fileno(fileh), F_GETFL, &flags);
+               (void)fcntl(fileno(fileh), F_SETFL, flags & ~O_NONBLOCK);
+       }
+
 	filename = strcpy( new char[strlen(bs_filename)+1], bs_filename );
     streamname = filename;
 
