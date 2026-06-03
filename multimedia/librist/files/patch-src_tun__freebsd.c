-- Add FreeBSD TUN interface support (tun_freebsd.c).
-- The upstream source ships tun_linux.c and tun_darwin.c but has no
-- FreeBSD implementation, causing undefined symbol errors at link time.
-- This file implements the same rist_tun_* API using FreeBSD's /dev/tun
-- cloning device and BSD socket ioctls (SIOCAIFADDR, SIOCSIFMTU, etc.).

--- src/tun_freebsd.c.orig	2026-05-10 02:43:09 UTC
+++ src/tun_freebsd.c
@@ -0,0 +1,167 @@
+/* librist. Copyright © 2026 SipRadius LLC. All right reserved.
+ * Author: Sergio Ammirata, Ph.D. <sergio@ammirata.net>
+ *
+ * SPDX-License-Identifier: BSD-2-Clause
+ */
+
+#ifdef __FreeBSD__
+
+#include "librist/tun.h"
+
+#include <errno.h>
+#include <fcntl.h>
+#include <stdio.h>
+#include <string.h>
+#include <unistd.h>
+#include <sys/ioctl.h>
+#include <sys/socket.h>
+#include <net/if.h>
+#include <net/if_tun.h>
+#include <netinet/in.h>
+#include <arpa/inet.h>
+
+int rist_tun_open(const char *requested_name, char *actual_name, size_t name_len)
+{
+	char path[64];
+	int fd;
+
+	if (requested_name && requested_name[0])
+		snprintf(path, sizeof(path), "/dev/%s", requested_name);
+	else
+		snprintf(path, sizeof(path), "/dev/tun");
+
+	fd = open(path, O_RDWR);
+	if (fd < 0) {
+		perror("open tun");
+		return -1;
+	}
+
+	if (actual_name && name_len > 0) {
+		struct ifreq ifr;
+		memset(&ifr, 0, sizeof(ifr));
+		if (ioctl(fd, TUNGIFNAME, &ifr) < 0) {
+			perror("ioctl TUNGIFNAME");
+			close(fd);
+			return -1;
+		}
+		strncpy(actual_name, ifr.ifr_name, name_len - 1);
+		actual_name[name_len - 1] = '\0';
+	}
+
+	return fd;
+}
+
+void rist_tun_close(int fd)
+{
+	if (fd >= 0)
+		close(fd);
+}
+
+int rist_tun_read(int fd, uint8_t *buf, size_t len)
+{
+	return (int)read(fd, buf, len);
+}
+
+int rist_tun_write(int fd, const uint8_t *buf, size_t len)
+{
+	return (int)write(fd, buf, len);
+}
+
+static int tun_ioctl_socket(void)
+{
+	int s = socket(AF_INET, SOCK_DGRAM, 0);
+	if (s < 0)
+		perror("socket AF_INET");
+	return s;
+}
+
+int rist_tun_set_ip(const char *dev, const char *ip, int prefix_len)
+{
+	int s = tun_ioctl_socket();
+	if (s < 0)
+		return -1;
+
+	struct ifaliasreq ifra;
+	memset(&ifra, 0, sizeof(ifra));
+	strncpy(ifra.ifra_name, dev, IFNAMSIZ - 1);
+
+	struct sockaddr_in *addr = (struct sockaddr_in *)&ifra.ifra_addr;
+	addr->sin_len    = sizeof(*addr);
+	addr->sin_family = AF_INET;
+	if (inet_pton(AF_INET, ip, &addr->sin_addr) != 1) {
+		fprintf(stderr, "Invalid IP address: %s\n", ip);
+		close(s);
+		return -1;
+	}
+
+	struct sockaddr_in *mask = (struct sockaddr_in *)&ifra.ifra_mask;
+	mask->sin_len    = sizeof(*mask);
+	mask->sin_family = AF_INET;
+	mask->sin_addr.s_addr = prefix_len ?
+		htonl(~((1U << (32 - prefix_len)) - 1)) : 0;
+
+	struct sockaddr_in *dst = (struct sockaddr_in *)&ifra.ifra_broadaddr;
+	dst->sin_len    = sizeof(*dst);
+	dst->sin_family = AF_INET;
+	dst->sin_addr   = addr->sin_addr;
+
+	if (ioctl(s, SIOCAIFADDR, &ifra) < 0) {
+		perror("ioctl SIOCAIFADDR");
+		close(s);
+		return -1;
+	}
+
+	close(s);
+	return 0;
+}
+
+int rist_tun_set_mtu(const char *dev, int mtu)
+{
+	int s = tun_ioctl_socket();
+	if (s < 0)
+		return -1;
+
+	struct ifreq ifr;
+	memset(&ifr, 0, sizeof(ifr));
+	strncpy(ifr.ifr_name, dev, IFNAMSIZ - 1);
+	ifr.ifr_mtu = mtu;
+
+	if (ioctl(s, SIOCSIFMTU, &ifr) < 0) {
+		perror("ioctl SIOCSIFMTU");
+		close(s);
+		return -1;
+	}
+
+	close(s);
+	return 0;
+}
+
+int rist_tun_bring_up(const char *dev)
+{
+	int s = tun_ioctl_socket();
+	if (s < 0)
+		return -1;
+
+	struct ifreq ifr;
+	memset(&ifr, 0, sizeof(ifr));
+	strncpy(ifr.ifr_name, dev, IFNAMSIZ - 1);
+
+	if (ioctl(s, SIOCGIFFLAGS, &ifr) < 0) {
+		perror("ioctl SIOCGIFFLAGS");
+		close(s);
+		return -1;
+	}
+
+	ifr.ifr_flags |= IFF_UP | IFF_RUNNING;
+
+	if (ioctl(s, SIOCSIFFLAGS, &ifr) < 0) {
+		perror("ioctl SIOCSIFFLAGS");
+		close(s);
+		return -1;
+	}
+
+	close(s);
+	return 0;
+}
+
+#endif /* __FreeBSD__ */
