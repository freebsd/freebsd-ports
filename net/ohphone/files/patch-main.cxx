--- ./main.cxx.orig	2006-04-07 02:21:49.000000000 +0800
+++ ./main.cxx	2008-03-03 23:07:51.000000000 +0800
@@ -184,6 +184,8 @@
  */
 
 #include <ptlib.h>
+#include <ptlib/sound.h>
+#include <ptlib/video.h>
 #include <ptclib/random.h>
 
 #include "main.h"
@@ -224,7 +226,7 @@
 #include "xlibvid.h"
 #endif
 
-#ifdef P_SDL
+#if P_SDL
 #include <ptclib/vsdl.h>
 #endif
 
@@ -554,7 +556,7 @@
             "                          :      svga256  256 colour VGA (Linux only)\n"
             "                          :      svga     full colour VGA (Linux only)\n"
 #endif
-#ifdef P_SDL
+#if P_SDL
             "                          :      sdl      Use Simple DirectMedia Library\n"
 #endif
 #ifdef HAS_X11
@@ -855,7 +857,7 @@
         && !(videoReceiveDevice *= "svga")
         && !(videoReceiveDevice *= "svga256")
 #endif
-#ifdef P_SDL
+#if P_SDL
         && !(videoReceiveDevice *= "sdl")
 #endif
 #ifdef HAS_X11
@@ -2065,7 +2067,7 @@
   if ((!isEncoding) || videoLocal)
     PAssert(!videoReceiveDevice.IsEmpty(), "video display created without device type");
 
-#ifdef P_SDL
+#if P_SDL
      // Dump received video to SDL 
     if (videoReceiveDevice *= "sdl") 
       display = new PSDLVideoDevice();
