--- mplex/main.cpp.orig	Thu Dec  9 21:13:26 2004
+++ mplex/main.cpp	Mon Jul 18 21:11:07 2005
@@ -38,6 +38,7 @@
 #endif
 #include <ctype.h>
 #include <math.h>
+#include <fcntl.h>
 #include "cpu_accel.h"
 #include "mjpeg_types.h"
 #include "mjpeg_logging.h"
@@ -107,6 +108,13 @@
 		mjpeg_error_exit1( "Could not open for writing: %s", cur_filename );
 	}
 
+	{
+		int	flags;
+
+		(void)fcntl(fileno(strm), F_GETFL, &flags);
+		(void)fcntl(fileno(strm), F_SETFL, flags & ~O_NONBLOCK);
+	}
+
 	return 0;
 }
 
@@ -144,6 +152,12 @@
 	{
 		mjpeg_error_exit1( "Could not open for writing: %s", cur_filename );
 	}
+	{
+		int	flags;
+
+		(void)fcntl(fileno(strm), F_GETFL, &flags);
+		(void)fcntl(fileno(strm), F_SETFL, flags & ~O_NONBLOCK);
+	}
 }
 
 void
@@ -200,6 +214,14 @@
 	{
 		mjpeg_error_exit1( "Unable to open file %s for reading.", bs_filename);
 	}
+
+	{
+		int	flags;
+
+		(void)fcntl(fileno(fileh), F_GETFL, &flags);
+		(void)fcntl(fileno(fileh), F_SETFL, flags & ~O_NONBLOCK);
+	}
+
 	filename = strcpy( new char[strlen(bs_filename)+1], bs_filename );
