--- src/zmu.cpp.orig	2011-02-16 00:59:06.000000000 +0300
+++ src/zmu.cpp	2011-05-05 18:31:35.038175339 +0400
@@ -18,7 +18,7 @@
 // 
 
 #include <getopt.h>
-
+#include <iostream>
 #include "zm.h"
 #include "zm_db.h"
 #include "zm_user.h"
@@ -435,7 +435,7 @@ int main( int argc, char *argv[] )
 				{
 					char timestamp_str[64] = "None";
 					if ( timestamp.tv_sec )
-						strftime( timestamp_str, sizeof(timestamp_str), "%Y-%m-%d %H:%M:%S", localtime( &timestamp.tv_sec ) );
+						strftime( timestamp_str, sizeof(timestamp_str), "%Y-%m-%d %H:%M:%S", localtime(  (time_t *) &timestamp.tv_sec  ) );
 					if ( image_idx == -1 )
 						printf( "Time of last image capture: %s.%02ld\n", timestamp_str, timestamp.tv_usec/10000 );
 					else
