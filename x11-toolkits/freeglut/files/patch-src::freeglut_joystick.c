
$FreeBSD$

--- src/freeglut_joystick.c.orig	Mon Nov 10 01:09:42 2003
+++ src/freeglut_joystick.c	Mon Nov 10 01:10:52 2003
@@ -57,7 +57,7 @@
 #   include <unistd.h>
 #   include <fcntl.h>
 #   if defined(__FreeBSD__) || defined(__NetBSD__)
-#   if __FreeBSD_version >= 500000
+#   if defined(__FreeBSD__)
 #       include <sys/joystick.h>
 #   else
 #       include <machine/joystick.h>
