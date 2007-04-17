--- coreapi/linphonecore.c.orig	Thu Apr  5 00:19:40 2007
+++ coreapi/linphonecore.c	Fri Apr 13 01:43:09 2007
@@ -29,11 +29,9 @@
 #include "exevents.h"
 
 
-#ifdef INET6  
 #ifndef WIN32
 #include <netdb.h>  
 #endif
-#endif
 
 
 static const char *liblinphone_version=LIBLINPHONE_VERSION;
@@ -1179,7 +1177,9 @@
 
 void linphone_core_init_media_streams(LinphoneCore *lc){
 	lc->audiostream=audio_stream_new(linphone_core_get_audio_port(lc),linphone_core_ipv6_enabled(lc));
+#ifdef VIDEO_ENABLED
 	lc->videostream=video_stream_new(linphone_core_get_video_port(lc),linphone_core_ipv6_enabled(lc));
+#endif
 }
 
 void linphone_core_start_media_streams(LinphoneCore *lc, LinphoneCall *call){
