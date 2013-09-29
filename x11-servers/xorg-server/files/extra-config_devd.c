--- /dev/null	2013-08-03 00:44:23.000000000 +0200
+++ config/devd.c	2013-08-03 00:45:15.162836806 +0200
@@ -0,0 +1,478 @@
+/*
+ * Copyright © 2012 Baptiste Daroussin
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
+#include <sys/socket.h>
+#include <sys/sysctl.h>
+#include <sys/un.h>
+
+#include <ctype.h>
+#include <stdlib.h>
+#include <stdio.h>
+#include <stdarg.h>
+#include <stdbool.h>
+#include <unistd.h>
+
+#include "input.h"
+#include "inputstr.h"
+#include "hotplug.h"
+#include "config-backends.h"
+#include "os.h"
+
+#define DEVD_SOCK_PATH "/var/run/devd.pipe"
+
+#define DEVD_EVENT_ADD		'+'
+#define DEVD_EVENT_REMOVE	'-'
+
+static int sock_devd = -1;
+
+#if XORG_VERSION_CURRENT < 10800000
+enum {
+	ATTR_KEYBOARD,
+	ATTR_POINTER,
+	ATTR_JOYSTICK,
+	ATTR_TOUCHPAD,
+	ATTR_TOUCHSCREEN,
+};
+#endif
+
+struct hw_type {
+	const char *driver;
+	int flag;
+	const char *xdriver;
+};
+
+static struct hw_type hw_types[] = {
+	{ "ukbd", ATTR_KEYBOARD, "kdb" },
+	{ "atkbd", ATTR_KEYBOARD, "kdb" },
+	{ "ums", ATTR_POINTER, "mouse" },
+	{ "psm", ATTR_POINTER, "mouse" },
+	{ "uhid", ATTR_POINTER, "mouse" },
+	{ "joy", ATTR_JOYSTICK, NULL },
+	{ "atp", ATTR_TOUCHPAD, NULL },
+	{ "uep", ATTR_TOUCHSCREEN, NULL },
+	{ NULL, -1, NULL },
+};
+
+#if XORG_VERSION_CURRENT < 10800000
+static void
+add_option(InputOption **options, const char *key, const char *value)
+{
+    if (!value || *value == '\0')
+        return;
+
+    for (; *options; options = &(*options)->next)
+        ;
+    *options = calloc(sizeof(**options), 1);
+    if (!*options) /* Yeesh. */
+        return;
+    (*options)->key = xstrdup(key);
+    (*options)->value = xstrdup(value);
+    (*options)->next = NULL;
+}
+
+static void
+remove_device(DeviceIntPtr dev)
+{
+    /* this only gets called for devices that have already been added */
+    LogMessage(X_INFO, "config/devd: removing device %s\n", dev->name);
+
+    /* Call PIE here so we don't try to dereference a device that's
+     * already been removed. */
+    OsBlockSignals();
+    ProcessInputEvents();
+    DeleteInputDeviceRequest(dev);
+    OsReleaseSignals();
+}
+
+static bool
+device_is_duplicate(char *config_info)
+{
+    DeviceIntPtr dev;
+
+    for (dev = inputInfo.devices; dev; dev = dev->next)
+        if (dev->config_info && (strcmp(dev->config_info, config_info) == 0))
+            return true;
+
+    for (dev = inputInfo.off_devices; dev; dev = dev->next)
+        if (dev->config_info && (strcmp(dev->config_info, config_info) == 0))
+            return true;
+
+    return false;
+}
+
+#endif
+
+static bool
+sysctl_exists(const char *format, ...)
+{
+	va_list args;
+	char *name = NULL;
+	size_t len;
+	int ret;
+
+	if (format == NULL)
+		return false;
+
+	va_start(args, format);
+	vasprintf(&name, format, args);
+	va_end(args);
+
+	ret = sysctlbyname(name, NULL, &len, NULL, 0);
+
+	if (ret == -1)
+		len = 0;
+
+	free(name);
+	return (len > 0);
+}
+
+static char *
+sysctl_get_str(const char *format, ...)
+{
+	va_list args;
+	char *name = NULL;
+	char *dest = NULL;
+	size_t len;
+
+	if (format == NULL)
+		return NULL;
+
+	va_start(args, format);
+	vasprintf(&name, format, args);
+	va_end(args);
+
+	if (sysctlbyname(name, NULL, &len, NULL, 0) == 0) {
+		dest = malloc(len + 1);
+		if (sysctlbyname(name, dest, &len, NULL, 0) == 0)
+			dest[len] = '\0';
+		else {
+			free(dest);
+			dest = NULL;
+		}
+	}
+
+	free(name);
+	return dest;
+}
+
+static void
+device_added(char *line)
+{
+    char *walk;
+    char *path;
+    char *vendor;
+    char *product = NULL;
+    char *config_info = NULL;
+    InputOption *options = NULL;
+#if XORG_VERSION_CURRENT > 10800000
+    InputAttributes attrs = {};
+#else
+    InputOption *tmpo;
+#endif
+    DeviceIntPtr dev = NULL;
+    int i, rc;
+
+    walk = strchr(line, ' ');
+    if (walk != NULL)
+        walk[0] = '\0';
+
+    for (i = 0; hw_types[i].driver != NULL; i++) {
+        if (strncmp(line, hw_types[i].driver,
+                    strlen(hw_types[i].driver)) == 0 &&
+            isnumber(*(line + strlen(hw_types[i].driver)))) {
+#if XORG_VERSION_CURRENT > 10800000
+            attrs.flags |= hw_types[i].flag;
+#endif
+            break;
+        }
+    }
+    if (hw_types[i].driver == NULL) {
+        LogMessageVerb(X_INFO, 10, "config/devd: ignoring device %s\n", line);
+        return;
+    }
+
+#if XORG_VERSION_CURRENT < 10800000
+    if (hw_types[i].xdriver == NULL) {
+        LogMessageVerb(X_INFO, 10, "config/devd: ignoring device %s\n", line);
+        return;
+    }
+#endif
+    if (asprintf(&path, "/dev/%s", line) == -1)
+        return;
+
+#if XORG_VERSION_CURRENT < 10800000
+    options = calloc(sizeof(*options), 1);
+    if (!options)
+        return;
+
+    add_option(&options, "_source", "server/devd");
+#else
+    options =  input_option_new(NULL, "_source", "server/devd");
+    if (!options)
+        return;
+#endif
+
+    vendor = sysctl_get_str("dev.%s.%s.%%desc", hw_types[i].driver, line + strlen(hw_types[i].driver));
+    if (vendor == NULL) {
+#if XORG_VERSION_CURRENT > 10800000
+        attrs.vendor = strdup("(unnamed)");
+#endif
+    } else {
+        if ((product = strchr(vendor, ' ')) != NULL) {
+            product[0] = '\0';
+            product++;
+        }
+#if XORG_VERSION_CURRENT > 10800000
+        attrs.vendor = strdup(vendor);
+#endif
+        if (product != NULL && (walk = strchr(product, ',')) != NULL)
+            walk[0] = '\0';
+#if XORG_VERSION_CURRENT > 10800000
+        attrs.product = strdup(product != NULL ? product : "(unnamed)");
+	options = input_option_new(options, "name", product != NULL ? product : "(unnamed)");
+#else
+        add_option(&options, "name", product != NULL ? product : "(unnamed)");
+#endif
+    }
+#if XORG_VERSION_CURRENT > 10800000
+    attrs.usb_id = NULL;
+    options = input_option_new(options, "path", path);
+    options = input_option_new(options, "device", path);
+#else
+    add_option(&options, "path", path);
+    add_option(&options, "device", path);
+#endif
+
+#if XORG_VERSION_CURRENT < 10800000
+    add_option(&options, "driver", hw_types[i].xdriver);
+#endif
+
+    if (asprintf(&config_info, "devd:%s", line) == -1) {
+        config_info = NULL;
+        goto unwind;
+    }
+
+    if (device_is_duplicate(config_info)) {
+        LogMessage(X_WARNING, "config/devd: device %s already added. "
+                              "Ignoring.\n", product != NULL ? product : "(unnamed)");
+        goto unwind;
+    }
+
+#if XORG_VERSION_CURRENT < 10800000
+    add_option(&options, "config_info", config_info);
+#else
+    options = input_option_new(options, "config_info", config_info);
+#endif
+    LogMessage(X_INFO, "config/devd: Adding input device %s (%s)\n",
+               product != NULL ? product : "(unnamed)", path);
+
+#if XORG_VERSION_CURRENT > 10800000
+    rc = NewInputDeviceRequest(options, &attrs, &dev);
+#else
+    rc = NewInputDeviceRequest(options, &dev);
+#endif
+
+    if (rc != Success)
+        goto unwind;
+
+ unwind:
+    free(config_info);
+#if XORG_VERSION_CURRENT < 10800000
+    while ((tmpo = options)) {
+        options = tmpo->next;
+        free(tmpo->key);        /* NULL if dev != NULL */
+        free(tmpo->value);      /* NULL if dev != NULL */
+        free(tmpo);
+    }
+#else
+    input_option_free_list(&options);
+#endif
+
+#if XORG_VERSION_CURRENT > 10800000
+    free(attrs.usb_id);
+    free(attrs.product);
+    free(attrs.device);
+    free(attrs.vendor);
+#endif
+
+    return;
+}
+
+static void
+device_removed(char *line)
+{
+    char *walk;
+    char *value;
+#if XORG_VERSION_CURRENT < 10800000
+    DeviceIntPtr dev, next;
+#endif
+
+    walk = strchr(line, ' ');
+    if (walk != NULL)
+        walk[0] = '\0';
+
+    if (asprintf(&value, "devd:%s", line) == -1)
+        return;
+
+#if XORG_VERSION_CURRENT > 10800000
+    remove_devices("dev", value);
+#else
+    for (dev = inputInfo.devices; dev; dev = next) {
+        next = dev->next;
+        if (dev->config_info && strcmp(dev->config_info, value) == 0)
+            remove_device(dev);
+    }
+    for (dev = inputInfo.off_devices; dev; dev = next) {
+	next = dev->next;
+        if (dev->config_info && strcmp(dev->config_info, value) == 0)
+            remove_device(dev);
+    }
+#endif
+
+    free(value);
+}
+
+static ssize_t
+socket_getline(int fd, char **out)
+{
+	char *buf;
+	ssize_t ret, cap, sz = 0;
+	char c;
+
+	cap = 1024;
+	buf = malloc(cap * sizeof(char));
+	if (!buf)
+		return -1;
+
+	for (;;) {
+		ret = read(sock_devd, &c, 1);
+		if (ret < 1) {
+			free(buf);
+			return -1;
+		}
+
+		if (c == '\n')
+			break;
+
+		if (sz + 1 >= cap) {
+			cap *= 2;
+			buf = realloc(buf, cap *sizeof(char));
+		}
+		buf[sz] = c;
+		sz++;
+	}
+
+	buf[sz] = '\0';
+	if (sz > 0)
+		*out = buf;
+	else
+		free(buf);
+
+	return sz; /* number of bytes in the line, not counting the line break*/
+}
+
+static void
+wakeup_handler(pointer data, int err, pointer read_mask)
+{
+    char *line = NULL;
+
+    if (err < 0)
+        return;
+
+    if (FD_ISSET(sock_devd, (fd_set *)read_mask)) {
+        if (socket_getline(sock_devd, &line) < 0)
+            return;
+
+        switch(*line) {
+		case DEVD_EVENT_ADD:
+			device_added(line++);
+			break;
+		case DEVD_EVENT_REMOVE:
+			device_removed(line++);
+			break;
+		default:
+			break;
+	}
+	free(line);
+    }
+}
+
+static void
+block_handler(pointer data, struct timeval **tv, pointer read_mask)
+{
+}
+
+int
+config_devd_init(void)
+{
+    struct sockaddr_un devd;
+    char devicename[1024];
+    int i, j;
+
+    /* first scan the sysctl to determine the hardware if needed */
+
+    for (i = 0; hw_types[i].driver != NULL; i++) {
+        for (j = 0; sysctl_exists("dev.%s.%i.%%desc", hw_types[i].driver, j); j++) {
+            snprintf(devicename, 1024, "%s%i", hw_types[i].driver, j);
+            device_added(devicename);
+        }
+
+    }
+    sock_devd = socket(AF_UNIX, SOCK_STREAM, 0);
+    if (sock_devd < 0) {
+        ErrorF("config/devd: Fail opening stream socket");
+        return 0;
+    }
+
+    devd.sun_family = AF_UNIX;
+    strlcpy(devd.sun_path, DEVD_SOCK_PATH, sizeof(devd.sun_path));
+
+    if (connect(sock_devd, (struct sockaddr *) &devd, sizeof(struct sockaddr_un)) < 0) {
+        close(sock_devd);
+        ErrorF("config/devd: Fail to connect to devd");
+        return 0;
+    }
+
+    RegisterBlockAndWakeupHandlers(block_handler, wakeup_handler, NULL);
+    AddGeneralSocket(sock_devd);
+
+    return 1;
+}
+
+void
+config_devd_fini(void)
+{
+    if (sock_devd < 0)
+        return;
+
+    RemoveGeneralSocket(sock_devd);
+    RemoveBlockAndWakeupHandlers(block_handler, wakeup_handler, NULL);
+    close(sock_devd);
+}
