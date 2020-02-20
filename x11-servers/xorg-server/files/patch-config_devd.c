--- config/devd.c.orig	2017-03-16 05:24:43 UTC
+++ config/devd.c
@@ -0,0 +1,855 @@
+/*
+ * Copyright (c) 2012 Baptiste Daroussin
+ * Copyright (c) 2013, 2014 Alex Kozlov
+ * Copyright (c) 2014 Robert Millan
+ * Copyright (c) 2014 Jean-Sebastien Pedron
+ * Copyright (c) 2015 Hans Petter Selasky
+ * Copyright (c) 2015-2017 Rozhuk Ivan
+ * Copyright (c) 2016, 2017 Vladimir Kondratyev
+ * Copyright (c) 2017 Matthew Rezny
+ *
+ * Permission is hereby granted, free of charge, to any person obtaining a
+ * copy of this software and associated documentation files (the "Software"),
+ * to deal in the Software without restriction, including without limitation
+ * the rights to use, copy, modify, merge, publish, distribute, sublicense,
+ * and/or sell copies of the Software, and to permit persons to whom the
+ * Software is furnished to do so, subject to the following conditions:
+ *
+ * The above copyright notice and this permission notice (including the next
+ * paragraph) shall be included in all copies or substantial portions of the
+ * Software.
+ *
+ * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
+ * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
+ * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
+ * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
+ * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
+ * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
+ * DEALINGS IN THE SOFTWARE.
+ *
+ * Author: Baptiste Daroussin <bapt@FreeBSD.org>
+ */
+
+#ifdef HAVE_DIX_CONFIG_H
+#include <dix-config.h>
+#endif
+
+#include <sys/types.h>
+#include <sys/kbio.h>
+#include <sys/socket.h>
+#include <sys/stat.h>
+#include <sys/sysctl.h>
+#include <sys/un.h>
+#include <sys/mouse.h>
+#include <sys/consio.h>
+#include <sys/ioctl.h>
+#include <dev/evdev/input.h>
+#include <dev/usb/usb_ioctl.h>
+#include <dev/usb/usbhid.h>
+
+#include <ctype.h>
+#include <dirent.h>
+#include <errno.h>
+#include <fcntl.h>
+#include <stdlib.h>
+#include <stdio.h>
+#include <stdbool.h>
+#include <unistd.h>
+#include <string.h>
+#include <paths.h>
+#include <usbhid.h>
+
+#include "input.h"
+#include "inputstr.h"
+#include "hotplug.h"
+#include "config-backends.h"
+#include "os.h"
+
+#define	_IOC_READ	IOC_OUT
+
+#define	ULONG_BITS		(sizeof(unsigned long) * 8)
+#define	ULONG_CNT(__x)		(((__x) + ULONG_BITS - 1) / ULONG_BITS)
+#define ULONG_IS_BIT_SET(__x, __bit) (((const unsigned long*)(__x))[(__bit) / ULONG_BITS] & (1UL << (__bit % ULONG_BITS)))
+
+/* from: <linux/joystick.h> */
+#define JSIOCGNAME(len)		_IOC(_IOC_READ, 'j', 0x13, len)		/* get identifier string */
+
+/* WebCamD specific. */
+#define WEBCAMD_IOCTL_GET_USB_VENDOR_ID _IOR('q', 250, unsigned short)
+#define WEBCAMD_IOCTL_GET_USB_PRODUCT_ID _IOR('q', 251, unsigned short)
+#define WEBCAMD_IOCTL_GET_USB_SPEED	_IOR('q', 252, unsigned int)
+
+#ifdef COMPAT_32BIT
+	#define hid_pass_ptr(ptr)	((uint64_t)(uintptr_t)(ptr))
+#else
+	#define hid_pass_ptr(ptr)	(ptr)
+#endif
+
+#define _PATH_DEV_LEN		(sizeof(_PATH_DEV) - 1)
+#define DEVD_PATH_DEV		"devd:" _PATH_DEV
+#define DEVD_PATH_DEV_LEN	(sizeof(DEVD_PATH_DEV) - 1)
+#define DEVD_PATH_LEN		(DEVD_PATH_DEV_LEN - _PATH_DEV_LEN)
+
+#define DEVD_SOCK_PATH		_PATH_VARRUN "devd.pipe"
+
+#define DEVD_EVENT_ADD		'+'
+#define DEVD_EVENT_REMOVE	'-'
+#define DEVD_EVENT_NOTIFY	'!'
+
+#define RECONNECT_DELAY	(5 * 1000)
+
+#define is_meuqual(__v1, __v1sz, __v2, __v2sz)				\
+	((__v1sz) == (__v2sz) && NULL != (__v1) && NULL != (__v2) &&	\
+	 0 == memcmp((__v1), (__v2), (__v1sz)))
+
+#define is_meuqual_cstr(__cstr, __v, __vsz)				\
+	is_meuqual(__cstr, (sizeof(__cstr) - 1), __v, __vsz)
+
+#define is_de_euqual_cstr(__de, __cstr)					\
+	(NULL != (__de) &&						\
+	 is_meuqual((__de)->d_name, (__de)->d_namlen, __cstr, (sizeof(__cstr) - 1)))
+
+#define devd_get_val_cstr(__cstr, __buf, __bufsz, __valsz)		\
+	devd_get_val((__buf), (__bufsz), __cstr, (sizeof(__cstr) - 1),	\
+	(__valsz))
+
+static int devd_skt = 0;
+static char devd_buf[4096];
+static size_t devd_buf_used = 0;
+static int is_kbdmux = 0;
+static int evdev_support = 0;
+static OsTimerPtr rtimer = NULL;
+
+/* Input devices. */
+typedef struct hw_type_s {
+	const char	*dev_name;
+	size_t		dev_name_size;
+	size_t		path_offset;
+	int		is_hybrid; /* has both evdev and traditional interfaces */
+	int		flags;
+	const char	*xdriver; 
+} hw_type_t, *hw_type_p;
+
+/* xdriver can be set via config "InputClass" section.
+ * Do not set xdriver name if device have more than one
+ * xf86-input-* drivers.
+ * "input/event" can be handled by: xf86-input-libinput,
+ * xf86-input-evdev and xf86-input-wacom, let user choose.
+ */
+static hw_type_t hw_types[] = {
+	{ "uhid",	4, 0, 0, 0, NULL },
+	{ "ukbd",	4, 0, 1, ATTR_KEY | ATTR_KEYBOARD, "kbd" },
+	{ "atkbd",	5, 0, 1, ATTR_KEY | ATTR_KEYBOARD, "kbd" },
+	{ "kbdmux",	6, 0, 1, ATTR_KEY | ATTR_KEYBOARD, "kbd" },
+	{ "sysmouse",	8, 0, 1, ATTR_POINTER, "mouse" },
+	{ "ums",	3, 0, 1, ATTR_POINTER, "mouse" },
+	{ "psm",	3, 0, 1, ATTR_POINTER, "mouse" },
+	{ "vboxguest",	9, 0, 0, ATTR_POINTER, "vboxmouse" },
+	{ "joy",	3, 0, 0, ATTR_JOYSTICK, NULL },
+	{ "atp",	3, 0, 0, ATTR_TOUCHPAD, NULL },
+	{ "uep",	3, 0, 0, ATTR_TOUCHSCREEN, NULL },
+	{ "input/event",5, 6, 0, 0, NULL },
+	{ "input/js",	2, 6, 0, ATTR_JOYSTICK, NULL },
+	{ NULL,		0, 0, 0, NULL },
+};
+
+/* Input devices paths. */
+static hw_type_t hw_type_path[] = {
+	{ "input/",	0, 6, 0, NULL },
+	{ NULL,		0, 0, 0, NULL },
+};
+
+static size_t
+bits_calc(const unsigned long *bits, size_t off_start, size_t off_stop)
+{
+	size_t count = 0;
+
+	for (size_t i = off_start; i < off_stop; ++i) {
+		if (ULONG_IS_BIT_SET(bits, i)) {
+			++count;
+		}
+	}
+	return count;
+}
+
+static hw_type_p
+get_dev_type_by_name(const char *dev_name, size_t dev_name_size)
+{
+	if (!dev_name || !dev_name_size)
+		return NULL;
+
+	for (size_t i = 0; hw_types[i].dev_name; ++i) {
+		if (dev_name_size >= (hw_types[i].dev_name_size + hw_types[i].path_offset) &&
+		    !memcmp(dev_name, hw_types[i].dev_name, (hw_types[i].path_offset + hw_types[i].dev_name_size))) {
+			return &hw_types[i];
+		}
+	}
+	return NULL;
+}
+
+static hw_type_p
+get_dev_type_by_path(const char *dev_name, size_t dev_name_size, hw_type_p hw_type_cust)
+{
+	if (!dev_name || !dev_name_size || !hw_type_cust)
+		return NULL;
+
+	for (size_t i = 0; hw_type_path[i].dev_name; ++i) {
+		if (dev_name_size <= hw_type_path[i].path_offset ||
+		    memcmp(dev_name, hw_type_path[i].dev_name, hw_type_path[i].path_offset))
+			continue;
+		/* Path in white list. */
+		hw_type_cust->dev_name = dev_name;
+		hw_type_cust->flags = hw_type_path[i].flags;
+		hw_type_cust->xdriver = hw_type_path[i].xdriver;
+		hw_type_cust->path_offset = hw_type_path[i].path_offset;
+		size_t name_end = hw_type_cust->path_offset;
+		while (name_end < dev_name_size && !isdigit(dev_name[name_end]))
+			++name_end;
+		hw_type_cust->dev_name_size = (name_end - hw_type_cust->path_offset);
+		return hw_type_cust;
+	}
+	return NULL;
+}
+
+static int
+is_kbdmux_enabled(void)
+{
+	/* Xorg uses /dev/ttyv0 as a console device */
+	/* const char device[]="/dev/console"; */
+	static const char *device = _PATH_TTY "v0";
+
+	int fd = open(device, O_RDONLY);
+	if (fd < 0)
+		return 0;
+
+	keyboard_info_t info;
+	int ret = (ioctl(fd, KDGKBINFO, &info) == -1 ||
+	           memcmp(info.kb_name, "kbdmux", 6)) ? 0 : 1;
+	close(fd);
+	return ret;
+}
+
+/* Derived from EvdevProbe() function of xf86-input-evdev driver */
+static int
+get_evdev_flags(int fd)
+{
+	if (fd<0)
+		return 0;
+
+	unsigned long key_bits[ULONG_CNT(KEY_CNT)], rel_bits[ULONG_CNT(REL_CNT)], abs_bits[ULONG_CNT(ABS_CNT)];
+	size_t has_keys = 0, has_buttons = 0, has_lmr = 0, has_rel_axes = 0, has_abs_axes = 0, has_mt = 0;
+	if (ioctl(fd, EVIOCGBIT(EV_KEY, sizeof(key_bits)), key_bits) != -1) {
+		has_keys = bits_calc(key_bits, 0, BTN_MISC);
+		has_buttons = bits_calc(key_bits, BTN_MISC, BTN_JOYSTICK);
+		has_lmr = bits_calc(key_bits, BTN_LEFT, BTN_MIDDLE + 1);
+	}
+	if (ioctl(fd, EVIOCGBIT(EV_REL, sizeof(rel_bits)), rel_bits) != -1) {
+		has_rel_axes = bits_calc(rel_bits, 0, REL_CNT);
+	}
+	if (ioctl(fd, EVIOCGBIT(EV_ABS, sizeof(abs_bits)), abs_bits) != -1) {
+		has_abs_axes = bits_calc(abs_bits, 0, ABS_CNT);
+		has_mt = bits_calc(abs_bits, ABS_MT_SLOT, ABS_CNT);
+	}
+
+	int flags = 0;
+	if (has_abs_axes) {
+		if (has_mt) {
+			if (!has_buttons) {
+				/*
+				 * XXX: I'm not sure that joystick detection is
+				 * done right. xf86-input-evdev does not support them.
+				 */
+				if (ULONG_IS_BIT_SET(key_bits, BTN_JOYSTICK))
+					flags = ATTR_JOYSTICK;
+				else
+					++has_buttons;
+			}
+		}
+		if (!flags && ULONG_IS_BIT_SET(abs_bits, ABS_X) && ULONG_IS_BIT_SET(abs_bits, ABS_Y)) {
+			if (ULONG_IS_BIT_SET(key_bits, BTN_TOOL_PEN) ||
+			    ULONG_IS_BIT_SET(key_bits, BTN_STYLUS) ||
+			    ULONG_IS_BIT_SET(key_bits, BTN_STYLUS2))
+				flags = ATTR_TABLET;
+			else if (ULONG_IS_BIT_SET(abs_bits, ABS_PRESSURE) ||
+			         ULONG_IS_BIT_SET(key_bits, BTN_TOUCH)) {
+				if (has_lmr || ULONG_IS_BIT_SET(key_bits, BTN_TOOL_FINGER))
+					flags = ATTR_TOUCHPAD;
+				else
+					flags = ATTR_TOUCHSCREEN;
+			} else if (!(ULONG_IS_BIT_SET(rel_bits, REL_X) &&
+			             ULONG_IS_BIT_SET(rel_bits, REL_Y)) &&
+			            has_lmr) /* some touchscreens use BTN_LEFT rather than BTN_TOUCH */
+				flags = ATTR_TOUCHSCREEN;
+		}
+	}
+	if (!flags) {
+		if (has_keys)
+			flags = ATTR_KEY | ATTR_KEYBOARD;
+		else if (has_rel_axes || has_abs_axes || has_buttons)
+			flags = ATTR_POINTER;
+	}
+	return flags;
+}
+
+/* From: sys/dev/usb/usb_hid.c */
+static int
+hid_is_collection(report_desc_t s, uint32_t usage)
+{
+	struct hid_data* hd = hid_start_parse(s, ~0, -1);
+	if (!hd)
+		return 0;
+
+	struct hid_item hi;
+	int rc;
+	while ((rc = hid_get_item(hd, &hi))) {
+		 if (hi.kind == hid_collection && hi.usage == usage)
+			break;
+	}
+	hid_end_parse(hd);
+	return rc;
+}
+
+static int
+hid_is_mouse(report_desc_t s)
+{
+	struct hid_data* hd = hid_start_parse(s, (1 << hid_input), -1);
+	if (!hd)
+		return 0;
+
+	struct hid_item hi;
+	int found = 0, mdepth = 0;
+	while (hid_get_item(hd, &hi)) {
+		switch (hi.kind) {
+		case hid_collection:
+			if (mdepth != 0)
+				++mdepth;
+			else if (hi.collection == 1 &&
+			         hi.usage == HID_USAGE2(HUP_GENERIC_DESKTOP, HUG_MOUSE))
+				++mdepth;
+			break;
+		case hid_endcollection:
+			if (mdepth)
+				--mdepth;
+			break;
+		case hid_input:
+			if (!mdepth)
+				break;
+			if (hi.usage == HID_USAGE2(HUP_GENERIC_DESKTOP, HUG_X) &&
+			    (hi.flags & (HIO_CONST|HIO_RELATIVE)) == HIO_RELATIVE)
+				++found;
+			if (hi.usage == HID_USAGE2(HUP_GENERIC_DESKTOP, HUG_Y) &&
+			    (hi.flags & (HIO_CONST|HIO_RELATIVE)) == HIO_RELATIVE)
+				++found;
+			break;
+		default:
+			break;
+		}
+	}
+	hid_end_parse(hd);
+	return found;
+}
+
+static char *
+sysctl_get_str(const char *sysctlname, size_t *size_ret)
+{
+	if (!sysctlname)
+		return NULL;
+
+	size_t len = 0;
+	if (sysctlbyname(sysctlname, NULL, &len, NULL, 0) || !len)
+		return NULL;
+
+	char* dest = malloc(len + 1);
+	if (!dest)
+		return NULL;
+
+	if (sysctlbyname(sysctlname, dest, &len, NULL, 0)) {
+		free(dest);
+		return NULL;
+	}
+	dest[len] = 0;
+	if (size_ret)
+		*size_ret = len;
+	return dest;
+}
+
+static char *
+devd_get_val(char *buf, size_t buf_size, const char *val_name, size_t val_name_size, size_t *val_size)
+{
+	if (!buf || !buf_size || !val_name || !val_name_size)
+		return NULL;
+
+	char *ret = buf, *buf_end = (buf + buf_size);
+	while (ret && ret < buf_end) {
+		ret = memmem(ret, (buf_end - ret), val_name, val_name_size);
+		if (!ret)
+			return NULL;
+		/* Found. */
+		/* Check: space before or buf+1. */
+		if ((buf + 1) < ret && ret[-1] != ' ') {
+			ret += val_name_size;
+			continue;
+		}
+		/* Check: = after name and size for value. */
+		ret += val_name_size;
+		if ((ret + 1) >= buf_end)
+			return NULL;
+		if (ret[0] != '=')
+			continue;
+		++ret;
+		break;
+	}
+	if (!ret || !val_size)
+		return ret;
+	/* Calc value data size. */
+	char* ptr = memchr(ret, ' ', (buf_end - ret));
+	if (!ptr) /* End of string/last value. */
+		ptr = buf_end;
+	*val_size = (ptr - ret);
+	return ret;
+}
+
+static void
+device_added(const char *dev_name, size_t dev_name_size, int allow_no_device)
+{
+	if (!dev_name || !dev_name_size || dev_name_size > PATH_MAX)
+		return;
+
+	char config_info[PATH_MAX + 32];
+	/* Make dev_name null ended string. */
+	snprintf(config_info, sizeof(config_info), DEVD_PATH_DEV"%.*s", (int)dev_name_size, dev_name);
+	/* Set / update pointers to dev_name and dev_path. */
+	char* dev_path = (config_info + DEVD_PATH_LEN); /* Skip: "devd:" */
+	dev_name = (dev_path + _PATH_DEV_LEN); /* Skip: "/dev/" */
+
+	/* Is known input device or path? */
+	hw_type_t *hwtype = get_dev_type_by_name(dev_name, dev_name_size);
+	if (!hwtype) {
+		hw_type_t hwtype_cust;
+		hwtype = get_dev_type_by_path(dev_name, dev_name_size, &hwtype_cust);
+	}
+	if (!hwtype) /* Not found in white list. */
+		return;
+
+	/* Skip legacy interfaces if EVDEV_SUPPORT is compiled into kernel */
+	if (evdev_support && hwtype->is_hybrid) {
+		LogMessage(X_INFO, "config/devd: EVDEV_SUPPORT is enabled, ignoring device %s\n", dev_name);
+		return;
+	}
+	/* Skip keyboard devices if kbdmux is enabled */
+	if (is_kbdmux && !allow_no_device && (hwtype->flags & ATTR_KEYBOARD)) {
+		LogMessage(X_INFO, "config/devd: kbdmux is enabled, ignoring device %s\n", dev_name);
+		return;
+	}
+	/* Skip duplicate devices. */
+	if (device_is_duplicate(config_info)) {
+		LogMessage(X_WARNING, "config/devd: device %s already added. ignoring\n", dev_path);
+		return;
+	}
+
+	/* Init and set attributes. */
+	char pnp_usb_id[PATH_MAX], product[PATH_MAX], vendor[PATH_MAX];
+	InputAttributes attrs;
+	memset(&attrs, 0, sizeof(attrs));
+	attrs.device = dev_path;
+	attrs.flags = hwtype->flags;
+
+	/* Try to open device. */
+	int fd = open(dev_path, O_RDONLY);
+	if (fd < 0) {
+		if (!(hwtype->flags & (ATTR_KEY | ATTR_KEYBOARD))) {
+			/*
+			 * Fail if cannot open device, it breaks AllowMouseOpenFail,
+			 * but it should not matter when config/devd is enabled
+			 */
+			LogMessage(X_WARNING, "config/devd: device %s already opened\n", dev_path);
+			return;
+		}
+		if (!allow_no_device) {
+			/*
+			 * There can be only one keyboard attached to console and
+			 * it is already added.
+			 */
+			LogMessage(X_WARNING, "config/devd: console keyboard is already added, ignoring %s\n", dev_path);
+			return;
+		}
+	} else {
+		/* Try to get device info via ioctl(). */
+		keyboard_info_t kbdi;
+		mousehw_t mshw;
+		struct input_id iid;
+		report_desc_t rep_desc;
+
+		if (ioctl(fd, KDGKBINFO, &kbdi) != -1) { /* Is this keyboard? */
+			memcpy(product, kbdi.kb_name, sizeof(kbdi.kb_name));
+			attrs.product = product;
+			attrs.flags = ATTR_KEY | ATTR_KEYBOARD;
+			LogMessage(X_INFO, "config/devd: detected keyboard: %s, kb_index=%i, kb_unit=%i, kb_type=%i, kb_config=%i\n",
+			           kbdi.kb_name, kbdi.kb_index, kbdi.kb_unit, kbdi.kb_type, kbdi.kb_config);
+		} else if (ioctl(fd, MOUSE_GETHWINFO, &mshw) != -1) { /* Is this mouse? */
+			/* FreeBSD mouse drivers does not return real vid+pid. */
+			/* construct USB ID in lowercase hex - "0000:ffff" */
+			if (mshw.iftype != MOUSE_IF_USB && mshw.model > 0) {
+				snprintf(pnp_usb_id, sizeof(pnp_usb_id), "%04x:%04x", mshw.hwid, mshw.model);
+				attrs.usb_id = pnp_usb_id;
+			}
+			if (mshw.type == MOUSE_PAD)
+				attrs.flags = ATTR_TOUCHPAD;
+			else
+				attrs.flags = ATTR_POINTER;
+			LogMessage(X_INFO, "config/devd: detected mouse: hwid=%04x, model=%04x, type=%04x, iftype=%04x, buttons=%d\n",
+			           mshw.hwid, mshw.model, mshw.type, mshw.iftype, mshw.buttons);
+		} else if (ioctl(fd, JSIOCGNAME((sizeof(product) - 1)), product) != -1) { /* Is this joystick? */
+			attrs.product = product;
+			attrs.flags = ATTR_JOYSTICK;
+			LogMessage(X_INFO, "config/devd: detected joystick: %s\n", product);
+		} else if (ioctl(fd, EVIOCGID, &iid) != -1 &&
+		           ioctl(fd, EVIOCGNAME((sizeof(product) - 1)), product) != -1) { /* Is this event? */
+			/* construct USB ID in lowercase hex - "0000:ffff" */
+			snprintf(pnp_usb_id, sizeof(pnp_usb_id), "%04x:%04x", iid.vendor, iid.product);
+			attrs.usb_id = pnp_usb_id;
+			attrs.product = product;
+			/* Detect device type. */
+			attrs.flags = get_evdev_flags(fd);
+			/* Skip keyboard devices if kbdmux is enabled and EVDEV_SUPPORT is not compiled into kernel*/
+			if (is_kbdmux && !evdev_support && (attrs.flags & ATTR_KEYBOARD)) {
+				close(fd);
+				LogMessage(X_INFO, "config/devd: kbdmux is enabled, ignoring device %s\n", dev_name);
+				return;
+			}
+			LogMessage(X_INFO, "config/devd: detected event input: %s, bustype=%04x, vendor=%04x, product=%04x, version=%04x\n",
+			           product, iid.bustype, iid.vendor, iid.product, iid.version);
+		} else if ((rep_desc = hid_get_report_desc(fd))) { /* Is USB HID? */
+			if (hid_is_mouse(rep_desc)) {
+				attrs.flags = ATTR_POINTER;
+				LogMessage(X_INFO, "config/devd: detected USB HID mouse\n");
+			} else if (hid_is_collection(rep_desc, HID_USAGE2(HUP_GENERIC_DESKTOP, HUG_KEYBOARD))) {
+				/* Skip keyboard devices if kbdmux is enabled */
+				if (is_kbdmux) {
+					hid_dispose_report_desc(rep_desc);
+					close(fd);
+					LogMessage(X_INFO, "config/devd: kbdmux is enabled, ignoring device %s\n", dev_name);
+					return;
+				}
+				attrs.flags = ATTR_KEY | ATTR_KEYBOARD;
+				LogMessage(X_INFO, "config/devd: detected USB HID keyboard\n");
+			} else if (hid_is_collection(rep_desc, HID_USAGE2(HUP_GENERIC_DESKTOP, HUG_JOYSTICK)) ||
+			           hid_is_collection(rep_desc, HID_USAGE2(HUP_GENERIC_DESKTOP, HUG_GAME_PAD))) {
+				attrs.flags = ATTR_JOYSTICK;
+				LogMessage(X_INFO, "config/devd: detected USB HID joystick\n");
+			} else
+				LogMessage(X_INFO, "config/devd: detected USB HID of unknown type\n");
+			hid_dispose_report_desc(rep_desc);
+		}
+
+		if (!attrs.usb_id) { /* Is this webcamd device? */
+			unsigned short vid, pid;
+			if (ioctl(fd, WEBCAMD_IOCTL_GET_USB_VENDOR_ID, &vid) != -1 &&
+			    ioctl(fd, WEBCAMD_IOCTL_GET_USB_PRODUCT_ID, &pid) != -1) {
+				snprintf(pnp_usb_id, sizeof(pnp_usb_id), "%04x:%04x", vid, pid);
+				attrs.usb_id = pnp_usb_id;
+				LogMessage(X_INFO, "config/devd: webcamd device: %s\n", pnp_usb_id);
+			}
+		}
+	}
+	close(fd);
+
+	/* Try to get device info via sysctl(). */
+	if (!attrs.usb_id && !attrs.pnp_id) {
+		char sysctlname[PATH_MAX];
+		snprintf(sysctlname, sizeof(sysctlname), "dev.%.*s.%s.%%pnpinfo",
+		         (int)hwtype->dev_name_size,
+		         (hwtype->dev_name + hwtype->path_offset),
+		         (dev_name + hwtype->path_offset + hwtype->dev_name_size));
+		size_t sdata_size;
+		char* sdata = sysctl_get_str(sysctlname, &sdata_size);
+		if (sdata) {
+			size_t pid_size, vid_size;
+			char* ptr_vid = devd_get_val_cstr("vendor", sdata, sdata_size, &vid_size);
+			char* ptr_pid = devd_get_val_cstr("product", sdata, sdata_size, &pid_size);
+			if (ptr_vid && ptr_pid) { /* usb_id */
+				ptr_vid[vid_size] = 0;
+				ptr_pid[pid_size] = 0;
+				snprintf(pnp_usb_id, sizeof(pnp_usb_id), "%s:%s", ptr_vid, ptr_pid);
+				attrs.usb_id = pnp_usb_id;
+				LogMessage(X_INFO, "config/devd: [sysctl] usb_id: %s\n", pnp_usb_id);
+			} else { /* pnp_id */
+				strlcpy(pnp_usb_id, sdata, sizeof(pnp_usb_id));
+				attrs.pnp_id = pnp_usb_id;
+			}
+			free(sdata);
+		}
+	}
+	if (!attrs.vendor || !attrs.product) {
+		char sysctlname[PATH_MAX];
+		snprintf(sysctlname, sizeof(sysctlname), "dev.%.*s.%s.%%desc",
+		         (int)hwtype->dev_name_size,
+		         (hwtype->dev_name + hwtype->path_offset),
+		         (dev_name + hwtype->path_offset + hwtype->dev_name_size));
+		size_t sdata_size;
+		char* sdata = sysctl_get_str(sysctlname, &sdata_size);
+		if (sdata) {
+			/* Vendor. */
+			char* ptr_pid = memchr(sdata, ' ', sdata_size);
+			if (ptr_pid)
+				ptr_pid[0] = 0;
+			strlcpy(vendor, sdata, sizeof(vendor));
+			attrs.vendor = vendor;
+			/* Product. */
+			if (!attrs.product && ptr_pid) {
+				++ptr_pid;
+				char* ptr_vid = memchr(ptr_pid, ',', (sdata_size - (ptr_pid - sdata)));
+				if (ptr_vid)
+					ptr_vid[0] = 0;
+				strlcpy(product, ptr_pid, sizeof(product));
+				attrs.product = product;
+			} else
+				product[0] = 0;
+			free(sdata);
+			LogMessage(X_INFO, "config/devd: [sysctl] vendor: %s, product: %s\n", vendor, product);
+		}
+	}
+
+	/* Init options. */
+	InputOption *option = NULL, *options = NULL;
+	if ((option = input_option_new(options, "_source", "server/devd")))
+		options = option;
+	if (option && (option = input_option_new(options, "config_info", config_info)))
+		options = option;
+	if (option && (option = input_option_new(options, "name", (attrs.product ? attrs.product : dev_name))))
+		options = option;
+	if (option && hwtype->xdriver && (option = input_option_new(options, "driver", hwtype->xdriver)))
+		options = option;
+	/*
+	 * Don't pass "device" option if the keyboard is already attached to the console (ie. open() failed)
+	 * This would activate a special logic in xf86-input-keyboard. Prevent any other attached to console
+	 * keyboards being processed. There can be only one such device.
+	 */
+	if (option && fd >= 0 && (option = input_option_new(options, "device", dev_path)))
+		options = option;
+	/* Most drivers just use "device" but evdev also uses "path" so populate both */
+	if (option && (option = input_option_new(options, "path", dev_path)))
+		options = option;
+	if (option) {
+		LogMessage(X_INFO, "config/devd: adding input device %s\n", dev_path);
+		DeviceIntPtr dev_iptr = NULL;
+		int rc;
+		if ((rc = NewInputDeviceRequest(options, &attrs, &dev_iptr)) != Success)
+			LogMessage(X_ERROR, "config/devd: error %d adding device %s\n", rc, dev_path);
+	} else
+		LogMessage(X_ERROR, "config/devd: error adding device %s\n", dev_path);
+	if (options)
+		input_option_free_list(&options);
+	return;
+}
+
+static void
+device_removed(const char *dev_name, size_t dev_name_size)
+{
+
+	if (!dev_name || !dev_name_size || dev_name_size > PATH_MAX)
+		return;
+
+	hw_type_t hwtype_cust;
+	if (!get_dev_type_by_name(dev_name, dev_name_size) &&
+	    !get_dev_type_by_path(dev_name, dev_name_size, &hwtype_cust))
+		return;	/* Device not in list - unknown. */
+
+	char config_info[PATH_MAX + 32];
+	snprintf(config_info, sizeof(config_info), DEVD_PATH_DEV"%.*s", (int)dev_name_size, dev_name);
+	if (device_is_duplicate(config_info))
+		LogMessage(X_INFO, "config/devd: removing input device %s\n", (config_info + DEVD_PATH_LEN));
+	else
+		LogMessage(X_INFO, "config/devd: removing nonexistent device %s\n", (config_info + DEVD_PATH_LEN));
+	remove_devices("devd", config_info);
+	return;
+}
+
+static void socket_handler(int fd, int ready, void *data);
+
+static int
+connect_devd(void)
+{
+	int sock = socket(AF_UNIX, SOCK_STREAM, 0);
+	if (sock < 0) {
+		LogMessage(X_ERROR, "config/devd: failed opening stream socket: %s\n", strerror(errno));
+		return -1;
+	}
+
+	struct sockaddr_un devd;
+	devd.sun_family = AF_UNIX;
+	memcpy(devd.sun_path, DEVD_SOCK_PATH, sizeof(DEVD_SOCK_PATH));
+	if (connect(sock, (struct sockaddr*)&devd, sizeof(devd)) < 0) {
+		int error = errno;
+		close(sock);
+		LogMessage(X_ERROR, "config/devd: failed to connect to devd: %s)\n", strerror(error));
+		return -1;
+	}
+
+	SetNotifyFd(sock, socket_handler, X_NOTIFY_READ, NULL);
+	return sock;
+}
+
+static void
+disconnect_devd(int sock)
+{
+	if (sock < 0)
+		return;
+	RemoveNotifyFd(sock);
+	close(sock);
+	return;
+}
+
+static CARD32
+reconnect_handler(OsTimerPtr timer, CARD32 time, void *arg)
+{
+	devd_buf_used = 0;
+	devd_skt = connect_devd();
+	if (devd_skt < 0) /* Try again after RECONNECT_DELAY */
+		return RECONNECT_DELAY;
+	TimerFree(rtimer);
+	rtimer = NULL;
+	LogMessage(X_INFO, "config/devd: reopened devd socket\n");
+	return 0;
+}
+
+static void
+socket_handler(int fd, int ready, void *data)
+{
+	/* Read new data. */
+	while (1) {
+		ssize_t ios = recv(devd_skt, (devd_buf + devd_buf_used), (sizeof(devd_buf) - devd_buf_used), MSG_DONTWAIT);
+		if (ios > 0) { /* Read OK. */
+			devd_buf_used += ios;
+			continue; /* Try to read more. */
+		}
+		/* Something wrong. */
+		int error = errno;
+		if (error == EAGAIN)
+			break; /* All available data read. */
+		if (error == EINTR)
+			continue;
+		if (devd_buf_used >= sizeof(devd_buf)) {
+			devd_buf_used = 0; /* Message too long, reset buf. */
+			continue;
+		}
+		/* devd socket is lost */
+		disconnect_devd(devd_skt);
+		rtimer = TimerSet(NULL, 0, 1, reconnect_handler, NULL);
+		LogMessage(X_WARNING, "config/devd: devd socket read error: %s\n", strerror(error));
+		return;
+	}
+
+	/* Process data. */
+	char *ptr, *line = (devd_buf + 1);
+	size_t line_size = 0;
+	while((ptr = memchr(line, '\n', (devd_buf_used - line_size)))) {
+		line_size = (ptr - line);
+		do {
+			if (*(line - 1) != DEVD_EVENT_NOTIFY)
+				break; /* Handle only notify. */
+			/* Check: is system=DEVFS. */
+			size_t val_size;
+			char* val = devd_get_val_cstr("system", line, line_size, &val_size);
+			if (!is_meuqual_cstr("DEVFS", val, val_size))
+				break;
+			/* Check: is subsystem=CDEV. */
+			val = devd_get_val_cstr("subsystem", line, line_size, &val_size);
+			if (!is_meuqual_cstr("CDEV", val, val_size))
+				break;
+			/* Get device name. */
+			size_t cdev_size;
+			char* cdev = devd_get_val_cstr("cdev", line, line_size, &cdev_size);
+			if (!cdev)
+				break;
+			/* Get event type. */
+			val = devd_get_val_cstr("type", line, line_size, &val_size);
+			if (is_meuqual_cstr("CREATE", val, val_size)) {
+				device_added(cdev, cdev_size, 0);
+			} else if (is_meuqual_cstr("DESTROY", val, val_size)) {
+				device_removed(cdev, cdev_size);
+			}
+		} while(0);
+
+		line += (line_size + 2); /* Skip '\n' and event type byte. */
+		line_size = (line - devd_buf);
+		if (devd_buf_used <= line_size) {
+			devd_buf_used = 0;
+			return;
+		}
+	}
+	/* Save line without end marker. */
+	if (line_size) {
+		devd_buf_used -= (line_size - 1);
+		memmove(devd_buf, (line - 1), devd_buf_used);
+	}
+	return;
+}
+
+int
+config_devd_init(void)
+{
+	LogMessage(X_INFO, "config/devd: probing input devices...\n");
+
+	/* Check if kernel is compiled with evdev support in hybrid drivers */
+	evdev_support = feature_present("evdev_support");
+
+	/*
+	 * Add fake keyboard and give up on keyboards management
+	 * if kbdmux is enabled and not exported through evdev
+	 */
+	is_kbdmux = is_kbdmux_enabled();
+	if (is_kbdmux && !evdev_support)
+		device_added("kbdmux0", 7, 1);
+
+	/* Scan /dev/ for devices. */
+	struct dirent** namelist;
+	size_t dir_cnt = scandir(_PATH_DEV, &namelist, 0, alphasort);
+	for (size_t i = 0; i < dir_cnt; ++i) {
+		struct dirent* de = namelist[i];
+		if (is_de_euqual_cstr(de, ".") ||
+		    is_de_euqual_cstr(de, "..")) {
+			free(de);
+			continue;
+		}
+		if (de->d_type != DT_DIR) {
+			device_added(de->d_name, de->d_namlen, 0);
+		} else { /* Sub folder. */
+			char devicename[PATH_MAX];
+			snprintf(devicename, sizeof(devicename), _PATH_DEV "%s", de->d_name);
+			struct dirent** snamelist;
+			size_t sdir_cnt = scandir(devicename, &snamelist, 0, alphasort);
+			for (size_t j = 0; j < sdir_cnt; ++j) {
+				struct dirent* sde = snamelist[j];
+				if (!is_de_euqual_cstr(sde, ".") &&
+				    !is_de_euqual_cstr(sde, "..") &&
+				    sde->d_type != DT_DIR) {
+					size_t tm = snprintf(devicename, sizeof(devicename), "%s/%s", de->d_name, sde->d_name);
+					device_added(devicename, tm, 0);
+				}
+				free(sde);
+			}
+			free(snamelist);
+		}
+		free(de);
+	}
+	free(namelist);
+
+	devd_buf_used = 0;
+	devd_skt = connect_devd();
+	return (devd_skt < 0) ? 0 : 1;
+}
+
+void
+config_devd_fini(void)
+{
+	LogMessage(X_INFO, "config/devd: terminating backend...\n");
+
+	if (rtimer) {
+		TimerFree(rtimer);
+		rtimer = NULL;
+	}
+
+	disconnect_devd(devd_skt);
+	return;
+}
