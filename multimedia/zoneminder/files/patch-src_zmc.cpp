--- src/zmc.cpp.orig	2009-05-08 13:17:10.000000000 +0400
+++ src/zmc.cpp	2011-04-08 17:48:07.405805978 +0400
@@ -19,7 +19,7 @@
 
 #include <getopt.h>
 #include <signal.h>
-#include <values.h>
+#include <limits.h>
 
 #include "zm.h"
 #include "zm_db.h"
@@ -27,12 +27,14 @@
 #include "zm_signal.h"
 #include "zm_monitor.h"
 
+#define MAXINT INT_MAX
+
 void Usage()
 {
 	fprintf( stderr, "zmc -d <device_path> or -r <proto> -H <host> -P <port> -p <path> or -f <file_path> or -m <monitor_id>\n" );
 
 	fprintf( stderr, "Options:\n" );
-	fprintf( stderr, "  -d, --device <device_path>               : For local cameras, device to access. E.g /dev/video0 etc\n" );
+	fprintf( stderr, "  -d, --device <device_path>               : For local cameras, device to access. E.g /dev/bktr0 etc\n" );
 	fprintf( stderr, "  -r <proto> -H <host> -P <port> -p <path> : For remote cameras\n" );
 	fprintf( stderr, "  -f, --file <file_path>                   : For local images, jpg file to access.\n" );
 	fprintf( stderr, "  -m, --monitor <monitor_id>               : For sources associated with a single monitor\n" );
