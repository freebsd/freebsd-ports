--- libs/libmythtv/DVD/dvdringbuffer.h.orig	2018-01-11 12:39:22 UTC
+++ libs/libmythtv/DVD/dvdringbuffer.h
@@ -21,7 +21,7 @@ extern "C" {
 #include "libavcodec/avcodec.h"
 }
 
-#include "dvdnav/dvdnav.h"
+#include "../../../external/libmythdvdnav/dvdnav/dvdnav/dvdnav.h"
 
 /** \class MythDVDContext
  *  \brief Encapsulates playback context at any given moment.
