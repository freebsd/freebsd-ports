--- client/dvb/cx88_dvb_capture.h.orig	2014-11-15 03:08:05 UTC
+++ client/dvb/cx88_dvb_capture.h
@@ -32,7 +32,7 @@
 #include <list>
 extern "C"
 {
-   #include <cuse4bsd.h>
+   #include <cuse.h>
 }
 #include "tuner_config.h"
 #include "cx88_capture.h"
