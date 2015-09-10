--- modules/lua/vlc.h.orig	2015-07-11 03:08:07.625881252 +0000
+++ modules/lua/vlc.h	2015-07-11 03:08:25.711881262 +0000
@@ -38,6 +38,7 @@
 #include <vlc_stream.h>
 #include <vlc_demux.h>
 
+#define LUA_COMPAT_APIINTCASTS
 #define LUA_COMPAT_MODULE
 #include <lua.h>        /* Low level lua C API */
 #include <lauxlib.h>    /* Higher level C API */
