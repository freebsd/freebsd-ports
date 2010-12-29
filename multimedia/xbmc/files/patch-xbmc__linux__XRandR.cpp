--- ./xbmc/linux/XRandR.cpp.orig	2010-10-10 20:44:23.000000000 +0200
+++ ./xbmc/linux/XRandR.cpp	2010-12-01 12:17:34.256914833 +0100
@@ -29,6 +29,11 @@
 #include "tinyXML/tinyxml.h"
 #include "../xbmc/utils/log.h"
 
+#if defined(__FreeBSD__)
+#include <sys/types.h>
+#include <sys/wait.h>
+#endif
+
 using namespace std;
 
 CXRandR::CXRandR(bool query)
