--- client/dvb/cx88_dvb_frontend.cpp.orig	2014-11-15 03:08:05 UTC
+++ client/dvb/cx88_dvb_frontend.cpp
@@ -31,7 +31,7 @@
 #include <new>
 extern "C"
 {
-   #include <cuse4bsd.h>
+   #include <cuse.h>
 }
 #include "../cx88_debug.h"
 #include "cx88_dvb_frontend.h"
