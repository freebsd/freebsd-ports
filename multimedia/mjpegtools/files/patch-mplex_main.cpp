--- mplex/main.cpp.orig	2021-09-05 06:14:13 UTC
+++ mplex/main.cpp
@@ -39,6 +39,7 @@
 #endif
 #include <ctype.h>
 #include <math.h>
+#include <fcntl.h>
 #include "cpu_accel.h"
 #include "mjpeg_types.h"
 #include "mjpeg_logging.h"
@@ -120,6 +121,13 @@ int FileOutputStream::Open()
 		mjpeg_error_exit1( "Could not open for writing: %s", cur_filename );
 	}
 
+	{
+		int flags;
+
+		(void)fcntl(fileno(strm), F_GETFL, &flags);
+		(void)fcntl(fileno(strm), F_SETFL, flags & ~O_NONBLOCK);
+	}
+
 	return 0;
 }
 
@@ -155,6 +163,13 @@ FileOutputStream::NextSegment( )
 		mjpeg_error_exit1( "Could not open for writing: %s", cur_filename );
 	}
     segment_len = 0;
+	{
+		int flags;
+
+		(void)fcntl(fileno(strm), F_GETFL, &flags);
+		(void)fcntl(fileno(strm), F_SETFL, flags & ~O_NONBLOCK);
+	}
+
 }
 
 void
@@ -208,6 +223,14 @@ IFileBitStream::IFileBitStream( const char *bs_filenam
 {
 	if ((fileh = fopen(bs_filename, "rb")) == NULL)
 	   mjpeg_error_exit1( "Unable to open file %s for reading.", bs_filename);
+
+	{
+		int flags;
+
+		(void)fcntl(fileno(fileh), F_GETFL, &flags);
+		(void)fcntl(fileno(fileh), F_SETFL, flags & ~O_NONBLOCK);
+	}
+
 	filename = strcpy( new char[strlen(bs_filename)+1], bs_filename );
     streamname = filename;
 
