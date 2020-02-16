--- src/fs.h.orig	2020-02-14 04:46:53.262100000 +0000
+++ src/fs.h	2020-02-14 04:47:08.369514000 +0000
@@ -11,7 +11,6 @@
 #include <ext/stdio_filebuf.h>
 #endif
 
-#define BOOST_FILESYSTEM_NO_DEPRECATED
 #include <boost/filesystem.hpp>
 #include <boost/filesystem/fstream.hpp>
 
