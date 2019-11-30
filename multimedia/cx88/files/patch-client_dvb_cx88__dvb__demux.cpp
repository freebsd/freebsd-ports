--- client/dvb/cx88_dvb_demux.cpp.orig	2012-12-05 17:23:14 UTC
+++ client/dvb/cx88_dvb_demux.cpp
@@ -28,7 +28,7 @@
 #include <sys/types.h>
 extern "C"
 {
-   #include <cuse4bsd.h>
+   #include <cuse.h>
 }
 #include "../cx88_debug.h"
 #include "cx88_dvb_demux.h"
