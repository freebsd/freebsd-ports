--- src/compositor-drm.c.orig	2016-05-19 21:36:04 UTC
+++ src/compositor-drm.c
@@ -33,7 +33,14 @@
 #include <fcntl.h>
 #include <unistd.h>
 #include <linux/input.h>
+#if defined(__FreeBSD__)
+#include <sys/consio.h>
+#include <sys/mouse.h>
+#include <sys/ioctl.h>
+#include <sys/socket.h>
+#else
 #include <linux/vt.h>
+#endif
 #include <assert.h>
 #include <sys/mman.h>
 #include <dlfcn.h>
@@ -46,14 +53,21 @@
 #include <gbm.h>
 #include <libudev.h>
 
+#if defined(__FreeBSD__)
+#include "kbdev.h"
+#endif
 #include "compositor.h"
 #include "compositor-drm.h"
 #include "shared/helpers.h"
 #include "shared/timespec-util.h"
 #include "gl-renderer.h"
 #include "pixman-renderer.h"
+/* #if !defined(__FreeBSD__) */
 #include "libbacklight.h"
+/* #endif */
+#if !defined(__FreeBSD__)
 #include "libinput-seat.h"
+#endif
 #include "launcher-util.h"
 #include "vaapi-recorder.h"
 #include "presentation-time-server-protocol.h"
@@ -79,11 +93,23 @@ struct drm_backend {
 	struct weston_backend base;
 	struct weston_compositor *compositor;
 
+#if defined(__FreeBSD__)
+	struct weston_seat syscons_seat;
+
+	int sysmouse_fd;
+	struct wl_event_source *sysmouse_source;
+
+	int kbd_fd;
+	struct kbdev_state *kbdst;
+	struct wl_event_source *kbd_source;
+#endif
 	struct udev *udev;
 	struct wl_event_source *drm_source;
 
+#if !defined(__FreeBSD__)
 	struct udev_monitor *udev_monitor;
 	struct wl_event_source *udev_drm_source;
+#endif
 
 	struct {
 		int id;
@@ -116,7 +142,9 @@ struct drm_backend {
 
 	uint32_t prev_state;
 
+#if !defined(__FreeBSD__)
 	struct udev_input input;
+#endif
 
 	int32_t cursor_width;
 	int32_t cursor_height;
@@ -183,7 +211,9 @@ struct drm_output {
 	struct weston_view *cursor_view;
 	int current_cursor;
 	struct drm_fb *current, *next;
+/* #if !defined(__FreeBSD__) */
 	struct backlight *backlight;
+/* #endif */
 
 	struct drm_fb *dumb[2];
 	pixman_image_t *image[2];
@@ -229,6 +259,10 @@ drm_output_set_cursor(struct drm_output 
 static void
 drm_output_update_msc(struct drm_output *output, unsigned int seq);
 
+static void
+page_flip_handler(int fd, unsigned int frame,
+		  unsigned int sec, unsigned int usec, void *data);
+
 static int
 drm_sprite_crtc_supported(struct drm_output *output, uint32_t supported)
 {
@@ -383,7 +417,7 @@ drm_fb_get_from_bo(struct gbm_bo *bo,
 				    format, handles, pitches, offsets,
 				    &fb->fb_id, 0);
 		if (ret) {
-			weston_log("addfb2 failed: %m\n");
+			weston_log("addfb2 failed: %s\n", strerror(errno));
 			backend->no_addfb2 = 1;
 			backend->sprites_are_broken = 1;
 		}
@@ -394,7 +428,7 @@ drm_fb_get_from_bo(struct gbm_bo *bo,
 				   fb->stride, fb->handle, &fb->fb_id);
 
 	if (ret) {
-		weston_log("failed to create kms fb: %m\n");
+		weston_log("failed to create kms fb: %s\n", strerror(errno));
 		goto err_free;
 	}
 
@@ -524,7 +558,8 @@ drm_output_render_gl(struct drm_output *
 
 	bo = gbm_surface_lock_front_buffer(output->gbm_surface);
 	if (!bo) {
-		weston_log("failed to lock front buffer: %m\n");
+		weston_log("failed to lock front buffer: %s\n",
+		    strerror(errno));
 		return;
 	}
 
@@ -596,7 +631,7 @@ drm_output_set_gamma(struct weston_outpu
 				 output->crtc_id,
 				 size, r, g, b);
 	if (rc)
-		weston_log("set gamma failed: %m\n");
+		weston_log("set gamma failed: %s\n", strerror(errno));
 }
 
 /* Determine the type of vblank synchronization to use for the output.
@@ -651,7 +686,7 @@ drm_output_repaint(struct weston_output 
 				     &output->connector_id, 1,
 				     &mode->mode_info);
 		if (ret) {
-			weston_log("set mode failed: %m\n");
+			weston_log("set mode failed: %s\n", strerror(errno));
 			goto err_pageflip;
 		}
 		output_base->set_dpms(output_base, WESTON_DPMS_ON);
@@ -660,7 +695,7 @@ drm_output_repaint(struct weston_output 
 	if (drmModePageFlip(backend->drm.fd, output->crtc_id,
 			    output->next->fb_id,
 			    DRM_MODE_PAGE_FLIP_EVENT, output) < 0) {
-		weston_log("queueing pageflip failed: %m\n");
+		weston_log("queueing pageflip failed: %s\n", strerror(errno));
 		goto err_pageflip;
 	}
 
@@ -773,16 +808,18 @@ drm_output_start_repaint_loop(struct wes
 						WP_PRESENTATION_FEEDBACK_INVALID);
 			return;
 		}
-	}
+	} else
+		weston_log("failed to get valid timestamp, ret=%d\n", ret);
 
 	/* Immediate query didn't provide valid timestamp.
 	 * Use pageflip fallback.
 	 */
 	fb_id = output->current->fb_id;
 
+	weston_log("Using page flip fallback\n");
 	if (drmModePageFlip(backend->drm.fd, output->crtc_id, fb_id,
 			    DRM_MODE_PAGE_FLIP_EVENT, output) < 0) {
-		weston_log("queueing pageflip failed: %m\n");
+		weston_log("queueing pageflip failed: %s\n", strerror(errno));
 		goto finish_frame;
 	}
 
@@ -856,9 +893,11 @@ page_flip_handler(int fd, unsigned int f
 
 	output->page_flip_pending = 0;
 
-	if (output->destroy_pending)
+	if (output->destroy_pending) {
 		drm_output_destroy(&output->base);
-	else if (!output->vblank_pending) {
+		return;
+	}
+	if (!output->vblank_pending) {
 		ts.tv_sec = sec;
 		ts.tv_nsec = usec * 1000;
 		weston_output_finish_frame(&output->base, &ts, flags);
@@ -1155,7 +1194,7 @@ cursor_bo_update(struct drm_backend *b, 
 	wl_shm_buffer_end_access(buffer->shm_buffer);
 
 	if (gbm_bo_write(bo, buf, sizeof buf) < 0)
-		weston_log("failed update cursor: %m\n");
+		weston_log("failed update cursor: %s\n", strerror(errno));
 }
 
 static void
@@ -1190,7 +1229,8 @@ drm_output_set_cursor(struct drm_output 
 		handle = gbm_bo_get_handle(bo).s32;
 		if (drmModeSetCursor(b->drm.fd, output->crtc_id, handle,
 				b->cursor_width, b->cursor_height)) {
-			weston_log("failed to set cursor: %m\n");
+			weston_log("failed to set cursor: %s\n",
+			    strerror(errno));
 			b->cursors_are_broken = 1;
 		}
 	}
@@ -1205,7 +1245,8 @@ drm_output_set_cursor(struct drm_output 
 
 	if (output->cursor_plane.x != x || output->cursor_plane.y != y) {
 		if (drmModeMoveCursor(b->drm.fd, output->crtc_id, x, y)) {
-			weston_log("failed to move cursor: %m\n");
+			weston_log("failed to move cursor: %s\n",
+			    strerror(errno));
 			b->cursors_are_broken = 1;
 		}
 
@@ -1315,8 +1356,10 @@ drm_output_destroy(struct weston_output 
 		return;
 	}
 
+/* #if !defined(__FreeBSD__) */
 	if (output->backlight)
 		backlight_destroy(output->backlight);
+/* #endif */
 
 	drmModeFreeProperty(output->dpms_prop);
 
@@ -1466,20 +1509,32 @@ on_drm_input(int fd, uint32_t mask, void
 static int
 init_drm(struct drm_backend *b, struct udev_device *device)
 {
+	struct _drmSetVersion ver;
 	const char *filename, *sysnum;
 	uint64_t cap;
 	int fd, ret;
 	clockid_t clk_id;
 
+#if defined(__FreeBSD__)
+	b->drm.id = udev_device_get_devnum(device);
+	if (b->drm.id < 0) {
+#else
 	sysnum = udev_device_get_sysnum(device);
 	if (sysnum)
 		b->drm.id = atoi(sysnum);
 	if (!sysnum || b->drm.id < 0) {
+#endif
 		weston_log("cannot get device sysnum\n");
 		return -1;
 	}
 
 	filename = udev_device_get_devnode(device);
+#if defined(__FreeBSD__)
+	char buf[128];
+	memset(buf, 0, sizeof(buf));
+	snprintf(buf, sizeof(buf) - 1, "%s/%s", udev_get_dev_path(b->udev), filename);
+	filename = buf;
+#endif
 	fd = weston_launcher_open(b->compositor->launcher, filename, O_RDWR);
 	if (fd < 0) {
 		/* Probably permissions error */
@@ -1493,6 +1548,20 @@ init_drm(struct drm_backend *b, struct u
 	b->drm.fd = fd;
 	b->drm.filename = strdup(filename);
 
+	ver.drm_di_major = 1;
+	ver.drm_di_minor = 1;
+	ver.drm_dd_major = -1;
+	ver.drm_dd_minor = -1;
+	/*
+	 * This call is needed for the PCI address of the graphics device to
+	 * be appended to the hw.dri.X.name sysctl node.
+	 */
+	ret = drmSetInterfaceVersion(fd, &ver);
+	if (ret != 0) {
+		weston_log("Error: failed to set drm interface version.\n");
+		return -1;
+	}
+
 	ret = drmGetCap(fd, DRM_CAP_TIMESTAMP_MONOTONIC, &cap);
 	if (ret == 0 && cap == 1)
 		clk_id = CLOCK_MONOTONIC;
@@ -1500,8 +1569,13 @@ init_drm(struct drm_backend *b, struct u
 		clk_id = CLOCK_REALTIME;
 
 	if (weston_compositor_set_presentation_clock(b->compositor, clk_id) < 0) {
+#if defined(__FreeBSD__)
+		weston_log("Error: failed to set presentation clock %ld.\n",
+			   clk_id);
+#else
 		weston_log("Error: failed to set presentation clock %d.\n",
 			   clk_id);
+#endif
 		return -1;
 	}
 
@@ -1677,6 +1751,7 @@ drm_subpixel_to_wayland(int drm_value)
 	}
 }
 
+/* #if !defined(__FreeBSD__) */
 /* returns a value between 0-255 range, where higher is brighter */
 static uint32_t
 drm_get_backlight(struct drm_output *output)
@@ -1712,6 +1787,7 @@ drm_set_backlight(struct weston_output *
 
 	backlight_set_brightness(output->backlight, new_brightness);
 }
+/* #endif */
 
 static drmModePropertyPtr
 drm_get_prop(int fd, drmModeConnectorPtr connector, const char *name)
@@ -2122,6 +2198,7 @@ parse_modeline(const char *s, drmModeMod
 	return 0;
 }
 
+#if !defined(__FreeBSD__)
 static void
 setup_output_seat_constraint(struct drm_backend *b,
 			     struct weston_output *output,
@@ -2144,6 +2221,7 @@ setup_output_seat_constraint(struct drm_
 					     &pointer->y);
 	}
 }
+#endif
 
 static int
 parse_gbm_format(const char *s, uint32_t default_value, uint32_t *gbm_format)
@@ -2376,6 +2454,7 @@ create_output_for_connector(struct drm_b
 		goto err_output;
 	}
 
+/* #if !defined(__FreeBSD__) */
 	output->backlight = backlight_init(drm_device,
 					   connector->connector_type);
 	if (output->backlight) {
@@ -2386,6 +2465,7 @@ create_output_for_connector(struct drm_b
 	} else {
 		weston_log("Failed to initialize backlight\n");
 	}
+/* #endif */
 
 	weston_compositor_add_output(b->compositor, &output->base);
 
@@ -2580,6 +2660,7 @@ create_outputs(struct drm_backend *b, ui
 	return 0;
 }
 
+#if !defined(__FreeBSD__)
 static void
 update_outputs(struct drm_backend *b, struct udev_device *drm_device)
 {
@@ -2682,6 +2763,200 @@ udev_drm_event(int fd, uint32_t mask, vo
 
 	return 1;
 }
+#endif
+
+#if defined(__FreeBSD__)
+static int
+drm_kbd_handler(int fd, uint32_t mask, void *data)
+{
+	int i, n;
+	struct kbdev_event evs[64];
+
+	struct drm_backend *b = (struct drm_backend *)data;
+
+	fcntl(b->kbd_fd, F_SETFL, O_NONBLOCK);
+	n = kbdev_read_events(b->kbdst, evs, 64);
+	if (n <= 0)
+		return 0;
+
+	for (i = 0; i < n; i++) {
+		notify_key(&b->syscons_seat, weston_compositor_get_time(),
+		    evs[i].keycode,
+		    evs[i].pressed ? WL_KEYBOARD_KEY_STATE_PRESSED
+				   : WL_KEYBOARD_KEY_STATE_RELEASED,
+		    STATE_UPDATE_AUTOMATIC);
+	}
+
+	return 1;
+}
+
+static int
+drm_sysmouse_handler(int fd, uint32_t mask, void *data)
+{
+	char buf[128];
+	int xdelta, ydelta, zdelta;
+	wl_fixed_t xf, yf;
+	int nm;
+	static int oldmask = 7;
+	uint32_t time;
+	int k, n;
+
+	struct drm_backend *b = (struct drm_backend *)data;
+
+	k = 0;
+	if ((n = read(b->sysmouse_fd, buf, sizeof(buf))) <= 0) {
+		if (n < 0 && errno != EAGAIN)
+			weston_log("failed to read from sysmouse fd: %s\n",
+			    strerror(errno));
+		return 0;
+	}
+
+	for (k = 0; k < n; k += 8) {
+		if (n -k < 8 || (buf[0] & 0x80) == 0 || (buf[7] & 0x80) != 0)
+			continue;
+
+		xdelta = buf[k+1] + buf[k+3];
+		ydelta = buf[k+2] + buf[k+4];
+		ydelta = -ydelta;
+		zdelta = (buf[k+5] > 0 && buf[k+6] == 0) ? buf[k+5] | 0x80 : buf[k+5] + buf[k+6];
+
+		time = weston_compositor_get_time();
+		struct weston_pointer_axis_event ev_axis;
+		ev_axis.axis = WL_POINTER_AXIS_VERTICAL_SCROLL;
+		ev_axis.value = wl_fixed_from_int(((char)zdelta)*10);
+		notify_axis(&b->syscons_seat, weston_compositor_get_time(), &ev_axis);
+
+		if (xdelta != 0 || ydelta != 0) {
+			xf = wl_fixed_from_int(xdelta);
+			yf = wl_fixed_from_int(ydelta);
+			struct weston_pointer_motion_event ev_motion;
+			ev_motion.dx = xf;
+			ev_motion.dy = yf;
+			notify_motion(&b->syscons_seat, time, &ev_motion);
+		}
+
+		nm = buf[k+0] & 7;
+		if (nm != oldmask) {
+			if ((nm & 4) != (oldmask & 4)) {
+				notify_button(&b->syscons_seat, time, BTN_LEFT,
+				    (nm & 4) ? WL_POINTER_BUTTON_STATE_RELEASED
+					     : WL_POINTER_BUTTON_STATE_PRESSED);
+			}
+			if ((nm & 2) != (oldmask & 2)) {
+				notify_button(&b->syscons_seat, time, BTN_MIDDLE,
+				    (nm & 2) ? WL_POINTER_BUTTON_STATE_RELEASED
+					     : WL_POINTER_BUTTON_STATE_PRESSED);
+			}
+			if ((nm & 1) != (oldmask & 1)) {
+				notify_button(&b->syscons_seat, time, BTN_RIGHT,
+				    (nm & 1) ? WL_POINTER_BUTTON_STATE_RELEASED
+					     : WL_POINTER_BUTTON_STATE_PRESSED);
+			}
+			oldmask = nm;
+		}
+	}
+
+	return 1;
+}
+
+static int
+drm_input_sysmouse_open(struct drm_backend *b)
+{
+	if (b->sysmouse_fd == -1) {
+		b->sysmouse_fd = weston_launcher_open(b->compositor->launcher,
+		    "/dev/sysmouse", O_RDONLY | O_CLOEXEC);
+		if (b->sysmouse_fd < 0)
+			return -1;
+	}
+
+	int lvl = 1;
+	fcntl(b->sysmouse_fd, F_SETFL, O_NONBLOCK);
+	ioctl(b->sysmouse_fd, MOUSE_SETLEVEL, &lvl);
+
+	return 0;
+}
+
+static int
+drm_input_create(struct drm_backend *b)
+{
+	if (drm_input_sysmouse_open(b) != 0)
+		return -1;
+
+	if (b->kbd_fd == -1) {
+		b->kbd_fd = weston_launcher_ttyfd(b->compositor->launcher);
+		printf("tty fd from weston-launcher: %d\n", b->kbd_fd);
+		if (b->kbd_fd < 0) {
+			close(b->sysmouse_fd);
+			return -1;
+		}
+	}
+
+	fcntl(b->kbd_fd, F_SETFL, O_NONBLOCK);
+	b->kbdst = kbdev_new_state(b->kbd_fd);
+	if (b->kbdst == NULL)
+		return -1;
+
+	weston_seat_init(&b->syscons_seat, b->compositor, "syscons");
+
+	weston_seat_init_pointer(&b->syscons_seat);
+	weston_seat_init_keyboard(&b->syscons_seat, NULL);
+
+	notify_motion_absolute(&b->syscons_seat, weston_compositor_get_time(),
+	    50, 50);
+
+	b->sysmouse_source = wl_event_loop_add_fd(
+	    wl_display_get_event_loop(b->compositor->wl_display),
+	    b->sysmouse_fd, WL_EVENT_READABLE, drm_sysmouse_handler, b);
+
+	b->kbd_source = wl_event_loop_add_fd(
+	    wl_display_get_event_loop(b->compositor->wl_display),
+	    b->kbd_fd, WL_EVENT_READABLE, drm_kbd_handler, b);
+
+	return 0;
+}
+
+static void
+drm_input_enable(struct drm_backend *b)
+{
+	struct wl_array keys;
+	struct wl_event_loop *loop =
+	    wl_display_get_event_loop(b->compositor->wl_display);
+
+	/* Re-enable keyboard input */
+	b->kbd_source = wl_event_loop_add_fd(
+	    wl_display_get_event_loop(b->compositor->wl_display),
+	    b->kbd_fd, WL_EVENT_READABLE, drm_kbd_handler, b);
+	kbdev_reset_state(b->kbdst);
+	wl_array_init(&keys);
+	notify_keyboard_focus_in(&b->syscons_seat, &keys, STATE_UPDATE_AUTOMATIC);
+	wl_array_release(&keys);
+
+	/* Re-enable mouse input */
+	if (drm_input_sysmouse_open(b) == 0) {
+		b->sysmouse_source = wl_event_loop_add_fd(loop,
+		    b->sysmouse_fd, WL_EVENT_READABLE,
+		    drm_sysmouse_handler, b);
+	} else {
+		weston_log("Re-initializing sysmouse input failed\n");
+	}
+}
+
+static void
+drm_input_disable(struct drm_backend *b)
+{
+	if (b->sysmouse_source != NULL) {
+		wl_event_source_remove(b->sysmouse_source);
+		b->sysmouse_source = NULL;
+	}
+	if (b->kbd_source != NULL) {
+		wl_event_source_remove(b->kbd_source);
+		b->kbd_source = NULL;
+	}
+	notify_keyboard_focus_out(&b->syscons_seat);
+	close(b->sysmouse_fd);
+	b->sysmouse_fd = -1;
+}
+#endif
 
 static void
 drm_restore(struct weston_compositor *ec)
@@ -2694,9 +2969,15 @@ drm_destroy(struct weston_compositor *ec
 {
 	struct drm_backend *b = (struct drm_backend *) ec->backend;
 
+#if defined(__FreeBSD__)
+	wl_event_source_remove(b->sysmouse_source);
+	wl_event_source_remove(b->kbd_source);
+	close(b->sysmouse_fd);
+#else
 	udev_input_destroy(&b->input);
 
 	wl_event_source_remove(b->udev_drm_source);
+#endif
 	wl_event_source_remove(b->drm_source);
 
 	destroy_sprites(b);
@@ -2737,9 +3018,10 @@ drm_backend_set_modes(struct drm_backend
 				     &drm_mode->mode_info);
 		if (ret < 0) {
 			weston_log(
-				"failed to set mode %dx%d for output at %d,%d: %m\n",
+				"failed to set mode %dx%d for output at %d,%d: %s\n",
 				drm_mode->base.width, drm_mode->base.height,
-				output->base.x, output->base.y);
+				output->base.x, output->base.y,
+				strerror(errno));
 		}
 	}
 }
@@ -2757,10 +3039,18 @@ session_notify(struct wl_listener *liste
 		compositor->state = b->prev_state;
 		drm_backend_set_modes(b);
 		weston_compositor_damage_all(compositor);
+#if defined(__FreeBSD__)
+		drm_input_enable(b);
+#else
 		udev_input_enable(&b->input);
+#endif
 	} else {
 		weston_log("deactivating session\n");
+#if defined(__FreeBSD__)
+		drm_input_disable(b);
+#else
 		udev_input_disable(&b->input);
+#endif
 
 		b->prev_state = compositor->state;
 		weston_compositor_offscreen(compositor);
@@ -2797,24 +3087,42 @@ session_notify(struct wl_listener *liste
  * If no such device is found, the first DRM device reported by udev is used.
  */
 static struct udev_device*
+#if defined(__FreeBSD__)
+find_primary_gpu(struct drm_backend *b)
+#else
 find_primary_gpu(struct drm_backend *b, const char *seat)
+#endif
 {
 	struct udev_enumerate *e;
 	struct udev_list_entry *entry;
+/* #if defined(__FreeBSD__) */
+	/* struct udev_device *device, *drm_device; */
+/* #else */
 	const char *path, *device_seat, *id;
 	struct udev_device *device, *drm_device, *pci;
+/* #endif */
 
 	e = udev_enumerate_new(b->udev);
+/* #if defined(__FreeBSD__) */
+/* 	udev_enumerate_add_match_expr(e, "driver", "drm"); */
+/* 	udev_enumerate_add_match_regex(e, "name", "card[0-9]*"); */
+/* #else */
 	udev_enumerate_add_match_subsystem(e, "drm");
 	udev_enumerate_add_match_sysname(e, "card[0-9]*");
+/* #endif */
 
 	udev_enumerate_scan_devices(e);
 	drm_device = NULL;
 	udev_list_entry_foreach(entry, udev_enumerate_get_list_entry(e)) {
+/* #if defined(__FreeBSD__) */
+		/* device = udev_list_entry_get_device(entry); */
+/* #else */
 		path = udev_list_entry_get_name(entry);
 		device = udev_device_new_from_syspath(b->udev, path);
+/* #endif */
 		if (!device)
 			continue;
+#if !defined(__FreeBSD__)
 		device_seat = udev_device_get_property_value(device, "ID_SEAT");
 		if (!device_seat)
 			device_seat = default_seat;
@@ -2834,6 +3142,7 @@ find_primary_gpu(struct drm_backend *b, 
 				break;
 			}
 		}
+#endif
 
 		if (!drm_device)
 			drm_device = device;
@@ -2904,7 +3213,7 @@ recorder_frame_notify(struct wl_listener
 	ret = vaapi_recorder_frame(output->recorder, fd,
 				   output->current->stride);
 	if (ret < 0) {
-		weston_log("[libva recorder] aborted: %m\n");
+		weston_log("[libva recorder] aborted: %s\n", strerror(errno));
 		recorder_destroy(output);
 	}
 }
@@ -3041,11 +3350,15 @@ drm_backend_create(struct weston_composi
 	const char *seat_id = default_seat;
 
 	weston_log("initializing drm backend\n");
+	loop = wl_display_get_event_loop(compositor->wl_display);
 
 	b = zalloc(sizeof *b);
 	if (b == NULL)
 		return NULL;
 
+	b->sysmouse_fd = -1;
+	b->kbd_fd = -1;
+
 	/*
 	 * KMS support for hardware planes cannot properly synchronize
 	 * without nuclear page flip. Without nuclear/atomic, hw plane
@@ -3086,12 +3399,22 @@ drm_backend_create(struct weston_composi
 	b->session_listener.notify = session_notify;
 	wl_signal_add(&compositor->session_signal, &b->session_listener);
 
-	drm_device = find_primary_gpu(b, seat_id);
+#if defined(__FreeBSD__)
+	drm_device = find_primary_gpu(b);
+#else
+ 	drm_device = find_primary_gpu(b, param->seat_id);
+#endif
 	if (drm_device == NULL) {
 		weston_log("no drm device found\n");
 		goto err_udev;
 	}
-	path = udev_device_get_syspath(drm_device);
+
+#if defined(__FreeBSD__)
+	/* XXX no sysfs on DragonFly, just use devnode for log output */
+	path = udev_device_get_devnode(drm_device);
+#else
+ 	path = udev_device_get_syspath(drm_device);
+#endif
 
 	if (init_drm(b, drm_device) < 0) {
 		weston_log("failed to initialize kms\n");
@@ -3120,8 +3443,12 @@ drm_backend_create(struct weston_composi
 	wl_list_init(&b->sprite_list);
 	create_sprites(b);
 
+#if defined(__FreeBSD__)
+	if (drm_input_create(b) < 0) {
+#else
 	if (udev_input_init(&b->input,
 			    compositor, b->udev, seat_id) < 0) {
+#endif
 		weston_log("failed to create input devices\n");
 		goto err_sprite;
 	}
@@ -3138,11 +3465,11 @@ drm_backend_create(struct weston_composi
 
 	path = NULL;
 
-	loop = wl_display_get_event_loop(compositor->wl_display);
 	b->drm_source =
 		wl_event_loop_add_fd(loop, b->drm.fd,
 				     WL_EVENT_READABLE, on_drm_input, b);
 
+#if !defined(__FreeBSD__)
 	b->udev_monitor = udev_monitor_new_from_netlink(b->udev, "udev");
 	if (b->udev_monitor == NULL) {
 		weston_log("failed to intialize udev monitor\n");
@@ -3159,6 +3486,7 @@ drm_backend_create(struct weston_composi
 		weston_log("failed to enable udev-monitor receiving\n");
 		goto err_udev_monitor;
 	}
+#endif
 
 	udev_device_unref(drm_device);
 
@@ -3183,13 +3511,17 @@ drm_backend_create(struct weston_composi
 
 	return b;
 
+#if !defined(__FreeBSD__)
 err_udev_monitor:
 	wl_event_source_remove(b->udev_drm_source);
 	udev_monitor_unref(b->udev_monitor);
 err_drm_source:
+#endif
 	wl_event_source_remove(b->drm_source);
 err_udev_input:
+#if !defined(__FreeBSD__)
 	udev_input_destroy(&b->input);
+#endif
 err_sprite:
 	if (b->gbm)
 		gbm_device_destroy(b->gbm);
