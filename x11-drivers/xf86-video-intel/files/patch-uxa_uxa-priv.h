--- uxa/uxa-priv.h.orig	2009-05-12 19:12:11.000000000 -0500
+++ uxa/uxa-priv.h	2010-02-21 12:27:32.000000000 -0600
@@ -42,8 +42,7 @@
 #define NEED_EVENTS
 #include <X11/Xproto.h>
 #ifdef MITSHM
-#define _XSHM_SERVER_
-#include <X11/extensions/shmstr.h>
+#include <X11/extensions/shmproto.h>
 #endif
 #include "scrnintstr.h"
 #include "pixmapstr.h"
@@ -319,17 +318,11 @@
 extern const GCOps uxa_ops;
 
 #ifdef MITSHM
-extern ShmFuncs uxa_shm_funcs;
-
 /* XXX these come from shmint.h, which isn't exported by the server */
-void
-ShmRegisterFuncs(ScreenPtr pScreen, ShmFuncsPtr funcs);
 
-void
-ShmSetPixmapFormat(ScreenPtr pScreen, int format);
+#include "shmint.h"
 
-void
-fbShmPutImage(XSHM_PUT_IMAGE_ARGS);
+extern ShmFuncs uxa_shm_funcs;
 
 #endif
 
