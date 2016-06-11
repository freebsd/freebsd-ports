--- include/vlc_playlist.h.orig	2014-11-16 18:57:58 UTC
+++ include/vlc_playlist.h
@@ -24,13 +24,13 @@
 #ifndef VLC_PLAYLIST_H_
 #define VLC_PLAYLIST_H_
 
+#include <vlc_input.h>
+#include <vlc_events.h>
+
 # ifdef __cplusplus
 extern "C" {
 # endif
 
-#include <vlc_input.h>
-#include <vlc_events.h>
-
 TYPEDEF_ARRAY(playlist_item_t*, playlist_item_array_t)
 
 struct intf_thread_t;
