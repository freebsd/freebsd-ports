--- server/libvncserver/rfb/rfbproto.h.orig	Fri Jul 16 18:16:16 2004
+++ server/libvncserver/rfb/rfbproto.h	Fri Jul 16 18:16:39 2004
@@ -60,7 +60,9 @@
 #include <rfb/rfbint.h>
 #else
 #include <config.h>
+#ifdef HAVE_STDINT_H
 #include <stdint.h>
+#endif
 #endif
 #endif
 #include <rfb/keysym.h>
