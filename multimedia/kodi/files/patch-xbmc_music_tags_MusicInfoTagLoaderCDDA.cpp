--- xbmc/music/tags/MusicInfoTagLoaderCDDA.cpp.orig	2016-02-20 15:21:19 UTC
+++ xbmc/music/tags/MusicInfoTagLoaderCDDA.cpp
@@ -25,6 +25,7 @@
 #include "profiles/ProfilesManager.h"
 #include "storage/MediaManager.h"
 #include "utils/log.h"
+#include <stdlib.h>
 
 using namespace MUSIC_INFO;
 
