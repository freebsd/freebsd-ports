--- client/dvb/cx88_dvb_buffer.cpp.orig	2012-10-04 22:36:01 UTC
+++ client/dvb/cx88_dvb_buffer.cpp
@@ -30,7 +30,7 @@
 #include <new>
 extern "C"
 {
-   #include <cuse4bsd.h>
+   #include <cuse.h>
 }
 #include "cx88_dvb_buffer.h"
 
