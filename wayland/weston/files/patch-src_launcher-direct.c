--- src/launcher-direct.c.orig	2016-02-17 05:50:41 UTC
+++ src/launcher-direct.c
@@ -31,17 +31,29 @@
 #include <signal.h>
 #include <sys/stat.h>
 #include <sys/ioctl.h>
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
 
@@ -106,6 +118,69 @@ vt_handler(int signal_number, void *data
 	return 1;
 }
 
+/* #if defined(__FreeBSD__) */
+/* static char * */
+/* get_maj_min_driver(struct launcher_direct *launcher, int major, int minor) */
+/* { */
+/* 	struct udev_enumerate *enumerate; */
+/* 	struct udev_list_entry *current; */
+/* 	struct udev_device *dev; */
+/* 	/\* prop_dictionary_t dict; *\/ */
+/* 	char buf1[16], buf2[16]; */
+/* 	char *str = NULL; */
+/* 	int ret; */
+
+/* 	enumerate = udev_enumerate_new(launcher->udev_ctx); */
+/* 	if (enumerate == NULL) { */
+/* 		warn("udev_enumerate_new"); */
+/* 		return NULL; */
+/* 	} */
+
+/* 	memset(buf1, 0, sizeof(buf1)); */
+/* 	memset(buf2, 0, sizeof(buf2)); */
+/* 	snprintf(buf1, 15, "%d", major); */
+/* 	snprintf(buf2, 15, "%d", minor); */
+/* 	udev_enumerate_add_match_expr(enumerate, "major", buf1); */
+/* 	udev_enumerate_add_match_expr(enumerate, "minor", buf2); */
+
+/* 	ret = udev_enumerate_scan_devices(enumerate); */
+/* 	if (ret != 0) { */
+/* 		warn("udev_enumerate_scan_devices ret = %d", ret); */
+/* 		udev_enumerate_unref(enumerate); */
+/* 		return NULL; */
+/* 	} */
+
+/* 	current = udev_enumerate_get_list_entry(enumerate); */
+/* 	if (current == NULL) { */
+/* 		printf("No devices found.\n"); */
+/* 	} else { */
+/* 		udev_list_entry_foreach(current, current) { */
+/* 			dev = udev_list_entry_get_device(current); */
+/* 			if (dev == NULL) */
+/* 				continue; */
+/* 			/\* dict = udev_device_get_dictionary(dev); *\/ */
+/* 			/\* if (dict == NULL) *\/ */
+/* 			/\* 	continue; *\/ */
+/* 			if (str != NULL) { */
+/* 				free(str); */
+/* 				break; */
+/* 			} */
+/* 			str = udev_device_get_sysname(dev); */
+/* 			/\* str = prop_string_cstring(prop_dictionary_get(dict, *\/ */
+/* 			    /\* "driver")); *\/ */
+/* 			if (str == NULL) */
+/* 				break; */
+/* 			printf("major: %d, minor: %d for driver %s\n", */
+/* 			    major, minor, str); */
+/* 		} */
+/* 	} */
+
+/* 	udev_enumerate_unref(enumerate); */
+
+/* 	return str; */
+/* } */
+/* #endif */
+
 static int
 setup_tty(struct launcher_direct *launcher, int tty)
 {
@@ -122,7 +197,11 @@ setup_tty(struct launcher_direct *launch
 			return -1;
 		}
 	} else {
+#if defined(__FreeBSD__)
+		snprintf(tty_device, sizeof tty_device, "/dev/ttyv%d", tty);
+#else
 		snprintf(tty_device, sizeof tty_device, "/dev/tty%d", tty);
+#endif
 		launcher->tty = open(tty_device, O_RDWR | O_CLOEXEC);
 		if (launcher->tty == -1) {
 			weston_log("couldn't open tty %s: %m\n", tty_device);
@@ -130,6 +209,18 @@ setup_tty(struct launcher_direct *launch
 		}
 	}
 
+#if defined(__FreeBSD__)
+	/* if (fstat(launcher->tty, &buf) == 0) { */
+	/* 	char *ttydrv = get_maj_min_driver(wl, major(buf.st_rdev), */
+	/* 	    minor(buf.st_rdev)); */
+	/* 	if (ttydrv == NULL || strcmp("sc", ttydrv) != 0) */
+	/* 		errx(1, "weston-launch must be run from a virtual " */
+	/* 		    "terminal"); */
+	/* 	free(ttydrv); */
+	/* 	if (launcher->ttynr == -1) */
+	/* 		launcher->ttynr = minor(buf.st_rdev) + 1; */
+	/* } */
+#else
 	if (fstat(launcher->tty, &buf) == -1 ||
 	    major(buf.st_rdev) != TTY_MAJOR || minor(buf.st_rdev) == 0) {
 		weston_log("%s not a vt\n", tty_device);
@@ -137,7 +228,9 @@ setup_tty(struct launcher_direct *launch
 			   "use --tty to specify a tty\n");
 		goto err_close;
 	}
+#endif
 
+#if !defined(__FreeBSD__)
 	ret = ioctl(launcher->tty, KDGETMODE, &kd_mode);
 	if (ret) {
 		weston_log("failed to get VT mode: %m\n");
@@ -148,20 +241,28 @@ setup_tty(struct launcher_direct *launch
 			   "is another display server running?\n", tty_device);
 		goto err_close;
 	}
+#endif
 
+#if !defined(__FreeBSD__)
 	ioctl(launcher->tty, VT_ACTIVATE, minor(buf.st_rdev));
 	ioctl(launcher->tty, VT_WAITACTIVE, minor(buf.st_rdev));
+#endif
 
 	if (ioctl(launcher->tty, KDGKBMODE, &launcher->kb_mode)) {
 		weston_log("failed to read keyboard mode: %m\n");
 		goto err_close;
 	}
 
+#if defined(__FreeBSD__)
+	if (ioctl(launcher->tty, KDSKBMODE, K_CODE))
+		err(1, "failed to set K_CODE keyboard mode");
+#else
 	if (ioctl(launcher->tty, KDSKBMUTE, 1) &&
 	    ioctl(launcher->tty, KDSKBMODE, K_OFF)) {
 		weston_log("failed to set K_OFF keyboard mode: %m\n");
 		goto err_close;
 	}
+#endif
 
 	ret = ioctl(launcher->tty, KDSETMODE, KD_GRAPHICS);
 	if (ret) {
@@ -169,6 +270,14 @@ setup_tty(struct launcher_direct *launch
 		goto err_close;
 	}
 
+#if defined(__FreeBSD__)
+	/* Put the tty into raw mode */
+	struct termios tios;
+	tcgetattr(launcher->tty, &tios);
+	cfmakeraw(&tios);
+	tcsetattr(launcher->tty, TCSAFLUSH, &tios);
+#endif
+
 	/*
 	 * SIGRTMIN is used as global VT-acquire+release signal. Note that
 	 * SIGRT* must be tested on runtime, as their exact values are not
@@ -184,6 +293,9 @@ setup_tty(struct launcher_direct *launch
 	mode.mode = VT_PROCESS;
 	mode.relsig = SIGRTMIN;
 	mode.acqsig = SIGRTMIN;
+#if defined(__FreeBSD__)
+	mode.frsig = SIGIO; /* not used, but has to be set anyway */
+#endif
 	if (ioctl(launcher->tty, VT_SETMODE, &mode) < 0) {
 		weston_log("failed to take control of vt handling\n");
 		goto err_close;
@@ -218,6 +330,7 @@ launcher_direct_open(struct weston_launc
 		return -1;
 	}
 
+#if !defined(__FreeBSD__)
 	if (major(s.st_rdev) == DRM_MAJOR) {
 		launcher->drm_fd = fd;
 		if (!is_drm_master(fd)) {
@@ -226,7 +339,7 @@ launcher_direct_open(struct weston_launc
 			return -1;
 		}
 	}
-
+#endif
 	return fd;
 }
 
@@ -242,10 +355,15 @@ launcher_direct_restore(struct weston_la
 	struct launcher_direct *launcher = wl_container_of(launcher_base, launcher, base);
 	struct vt_mode mode = { 0 };
 
+#if defined(__FreeBSD__)
+	if (ioctl(launcher->tty, KDSKBMODE, launcher->kb_mode))
+#else
 	if (ioctl(launcher->tty, KDSKBMUTE, 0) &&
 	    ioctl(launcher->tty, KDSKBMODE, launcher->kb_mode))
+#endif
 		weston_log("failed to restore kb mode: %m\n");
 
+
 	if (ioctl(launcher->tty, KDSETMODE, KD_TEXT))
 		weston_log("failed to set KD_TEXT mode on tty: %m\n");
 
