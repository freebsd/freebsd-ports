--- rkward/rbackend/rklocalesupport.cpp.orig	Mon Apr  2 21:59:00 2007
+++ rkward/rbackend/rklocalesupport.cpp	Wed Apr 11 19:41:03 2007
@@ -17,6 +17,7 @@
 
 #include "rklocalesupport.h"
 
+#include <langinfo.h>
 #include <qtextcodec.h>
 
 /* NOTE: This code in this file is an almost literal copy taken from setupLocaleMapper in qtextcodec.cpp in Qt 3.3.8 !*/
