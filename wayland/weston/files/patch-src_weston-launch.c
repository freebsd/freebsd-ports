--- src/weston-launch.c.orig	2015-10-24 00:02:43 UTC
+++ src/weston-launch.c
@@ -33,7 +33,7 @@
 #include <poll.h>
 #include <errno.h>
 
-#include <error.h>
+#include <err.h>
 #include <getopt.h>
 
 #include <sys/types.h>
@@ -41,14 +41,25 @@
 #include <sys/stat.h>
 #include <sys/wait.h>
 #include <sys/socket.h>
+#if defined(__FreeBSD__)
+#include <event2/event.h>
+#else
 #include <sys/signalfd.h>
+#endif
 #include <signal.h>
 #include <unistd.h>
 #include <fcntl.h>
 
+#if defined(__FreeBSD__)
+#include <termios.h>
+#include <sys/consio.h>
+#include <sys/kbio.h>
+#include <libudev.h>
+#else
 #include <linux/vt.h>
 #include <linux/major.h>
 #include <linux/kd.h>
+#endif
 
 #include <pwd.h>
 #include <grp.h>
@@ -60,8 +71,11 @@
 
 #include "weston-launch.h"
 
+#if !defined(__FreeBSD__)
 #define DRM_MAJOR 226
+#endif
 
+#if !defined(__FreeBSD__)
 #ifndef KDSKBMUTE
 #define KDSKBMUTE	0x4B51
 #endif
@@ -69,6 +83,7 @@
 #ifndef EVIOCREVOKE
 #define EVIOCREVOKE _IOW('E', 0x91, int)
 #endif
+#endif
 
 #define MAX_ARGV_SIZE 256
 
@@ -100,10 +115,16 @@ struct weston_launch {
 	int sock[2];
 	int drm_fd;
 	int last_input_fd;
+	char *input_path[16];
 	int kb_mode;
 	struct passwd *pw;
 
+#if defined(__FreeBSD__)
+	struct udev *udev_ctx;
+	struct event_base *evbase;
+#else
 	int signalfd;
+#endif
 
 	pid_t child;
 	int verbose;
@@ -113,7 +134,11 @@ struct weston_launch {
 union cmsg_data { unsigned char b[4]; int fd; };
 
 static gid_t *
+#if defined(__FreeBSD__)
+read_groups(int *cnt)
+#else
 read_groups(void)
+#endif
 {
 	int n;
 	gid_t *groups;
@@ -121,7 +146,8 @@ read_groups(void)
 	n = getgroups(0, NULL);
 
 	if (n < 0) {
-		fprintf(stderr, "Unable to retrieve groups: %m\n");
+		fprintf(stderr, "Unable to retrieve groups: %s\n",
+		    strerror(errno));
 		return NULL;
 	}
 
@@ -130,10 +156,12 @@ read_groups(void)
 		return NULL;
 
 	if (getgroups(n, groups) < 0) {
-		fprintf(stderr, "Unable to retrieve groups: %m\n");
+		fprintf(stderr, "Unable to retrieve groups: %s\n",
+		    strerror(errno));
 		free(groups);
 		return NULL;
 	}
+	*cnt = n;
 	return groups;
 }
 
@@ -147,15 +175,26 @@ weston_launch_allowed(struct weston_laun
 	char *session, *seat;
 	int err;
 #endif
+#if defined(__FreeBSD__)
+	int cnt;
+#endif
 
 	if (getuid() == 0)
 		return true;
 
 	gr = getgrnam("weston-launch");
 	if (gr) {
+#if defined(__FreeBSD__)
+		groups = read_groups(&cnt);
+#else
 		groups = read_groups();
+#endif
 		if (groups) {
+#if defined(__FreeBSD__)
+			for (i = 0; i < cnt; ++i) {
+#else
 			for (i = 0; groups[i]; ++i) {
+#endif
 				if (groups[i] == gr->gr_gid) {
 					free(groups);
 					return true;
@@ -226,10 +265,10 @@ static int
 setup_launcher_socket(struct weston_launch *wl)
 {
 	if (socketpair(AF_LOCAL, SOCK_SEQPACKET, 0, wl->sock) < 0)
-		error(1, errno, "socketpair failed");
+		err(1, "socketpair");
 
 	if (fcntl(wl->sock[0], F_SETFD, FD_CLOEXEC) < 0)
-		error(1, errno, "fcntl failed");
+		err(1, "fcntl");
 
 	return 0;
 }
@@ -256,14 +295,23 @@ setup_signals(struct weston_launch *wl)
 	sigaddset(&mask, SIGCHLD);
 	sigaddset(&mask, SIGINT);
 	sigaddset(&mask, SIGTERM);
+#if !defined(__FreeBSD__)
 	sigaddset(&mask, SIGUSR1);
 	sigaddset(&mask, SIGUSR2);
+#endif
 	ret = sigprocmask(SIG_BLOCK, &mask, NULL);
 	assert(ret == 0);
 
+#if defined(__FreeBSD__)
+	signal(SIGUSR1, SIG_IGN);
+	signal(SIGUSR2, SIG_IGN);
+#endif
+
+#if !defined(__FreeBSD__)
 	wl->signalfd = signalfd(-1, &mask, SFD_NONBLOCK | SFD_CLOEXEC);
 	if (wl->signalfd < 0)
 		return -errno;
+#endif
 
 	return 0;
 }
@@ -289,6 +337,69 @@ send_reply(struct weston_launch *wl, int
 	return len;
 }
 
+/* #if defined(__FreeBSD__) */
+/* static char * */
+/* get_maj_min_driver(struct weston_launch *wl, int major, int minor) */
+/* { */
+/* 	struct udev_enumerate *enumerate; */
+/* 	struct udev_list_entry *current; */
+/* 	struct udev_device *dev; */
+/* 	/\* prop_dictionary_t dict; *\/ */
+/* 	char buf1[16], buf2[16]; */
+/* 	char *str = NULL; */
+/* 	int ret; */
+
+/* 	enumerate = udev_enumerate_new(wl->udev_ctx); */
+/* 	if (enumerate == NULL) { */
+/* 		warn("udev_enumerate_new"); */
+/* 		return NULL; */
+/* 	} */
+
+/* 	memset(buf1, 0, sizeof(buf1)); */
+/* 	memset(buf2, 0, sizeof(buf2)); */
+/* 	snprintf(buf1, 15, "%d", major); */
+/* 	snprintf(buf2, 15, "%d", minor); */
+/* 	/\* udev_enumerate_add_match_expr(enumerate, "major", buf1); *\/ */
+/* 	/\* udev_enumerate_add_match_expr(enumerate, "minor", buf2); *\/ */
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
 handle_open(struct weston_launch *wl, struct msghdr *msg, ssize_t len)
 {
@@ -300,6 +411,8 @@ handle_open(struct weston_launch *wl, st
 	struct iovec iov;
 	struct weston_launcher_open *message;
 	union cmsg_data *data;
+	char *path = NULL;
+	char *devdrv;
 
 	message = msg->msg_iov->iov_base;
 	if ((size_t)len < sizeof(*message))
@@ -308,20 +421,46 @@ handle_open(struct weston_launch *wl, st
 	/* Ensure path is null-terminated */
 	((char *) message)[len-1] = '\0';
 
-	fd = open(message->path, message->flags);
+	path = strdup(message->path);
+	fd = open(path, message->flags);
 	if (fd < 0) {
-		fprintf(stderr, "Error opening device %s: %m\n",
-			message->path);
+		fprintf(stderr, "Error opening device %s: %s\n",
+			path, strerror(errno));
 		goto err0;
 	}
+	printf("opened device %s to fd %d\n", path, fd);
 
 	if (fstat(fd, &s) < 0) {
 		close(fd);
 		fd = -1;
-		fprintf(stderr, "Failed to stat %s\n", message->path);
+		fprintf(stderr, "Failed to stat %s\n", path);
 		goto err0;
 	}
 
+/* #if defined(__FreeBSD__) */
+	/* devdrv = get_maj_min_driver(wl, major(s.st_rdev), minor(s.st_rdev)); */
+	/* if (devdrv == NULL || (strcmp("sysmouse", devdrv) != 0 && */
+	/* 		       strcmp("drm", devdrv) != 0)) { */
+	/* 	free(devdrv); */
+	/* 	close(fd); */
+	/* 	fd = -1; */
+	/* 	fprintf(stderr, "Device %s is not an input or drm device\n", */
+	/* 		message->path); */
+	/* 	goto err0; */
+	/* } */
+	/* if (devdrv != NULL && strcmp("sysmouse", devdrv) == 0) { */
+	/* 	if (fd-3 >= 16) { */
+	/* 		free(devdrv); */
+	/* 		warnx("no more than 16 input devices allowed"); */
+	/* 		close(fd); */
+	/* 		fd = -1; */
+	/* 		goto err0; */
+	/* 	} */
+	/* } */
+	/* free(devdrv); */
+/* #endif */
+
+#if !defined(__FreeBSD__)
 	if (major(s.st_rdev) != INPUT_MAJOR &&
 	    major(s.st_rdev) != DRM_MAJOR) {
 		close(fd);
@@ -330,6 +469,7 @@ handle_open(struct weston_launch *wl, st
 			message->path);
 		goto err0;
 	}
+#endif
 
 err0:
 	memset(&nmsg, 0, sizeof nmsg);
@@ -352,31 +492,74 @@ err0:
 
 	if (wl->verbose)
 		fprintf(stderr, "weston-launch: opened %s: ret: %d, fd: %d\n",
-			message->path, ret, fd);
+			path, ret, fd);
 	do {
 		len = sendmsg(wl->sock[0], &nmsg, 0);
 	} while (len < 0 && errno == EINTR);
 
-	if (len < 0)
+	if (len < 0) {
+#if defined(__FreeBSD__)
+		free(path);
+#endif
 		return -1;
+	}
 
+#if defined(__FreeBSD__)
+	// TODO: Something better here.. udev?
+	if(strstr(path, "drm")) {
+		wl->drm_fd = fd;
+	} else if(strstr(path, "input")) {
+		if (wl->last_input_fd < fd)
+			wl->last_input_fd = fd;
+		wl->input_path[fd-3] = path;
+	} else {
+		free(path);
+		path = NULL;
+	}
+	/* devdrv = get_maj_min_driver(wl, major(s.st_rdev), minor(s.st_rdev)); */
+	/* if (fd != -1 && devdrv != NULL && strcmp("drm", devdrv)) */
+	/* 	wl->drm_fd = fd; */
+	/* if (fd != -1 && devdrv != NULL && strcmp("sysmouse", devdrv) == 0) { */
+	/* 	/\* */
+	/* 	 * XXX with libdevattr, we can actually get the device path */
+	/* 	 *     from the fd. */
+	/* 	 *\/ */
+	/* 	if (wl->last_input_fd < fd) */
+	/* 		wl->last_input_fd = fd; */
+	/* 	wl->input_path[fd-3] = path; */
+	/* } else { */
+	/* 	free(path); */
+	/* 	path = NULL; */
+	/* } */
+	free(devdrv);
+#else
 	if (fd != -1 && major(s.st_rdev) == DRM_MAJOR)
 		wl->drm_fd = fd;
 	if (fd != -1 && major(s.st_rdev) == INPUT_MAJOR &&
 	    wl->last_input_fd < fd)
 		wl->last_input_fd = fd;
+#endif
 
 	return 0;
 }
 
+#if defined(__FreeBSD__)
+static void
+handle_socket_msg(evutil_socket_t fd, short events, void *arg)
+{
+	struct weston_launch *wl = arg;
+#else
 static int
 handle_socket_msg(struct weston_launch *wl)
 {
+#endif
 	char control[CMSG_SPACE(sizeof(int))];
 	char buf[BUFSIZ];
 	struct msghdr msg;
 	struct iovec iov;
+#if !defined(__FreeBSD__)
 	int ret = -1;
+#endif
 	ssize_t len;
 	struct weston_launcher_message *message;
 
@@ -392,17 +575,32 @@ handle_socket_msg(struct weston_launch *
 		len = recvmsg(wl->sock[0], &msg, 0);
 	} while (len < 0 && errno == EINTR);
 
-	if (len < 1)
+	if (len < 1) {
+#if defined(__FreeBSD__)
+		if (errno != EAGAIN)
+			event_base_loopbreak(wl->evbase);
+		return;
+#else
 		return -1;
+#endif
+	}
 
 	message = (void *) buf;
 	switch (message->opcode) {
 	case WESTON_LAUNCHER_OPEN:
+#if defined(__FreeBSD__)
+		handle_open(wl, &msg, len);
+#else
 		ret = handle_open(wl, &msg, len);
+#endif
 		break;
 	}
 
+#if defined(__FreeBSD__)
+	return;
+#else
 	return ret;
+#endif
 }
 
 static void
@@ -411,7 +609,9 @@ quit(struct weston_launch *wl, int statu
 	struct vt_mode mode = { 0 };
 	int err;
 
+#if !defined(__FreeBSD__)
 	close(wl->signalfd);
+#endif
 	close(wl->sock[0]);
 
 	if (wl->new_user) {
@@ -422,12 +622,18 @@ quit(struct weston_launch *wl, int statu
 		pam_end(wl->ph, err);
 	}
 
+#if defined(__FreeBSD__)
+	if (ioctl(wl->tty, KDSKBMODE, wl->kb_mode))
+#else
 	if (ioctl(wl->tty, KDSKBMUTE, 0) &&
 	    ioctl(wl->tty, KDSKBMODE, wl->kb_mode))
-		fprintf(stderr, "failed to restore keyboard mode: %m\n");
+#endif
+		fprintf(stderr, "failed to restore keyboard mode: %s\n",
+		    strerror(errno));
 
 	if (ioctl(wl->tty, KDSETMODE, KD_TEXT))
-		fprintf(stderr, "failed to set KD_TEXT mode on tty: %m\n");
+		fprintf(stderr, "failed to set KD_TEXT mode on tty: %s\n",
+		    strerror(errno));
 
 	/* We have to drop master before we switch the VT back in
 	 * VT_AUTO, so we don't risk switching to a VT with another
@@ -447,28 +653,56 @@ close_input_fds(struct weston_launch *wl
 	struct stat s;
 	int fd;
 
+	printf("%s: closing input fds\n", __func__);
+
 	for (fd = 3; fd <= wl->last_input_fd; fd++) {
+#if defined(__FreeBSD__)
+		if (fstat(fd, &s) == 0) {
+			if (fd-3 < 16 && wl->input_path[fd-3] != NULL) {
+				printf("revoking access to device %s\n", wl->input_path[fd-3]);
+				revoke(wl->input_path[fd-3]);
+				free(wl->input_path[fd-3]);
+				wl->input_path[fd-3] = NULL;
+				close(fd);
+			}
+#else
 		if (fstat(fd, &s) == 0 && major(s.st_rdev) == INPUT_MAJOR) {
 			/* EVIOCREVOKE may fail if the kernel doesn't
 			 * support it, but all we can do is ignore it. */
 			ioctl(fd, EVIOCREVOKE, 0);
 			close(fd);
+#endif
 		}
 	}
 }
 
+#if defined(__FreeBSD__)
+static void
+handle_signal(evutil_socket_t fd, short events, void *arg)
+{
+	struct weston_launch *wl = arg;
+#else
 static int
 handle_signal(struct weston_launch *wl)
 {
 	struct signalfd_siginfo sig;
+#endif
 	int pid, status, ret;
 
+#if !defined(__FreeBSD__)
 	if (read(wl->signalfd, &sig, sizeof sig) != sizeof sig) {
-		error(0, errno, "reading signalfd failed");
+		err(0, "reading signalfd failed");
 		return -1;
 	}
+#endif
+
+#if defined(__FreeBSD__)
+	printf("%s: signal=%d\n", __func__, fd);
 
+	switch (fd) {
+#else
 	switch (sig.ssi_signo) {
+#endif
 	case SIGCHLD:
 		pid = waitpid(-1, &status, 0);
 		if (pid == wl->child) {
@@ -491,25 +725,58 @@ handle_signal(struct weston_launch *wl)
 	case SIGTERM:
 	case SIGINT:
 		if (wl->child)
+#if defined(__FreeBSD__)
+			kill(wl->child, fd);
+#else
 			kill(wl->child, sig.ssi_signo);
+#endif
 		break;
 	case SIGUSR1:
+		warnx("%s: leaving vt", __func__);
 		send_reply(wl, WESTON_LAUNCHER_DEACTIVATE);
 		close_input_fds(wl);
 		drmDropMaster(wl->drm_fd);
+#if defined(__FreeBSD__)
+		ioctl(wl->tty, VT_RELDISP, VT_TRUE);
+#else
 		ioctl(wl->tty, VT_RELDISP, 1);
+#endif
 		break;
 	case SIGUSR2:
+		warnx("%s: entering vt", __func__);
 		ioctl(wl->tty, VT_RELDISP, VT_ACKACQ);
+#if defined(__FreeBSD__)
+		ioctl(wl->tty, VT_WAITACTIVE, wl->ttynr);
+#endif
 		drmSetMaster(wl->drm_fd);
 		send_reply(wl, WESTON_LAUNCHER_ACTIVATE);
 		break;
 	default:
+#if defined(__FreeBSD__)
+		return;
+#else
 		return -1;
+#endif
 	}
 
+#if defined(__FreeBSD__)
+	return;
+#else
+	return 0;
+#endif
+}
+
+#if defined(__FreeBSD__)
+static int
+setup_udev(struct weston_launch *wl)
+{
+	wl->udev_ctx = udev_new();
+	if (wl->udev_ctx == NULL)
+		errx(1, "udev_new failed");
+
 	return 0;
 }
+#endif
 
 static int
 setup_tty(struct weston_launch *wl, const char *tty)
@@ -518,6 +785,14 @@ setup_tty(struct weston_launch *wl, cons
 	struct vt_mode mode = { 0 };
 	char *t;
 
+	wl->ttynr = -1;
+
+
+#if defined(__FreeBSD__)
+	if (tty) {
+		errx(1, "tty option not supported on DragonFly");
+	}
+#else
 	if (!wl->new_user) {
 		wl->tty = STDIN_FILENO;
 	} else if (tty) {
@@ -526,53 +801,111 @@ setup_tty(struct weston_launch *wl, cons
 			wl->tty = STDIN_FILENO;
 		else
 			wl->tty = open(tty, O_RDWR | O_NOCTTY);
-	} else {
+	}
+#endif
+	else {
+#if defined(__FreeBSD__)
+		int tty0 = open("/dev/ttyv0", O_WRONLY | O_CLOEXEC);
+#else
 		int tty0 = open("/dev/tty0", O_WRONLY | O_CLOEXEC);
+#endif
 		char filename[16];
 
 		if (tty0 < 0)
-			error(1, errno, "could not open tty0");
+			err(1, "could not open tty0");
 
 		if (ioctl(tty0, VT_OPENQRY, &wl->ttynr) < 0 || wl->ttynr == -1)
-			error(1, errno, "failed to find non-opened console");
+			err(1, "failed to find non-opened console");
 
+#if defined(__FreeBSD__)
+		snprintf(filename, sizeof filename, "/dev/ttyv%d", wl->ttynr - 1);
+		printf("%s: using tty %s\n", __func__, filename);
+#else
 		snprintf(filename, sizeof filename, "/dev/tty%d", wl->ttynr);
+#endif
 		wl->tty = open(filename, O_RDWR | O_NOCTTY);
 		close(tty0);
 	}
 
 	if (wl->tty < 0)
-		error(1, errno, "failed to open tty");
+		err(1, "failed to open tty");
 
+#if defined(__FreeBSD__)
+	/* if (fstat(wl->tty, &buf) == 0) { */
+	/* 	char *ttydrv = get_maj_min_driver(wl, major(buf.st_rdev), */
+	/* 	    minor(buf.st_rdev)); */
+	/* 	if (ttydrv == NULL || strcmp("sc", ttydrv) != 0) */
+	/* 		errx(1, "weston-launch must be run from a virtual " */
+	/* 		    "terminal"); */
+	/* 	free(ttydrv); */
+	/* 	if (wl->ttynr == -1) */
+	/* 		wl->ttynr = minor(buf.st_rdev) + 1; */
+	/* } */
+#else
 	if (fstat(wl->tty, &buf) == -1 ||
 	    major(buf.st_rdev) != TTY_MAJOR || minor(buf.st_rdev) == 0)
-		error(1, 0, "weston-launch must be run from a virtual terminal");
+		errx(1, "weston-launch must be run from a virtual terminal");
+#endif
 
 	if (tty) {
 		if (fstat(wl->tty, &buf) < 0)
-			error(1, errno, "stat %s failed", tty);
+			err(1, "stat: %s", tty);
 
+#if defined(__FreeBSD__)
+		/* char *ttydrv = get_maj_min_driver(wl, major(buf.st_rdev), */
+		/*     minor(buf.st_rdev)); */
+		/* if (ttydrv == NULL || strcmp("sc", ttydrv) != 0) */
+		/* 	errx(1, "invalid tty device: %s", tty); */
+		/* free(ttydrv); */
+#else
 		if (major(buf.st_rdev) != TTY_MAJOR)
-			error(1, 0, "invalid tty device: %s", tty);
+			errx(1, "invalid tty device: %s", tty);
 
-		wl->ttynr = minor(buf.st_rdev);
+#endif
+		wl->ttynr = minor(buf.st_rdev) + 1;
 	}
 
+#if defined(__FreeBSD__)
+	printf("%s: wl->ttynr = %d\n", __func__, wl->ttynr);
+	if (wl->ttynr > 0) {
+		if (ioctl(wl->tty, VT_ACTIVATE, wl->ttynr) != 0)
+			err(1, "VT_ACTIVATE");
+		if (ioctl(wl->tty, VT_WAITACTIVE, wl->ttynr) != 0)
+			err(1, "VT_ACTIVATE");
+	}
+#endif
+
 	if (ioctl(wl->tty, KDGKBMODE, &wl->kb_mode))
-		error(1, errno, "failed to get current keyboard mode: %m\n");
+		err(1, "failed to get current keyboard mode");
 
+#if defined(__FreeBSD__)
+	if (ioctl(wl->tty, KDSKBMODE, K_CODE))
+		err(1, "failed to set K_CODE keyboard mode");
+#else
 	if (ioctl(wl->tty, KDSKBMUTE, 1) &&
 	    ioctl(wl->tty, KDSKBMODE, K_OFF))
-		error(1, errno, "failed to set K_OFF keyboard mode: %m\n");
+		err(1, "failed to set K_OFF keyboard mode");
+#endif
 
 	if (ioctl(wl->tty, KDSETMODE, KD_GRAPHICS))
-		error(1, errno, "failed to set KD_GRAPHICS mode on tty: %m\n");
+		err(1, "failed to set KD_GRAPHICS mode on tty");
+
+#if defined(__FreeBSD__)
+	/* Put the tty into raw mode */
+	struct termios tios;
+	tcgetattr(wl->tty, &tios);
+	cfmakeraw(&tios);
+	tcsetattr(wl->tty, TCSAFLUSH, &tios);
+#endif
 
 	mode.mode = VT_PROCESS;
 	mode.relsig = SIGUSR1;
 	mode.acqsig = SIGUSR2;
+#if defined(__FreeBSD__)
+	mode.frsig = SIGIO; /* not used, but has to be set anyway */
+#endif
 	if (ioctl(wl->tty, VT_SETMODE, &mode) < 0)
-		error(1, errno, "failed to take control of vt handling\n");
+		err(1, "failed to take control of vt handling");
 
 	return 0;
 }
@@ -586,28 +919,37 @@ setup_session(struct weston_launch *wl)
 
 	if (wl->tty != STDIN_FILENO) {
 		if (setsid() < 0)
-			error(1, errno, "setsid failed");
+			err(1, "setsid");
 		if (ioctl(wl->tty, TIOCSCTTY, 0) < 0)
-			error(1, errno, "TIOCSCTTY failed - tty is in use");
+			err(1, "TIOCSCTTY failed - tty is in use");
 	}
 
 	term = getenv("TERM");
+	char *xdg_runtime = getenv("XDG_RUNTIME_DIR");
+#if defined(__FreeBSD__)
+	extern char **environ;
+	environ = NULL;
+#else
 	clearenv();
+#endif
 	if (term)
 		setenv("TERM", term, 1);
 	setenv("USER", wl->pw->pw_name, 1);
 	setenv("LOGNAME", wl->pw->pw_name, 1);
 	setenv("HOME", wl->pw->pw_dir, 1);
 	setenv("SHELL", wl->pw->pw_shell, 1);
+	setenv("XDG_RUNTIME_DIR", xdg_runtime, 1);
 
 	env = pam_getenvlist(wl->ph);
 	if (env) {
 		for (i = 0; env[i]; ++i) {
 			if (putenv(env[i]) != 0)
-				error(0, 0, "putenv %s failed", env[i]);
+				errx(0, "putenv %s failed", env[i]);
 		}
 		free(env);
 	}
+
+	chdir(wl->pw->pw_dir);
 }
 
 static void
@@ -618,7 +960,7 @@ drop_privileges(struct weston_launch *wl
 	    initgroups(wl->pw->pw_name, wl->pw->pw_gid) < 0 ||
 #endif
 	    setuid(wl->pw->pw_uid) < 0)
-		error(1, errno, "dropping privileges failed");
+		err(1, "dropping privileges failed");
 }
 
 static void
@@ -646,8 +988,28 @@ launch_compositor(struct weston_launch *
 	sigaddset(&mask, SIGTERM);
 	sigaddset(&mask, SIGCHLD);
 	sigaddset(&mask, SIGINT);
+//#if !defined(__FreeBSD__)
+	sigaddset(&mask, SIGUSR1);
+	sigaddset(&mask, SIGUSR2);
+//#endif
 	sigprocmask(SIG_UNBLOCK, &mask, NULL);
 
+#if defined(__FreeBSD__)
+	signal(SIGUSR1, SIG_DFL);
+	signal(SIGUSR2, SIG_DFL);
+#endif
+
+#if defined(__FreeBSD__)
+	child_argv[0] = "-/bin/sh";
+	child_argv[1] = "-c";
+	child_argv[2] = BINDIR "/weston \"$@\"";
+	child_argv[3] = "weston";
+	for (i = 0; i < argc; ++i)
+		child_argv[4 + i] = argv[i];
+	child_argv[4 + i] = NULL;
+
+	execv("/bin/sh", child_argv);
+#else
 	child_argv[0] = "/bin/sh";
 	child_argv[1] = "-l";
 	child_argv[2] = "-c";
@@ -658,7 +1020,8 @@ launch_compositor(struct weston_launch *
 	child_argv[5 + i] = NULL;
 
 	execv(child_argv[0], child_argv);
-	error(1, errno, "exec failed");
+#endif
+	err(1, "exec failed");
 }
 
 static void
@@ -692,7 +1055,7 @@ main(int argc, char *argv[])
 		case 'u':
 			wl.new_user = optarg;
 			if (getuid() != 0)
-				error(1, 0, "Permission denied. -u allowed for root only");
+				errx(1, "Permission denied. -u allowed for root only");
 			break;
 		case 't':
 			tty = optarg;
@@ -707,17 +1070,17 @@ main(int argc, char *argv[])
 	}
 
 	if ((argc - optind) > (MAX_ARGV_SIZE - 6))
-		error(1, E2BIG, "Too many arguments to pass to weston");
+		err(1, "Too many arguments to pass to weston");
 
 	if (wl.new_user)
 		wl.pw = getpwnam(wl.new_user);
 	else
 		wl.pw = getpwuid(getuid());
 	if (wl.pw == NULL)
-		error(1, errno, "failed to get username");
+		err(1, "failed to get username");
 
 	if (!weston_launch_allowed(&wl))
-		error(1, 0, "Permission denied. You should either:\n"
+		err(1, "Permission denied. You should either:\n"
 #ifdef HAVE_SYSTEMD_LOGIN
 		      " - run from an active and local (systemd) session.\n"
 #else
@@ -725,6 +1088,11 @@ main(int argc, char *argv[])
 #endif
 		      " - or add yourself to the 'weston-launch' group.");
 
+#if defined(__FreeBSD__)
+	if (setup_udev(&wl) < 0)
+		exit(EXIT_FAILURE);
+#endif
+
 	if (setup_tty(&wl, tty) < 0)
 		exit(EXIT_FAILURE);
 
@@ -739,15 +1107,59 @@ main(int argc, char *argv[])
 
 	wl.child = fork();
 	if (wl.child == -1)
-		error(EXIT_FAILURE, errno, "fork failed");
+		err(EXIT_FAILURE, "fork failed");
 
 	if (wl.child == 0)
 		launch_compositor(&wl, argc - optind, argv + optind);
 
 	close(wl.sock[1]);
+#if !defined(__FreeBSD__)
 	if (wl.tty != STDIN_FILENO)
 		close(wl.tty);
+#endif
+
+#if defined(__FreeBSD__)
+	wl.evbase = event_base_new();
+	struct event *sockev = event_new(wl.evbase, wl.sock[0],
+	    EV_READ | EV_PERSIST, handle_socket_msg, &wl);
+	struct event *chldev = evsignal_new(wl.evbase, SIGCHLD, handle_signal,
+	    &wl);
+	struct event *intev = evsignal_new(wl.evbase, SIGINT, handle_signal,
+	    &wl);
+	struct event *termev = evsignal_new(wl.evbase, SIGTERM, handle_signal,
+	    &wl);
+	struct event *usr1ev = evsignal_new(wl.evbase, SIGUSR1, handle_signal,
+	    &wl);
+	struct event *usr2ev = evsignal_new(wl.evbase, SIGUSR2, handle_signal,
+	    &wl);
 
+	event_add(sockev, NULL);
+	event_add(chldev, NULL);
+	event_add(intev, NULL);
+	event_add(termev, NULL);
+	event_add(usr1ev, NULL);
+	event_add(usr2ev, NULL);
+
+	event_base_loop(wl.evbase, 0);
+
+	event_del(sockev);
+	event_del(chldev);
+	event_del(intev);
+	event_del(termev);
+	event_del(usr1ev);
+	event_del(usr2ev);
+
+	event_free(chldev);
+	event_free(intev);
+	event_free(termev);
+	event_free(usr1ev);
+	event_free(usr2ev);
+	event_free(sockev);
+	event_base_free(wl.evbase);
+
+	if (wl.tty != STDIN_FILENO)
+		close(wl.tty);
+#else
 	while (1) {
 		struct pollfd fds[2];
 		int n;
@@ -759,12 +1171,13 @@ main(int argc, char *argv[])
 
 		n = poll(fds, 2, -1);
 		if (n < 0)
-			error(0, errno, "poll failed");
+			err(0, "poll failed");
 		if (fds[0].revents & POLLIN)
 			handle_socket_msg(&wl);
 		if (fds[1].revents)
 			handle_signal(&wl);
 	}
+#endif
 
 	return 0;
 }
