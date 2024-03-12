--- gdk/wayland/gdkdisplay-wayland.c.orig	2024-03-12 11:52:13 UTC
+++ gdk/wayland/gdkdisplay-wayland.c
@@ -24,7 +24,9 @@
 #include <errno.h>
 #include <unistd.h>
 #include <fcntl.h>
+#ifdef HAVE_SYS_SYSMACROS_H
 #include <sys/sysmacros.h>
+#endif
 
 #ifdef HAVE_LINUX_MEMFD_H
 #include <linux/memfd.h>
