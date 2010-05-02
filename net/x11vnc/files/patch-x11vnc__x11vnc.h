--- x11vnc/x11vnc.h.orig	2009-03-16 08:04:58.000000000 +1000
+++ x11vnc/x11vnc.h	2010-04-30 23:48:55.249699749 +1100
@@ -266,6 +266,10 @@
 #include <sys/ipc.h>
 #include <sys/shm.h>
 #include <X11/extensions/XShm.h>
+#ifndef X_ShmAttach
+#include <X11/Xmd.h>
+#include <X11/extensions/shmproto.h>
+#endif
 #endif
 #if LIBVNCSERVER_HAVE_SHMAT
 #include <sys/ipc.h>
