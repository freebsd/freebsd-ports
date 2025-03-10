../gdk/wayland/gdkdmabuf-wayland.c:12:10: fatal error: 'sys/sysmacros.h' file not found
   12 | #include <sys/sysmacros.h>
      |          ^~~~~~~~~~~~~~~~~

--- gdk/wayland/gdkdmabuf-wayland.c.orig	2024-09-13 14:11:36 UTC
+++ gdk/wayland/gdkdmabuf-wayland.c
@@ -9,7 +9,9 @@
 
 #include <fcntl.h>
 #include <sys/mman.h>
+#ifdef HAVE_SYS_SYSMACROS_H
 #include <sys/sysmacros.h>
+#endif
 
 #include "linux-dmabuf-unstable-v1-client-protocol.h"
 
