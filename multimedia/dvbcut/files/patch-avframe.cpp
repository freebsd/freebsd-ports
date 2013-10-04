--- src/avframe.cpp.orig	2011-04-22 23:51:29.000000000 +0200
+++ src/avframe.cpp	2013-10-04 11:04:43.876355112 +0200
@@ -18,6 +18,7 @@
 
 /* $Id: avframe.cpp 141 2009-01-09 17:53:48Z too-tired $ */
 
+#include <sys/types.h>
 #include <qimage.h>
 #include <cstdlib>
 #include <cstdio>
