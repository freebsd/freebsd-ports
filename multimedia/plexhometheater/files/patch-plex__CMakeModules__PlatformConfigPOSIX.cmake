--- plex/CMakeModules/PlatformConfigPOSIX.cmake.orig	2014-05-23 21:04:41.000000000 +0800
+++ plex/CMakeModules/PlatformConfigPOSIX.cmake	2014-06-02 15:53:40.122706444 +0800
@@ -38,7 +38,12 @@
 endif(TARGET_RPI)
 
 ############ Check for pthread_setname -> HAVE_PTHREAD_SETNAME_NP
-set(HAVE_PTHREAD_SETNAME_NP 1)
+if(TARGET_FREEBSD)
+  set(HAVE_PTHREAD_SET_NAME_NP 1)
+else()
+  set(HAVE_PTHREAD_SETNAME_NP 1)
+endif()
+
 if(NOT TARGET_RPI)
   set(HAS_SDL_JOYSTICK 1)
 endif()
