--- libgrive/src/util/File.cc.orig	2016-08-28 12:56:18 UTC
+++ libgrive/src/util/File.cc
@@ -32,6 +32,7 @@
 #include <sys/stat.h>
 #include <sys/types.h>
 #include <fcntl.h>
+#include <unistd.h>
 
 #ifdef WIN32
 	#include <io.h>
