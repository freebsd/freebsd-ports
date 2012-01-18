--- ./xbmc/windowing/X11/XRandR.cpp.orig	2011-12-23 04:12:21.000000000 +0100
+++ ./xbmc/windowing/X11/XRandR.cpp	2012-01-02 10:14:38.000000000 +0100
@@ -30,6 +30,11 @@
 #include "tinyXML/tinyxml.h"
 #include "../xbmc/utils/log.h"
 
+#if defined(__FreeBSD__)
+#include <sys/types.h>
+#include <sys/wait.h>
+#endif
+
 using namespace std;
 
 CXRandR::CXRandR(bool query)
