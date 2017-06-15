--- main.cxx.orig	2006-04-06 18:21:49 UTC
+++ main.cxx
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
 
@@ -554,7 +556,7 @@ void OhPhone::Main()
             "                          :      svga256  256 colour VGA (Linux only)\n"
             "                          :      svga     full colour VGA (Linux only)\n"
 #endif
-#ifdef P_SDL
+#if P_SDL
             "                          :      sdl      Use Simple DirectMedia Library\n"
 #endif
 #ifdef HAS_X11
@@ -855,7 +857,7 @@ BOOL MyH323EndPoint::Initialise(PConfigA
         && !(videoReceiveDevice *= "svga")
         && !(videoReceiveDevice *= "svga256")
 #endif
-#ifdef P_SDL
+#if P_SDL
         && !(videoReceiveDevice *= "sdl")
 #endif
 #ifdef HAS_X11
@@ -2065,7 +2067,7 @@ BOOL MyH323EndPoint::OpenVideoChannel(H3
   if ((!isEncoding) || videoLocal)
     PAssert(!videoReceiveDevice.IsEmpty(), "video display created without device type");
 
-#ifdef P_SDL
+#if P_SDL
      // Dump received video to SDL 
     if (videoReceiveDevice *= "sdl") 
       display = new PSDLVideoDevice();
