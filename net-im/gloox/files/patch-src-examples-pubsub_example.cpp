--- src/examples/pubsub_example.cpp.orig	2009-06-22 11:35:17.000000000 +0200
+++ src/examples/pubsub_example.cpp	2013-12-26 22:58:22.252225373 +0100
@@ -22,6 +22,7 @@
 #include <unistd.h>
 #include <stdio.h>
 #include <string>
+#include <ctime>
 
 #if defined( WIN32 ) || defined( _WIN32 )
 # include <windows.h>
