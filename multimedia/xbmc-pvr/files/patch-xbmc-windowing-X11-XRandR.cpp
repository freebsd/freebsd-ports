--- xbmc/windowing/X11/XRandR.cpp.orig
+++ xbmc/windowing/X11/XRandR.cpp
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
