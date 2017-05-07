--- src/launcher-weston-launch.c.orig	2016-02-17 05:50:41 UTC
+++ src/launcher-weston-launch.c
@@ -36,19 +36,31 @@
 #include <sys/ioctl.h>
 #include <fcntl.h>
 #include <unistd.h>
+
+#if defined(__FreeBSD__)
+#include <termios.h>
+#include <sys/consio.h>
+#include <sys/kbio.h>
+#include <libudev.h>
+#else
 #include <linux/vt.h>
-#include <linux/kd.h>
 #include <linux/major.h>
+#include <linux/kd.h>
+#endif
 
 #include "compositor.h"
 #include "weston-launch.h"
 #include "launcher-impl.h"
 
+#if !defined(__FreeBSD__)
 #define DRM_MAJOR 226
+#endif
 
+#if !defined(__FreeBSD__)
 #ifndef KDSKBMUTE
 #define KDSKBMUTE	0x4B51
 #endif
+#endif
 
 #ifdef HAVE_LIBDRM
 
@@ -133,7 +145,7 @@ launcher_weston_launch_open(struct westo
 	msg.msg_iovlen = 1;
 	msg.msg_control = control;
 	msg.msg_controllen = sizeof control;
-	
+
 	do {
 		len = recvmsg(launcher->fd, &msg, MSG_CMSG_CLOEXEC);
 	} while (len < 0 && errno == EINTR);
@@ -171,8 +183,12 @@ launcher_weston_launch_restore(struct we
 	struct launcher_weston_launch *launcher = wl_container_of(launcher_base, launcher, base);
 	struct vt_mode mode = { 0 };
 
+#if defined(__FreeBSD__)
+	if (ioctl(launcher->tty, KDSKBMODE, launcher->kb_mode))
+#else
 	if (ioctl(launcher->tty, KDSKBMUTE, 0) &&
 	    ioctl(launcher->tty, KDSKBMODE, launcher->kb_mode))
+#endif
 		weston_log("failed to restore kb mode: %m\n");
 
 	if (ioctl(launcher->tty, KDSETMODE, KD_TEXT))
@@ -254,7 +270,11 @@ launcher_weston_launch_connect(struct we
 		/* We don't get a chance to read out the original kb
 		 * mode for the tty, so just hard code K_UNICODE here
 		 * in case we have to clean if weston-launch dies. */
-		launcher->kb_mode = K_UNICODE;
+#if defined(__FreeBSD__)
+		launcher->kb_mode = K_XLATE;
+#else
+ 		launcher->kb_mode = K_UNICODE;
+#endif
 
 		loop = wl_display_get_event_loop(compositor->wl_display);
 		launcher->source = wl_event_loop_add_fd(loop, launcher->fd,
