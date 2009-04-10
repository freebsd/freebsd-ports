--- plugins/media-keys/gsd-media-keys-manager.c.orig	2009-02-04 16:33:14.000000000 -0500
+++ plugins/media-keys/gsd-media-keys-manager.c	2009-02-27 14:05:26.000000000 -0500
@@ -64,6 +64,8 @@
 
 #if defined(__OpenBSD__)
 # define EJECT_COMMAND "eject -t /dev/cd0"
+#elif defined(__FreeBSD__)
+# define EJECT_COMMAND "cdcontrol eject"
 #else
 # define EJECT_COMMAND "eject -T"
 #endif
