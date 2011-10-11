--- src/video_out/xxmc.h.orig
+++ src/video_out/xxmc.h
@@ -79,6 +79,7 @@
 #include <X11/extensions/Xvlib.h>
 #ifdef HAVE_VLDXVMC
   #include <X11/extensions/vldXvMC.h>
+  #include <X11/extensions/XvMClib.h>
 #else
   #include <X11/extensions/XvMClib.h>
   #include <X11/extensions/XvMC.h>
