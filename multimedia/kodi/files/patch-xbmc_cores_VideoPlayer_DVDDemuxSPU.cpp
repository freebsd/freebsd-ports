--- xbmc/cores/VideoPlayer/DVDDemuxSPU.cpp.orig	2017-11-14 16:55:01 UTC
+++ xbmc/cores/VideoPlayer/DVDDemuxSPU.cpp
@@ -18,6 +18,7 @@
  *
  */
 
+#include <stdlib.h>
 #include "DVDDemuxSPU.h"
 #include "DVDClock.h"
 #include "DVDCodecs/Overlay/DVDOverlaySpu.h"
