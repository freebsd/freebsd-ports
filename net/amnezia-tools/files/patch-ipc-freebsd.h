--- ipc-freebsd.h.orig	2026-08-12 22:24:49 UTC
+++ ipc-freebsd.h
@@ -11,17 +11,52 @@
 
 #define IPC_SUPPORTS_KERNEL_INTERFACE
 
+#define WG_FREEBSD_MAX_AWG_STRING_LEN 4097
+
 static int get_dgram_socket(void)
 {
 	static int sock = -1;
 	if (sock < 0)
-		sock = socket(AF_INET, SOCK_DGRAM, 0);
+		sock = socket(AF_LOCAL, SOCK_DGRAM, 0);
 	return sock;
 }
 
+static uint32_t kernel_get_awg_version(const char *ifname)
+{
+	struct wg_data_io wgd = { 0 };
+	nvlist_t *nvl = NULL;
+	int s = get_dgram_socket();
+	int saved_errno;
+	uint32_t version = WG_AWG_VERSION_2;
+
+	if (s < 0)
+		return version;
+	strlcpy(wgd.wgd_name, ifname, sizeof(wgd.wgd_name));
+	saved_errno = errno;
+	if (ioctl(s, SIOCGWG, &wgd) < 0 || !wgd.wgd_size)
+		goto out;
+	wgd.wgd_data = malloc(wgd.wgd_size);
+	if (!wgd.wgd_data)
+		goto out;
+	if (ioctl(s, SIOCGWG, &wgd) < 0)
+		goto out;
+	nvl = nvlist_unpack(wgd.wgd_data, wgd.wgd_size, 0);
+	if (nvl && nvlist_exists_number(nvl, "awg-version")) {
+		uint64_t number = nvlist_get_number(nvl, "awg-version");
+		if (number > 0 && number <= UINT32_MAX)
+			version = number;
+	}
+out:
+	if (nvl)
+		nvlist_destroy(nvl);
+	free(wgd.wgd_data);
+	errno = saved_errno;
+	return version;
+}
+
 static int kernel_get_wireguard_interfaces(struct string_list *list)
 {
-	struct ifgroupreq ifgr = { .ifgr_name = "wg" };
+	struct ifgroupreq ifgr = { .ifgr_name = "amn" };
 	struct ifg_req *ifg;
 	int s = get_dgram_socket(), ret = 0;
 
@@ -60,6 +95,7 @@ static int kernel_get_device(struct wgdevice **device,
 	uint64_t number;
 	const void *binary;
 	int ret = 0, s;
+	uint32_t version = WG_AWG_VERSION_2;
 
 	*device = NULL;
 	s = get_dgram_socket();
@@ -79,10 +115,21 @@ static int kernel_get_device(struct wgdevice **device,
 	dev = calloc(1, sizeof(*dev));
 	if (!dev)
 		goto err;
+	/* The FreeBSD kernel uses zero as an internal sentinel for an unset Hx.
+	 * Expose the effective WireGuard message types expected by shared UI code. */
+	dev->init_header = u32_range_init(1, 1);
+	dev->resp_header = u32_range_init(2, 2);
+	dev->cookie_header = u32_range_init(3, 3);
+	dev->transport_header = u32_range_init(4, 4);
 	strlcpy(dev->name, ifname, sizeof(dev->name));
 	nvl_device = nvlist_unpack(wgd.wgd_data, wgd.wgd_size, 0);
 	if (!nvl_device)
 		goto err;
+	if (nvlist_exists_number(nvl_device, "awg-version")) {
+		number = nvlist_get_number(nvl_device, "awg-version");
+		if (number > 0 && number <= UINT32_MAX)
+			version = number;
+	}
 
 	if (nvlist_exists_number(nvl_device, "listen-port")) {
 		number = nvlist_get_number(nvl_device, "listen-port");
@@ -140,58 +187,30 @@ static int kernel_get_device(struct wgdevice **device,
 			dev->flags |= WGDEVICE_HAS_S4;
 		}
 	}
-	if (nvlist_exists_binary(nvl_device, "h1")) {
-		binary = nvlist_get_binary(nvl_device, "h1", &size);
-		if (binary && size < MAX_AWG_STRING_LEN)
-		{
-			dev->init_packet_magic_header = strdup((const char*)binary);
-			if (!dev->init_packet_magic_header) {
-				ret = ENOMEM;
-				goto err;
+	{
+		static const char *const names[] = { "h1", "h2", "h3", "h4" };
+		u32_range_t *const ranges[] = { &dev->init_header, &dev->resp_header,
+			&dev->cookie_header, &dev->transport_header };
+		const uint32_t flags[] = { WGDEVICE_HAS_H1, WGDEVICE_HAS_H2,
+			WGDEVICE_HAS_H3, WGDEVICE_HAS_H4 };
+
+		for (i = 0; i < 4; ++i) {
+			if (version >= WG_AWG_VERSION_3 && nvlist_exists_number(nvl_device, names[i])) {
+				/* Packed as (max << 32) | min, same as u32_range_t. */
+				*ranges[i] = nvlist_get_number(nvl_device, names[i]);
+				dev->flags |= flags[i];
+			} else if (nvlist_exists_binary(nvl_device, names[i])) {
+				binary = nvlist_get_binary(nvl_device, names[i], &size);
+				if (binary && size && ((const char *)binary)[size - 1] == '\0' &&
+				    u32_range_from_string(ranges[i], binary))
+					dev->flags |= flags[i];
 			}
-			dev->flags |= WGDEVICE_HAS_H1;
 		}
 	}
-	if (nvlist_exists_binary(nvl_device, "h2")) {
-		binary = nvlist_get_binary(nvl_device, "h2", &size);
-		if (binary && size < MAX_AWG_STRING_LEN)
-		{
-			dev->response_packet_magic_header = strdup((const char*)binary);
-			if (!dev->response_packet_magic_header) {
-				ret = ENOMEM;
-				goto err;
-			}
-			dev->flags |= WGDEVICE_HAS_H2;
-		}
-	}
-	if (nvlist_exists_binary(nvl_device, "h3")) {
-		binary = nvlist_get_binary(nvl_device, "h3", &size);
-		if (binary && size < MAX_AWG_STRING_LEN)
-		{
-			dev->underload_packet_magic_header = strdup((const char*)binary);
-			if (!dev->underload_packet_magic_header) {
-				ret = ENOMEM;
-				goto err;
-			}
-			dev->flags |= WGDEVICE_HAS_H3;
-		}
-	}
-	if (nvlist_exists_binary(nvl_device, "h4")) {
-		binary = nvlist_get_binary(nvl_device, "h4", &size);
-		if (binary && size < MAX_AWG_STRING_LEN)
-		{
-			dev->transport_packet_magic_header = strdup((const char*)binary);
-			if (!dev->transport_packet_magic_header) {
-				ret = ENOMEM;
-				goto err;
-			}
-			dev->flags |= WGDEVICE_HAS_H4;
-		}
-	}
 	if (nvlist_exists_binary(nvl_device, "i1"))
 	{
 		binary = nvlist_get_binary(nvl_device, "i1", &size);
-		if (binary && size < MAX_AWG_STRING_LEN)
+		if (binary && size && size <= WG_FREEBSD_MAX_AWG_STRING_LEN && ((const char *)binary)[size - 1] == '\0')
 		{
 			dev->i1 = strdup((const char*)binary);
 			if (!dev->i1) {
@@ -204,7 +223,7 @@ static int kernel_get_device(struct wgdevice **device,
 	if (nvlist_exists_binary(nvl_device, "i2"))
 	{
 		binary = nvlist_get_binary(nvl_device, "i2", &size);
-		if (binary && size < MAX_AWG_STRING_LEN)
+		if (binary && size && size <= WG_FREEBSD_MAX_AWG_STRING_LEN && ((const char *)binary)[size - 1] == '\0')
 		{
 			dev->i2 = strdup((const char*)binary);
 			if (!dev->i2) {
@@ -217,7 +236,7 @@ static int kernel_get_device(struct wgdevice **device,
 	if (nvlist_exists_binary(nvl_device, "i3"))
 	{
 		binary = nvlist_get_binary(nvl_device, "i3", &size);
-		if (binary && size < MAX_AWG_STRING_LEN)
+		if (binary && size && size <= WG_FREEBSD_MAX_AWG_STRING_LEN && ((const char *)binary)[size - 1] == '\0')
 		{
 			dev->i3 = strdup((const char*)binary);
 			if (!dev->i3) {
@@ -230,7 +249,7 @@ static int kernel_get_device(struct wgdevice **device,
 	if (nvlist_exists_binary(nvl_device, "i4"))
 	{
 		binary = nvlist_get_binary(nvl_device, "i4", &size);
-		if (binary && size < MAX_AWG_STRING_LEN)
+		if (binary && size && size <= WG_FREEBSD_MAX_AWG_STRING_LEN && ((const char *)binary)[size - 1] == '\0')
 		{
 			dev->i4 = strdup((const char*)binary);
 			if (!dev->i4) {
@@ -243,7 +262,7 @@ static int kernel_get_device(struct wgdevice **device,
 	if (nvlist_exists_binary(nvl_device, "i5"))
 	{
 		binary = nvlist_get_binary(nvl_device, "i5", &size);
-		if (binary && size < MAX_AWG_STRING_LEN)
+		if (binary && size && size <= WG_FREEBSD_MAX_AWG_STRING_LEN && ((const char *)binary)[size - 1] == '\0')
 		{
 			dev->i5 = strdup((const char*)binary);
 			if (!dev->i5) {
@@ -253,7 +272,45 @@ static int kernel_get_device(struct wgdevice **device,
 			dev->flags |= WGDEVICE_HAS_I5;
 		}
 	}
+	if (version >= WG_AWG_VERSION_3) {
+		struct {
+			const char *name;
+			u16_range_t *range;
+			uint32_t flag;
+		} range_params[] = {
+			{ "content-padding-addition", &dev->content_padding_addition, WGDEVICE_HAS_CONTENT_PADDING_ADDITION },
+			{ "rekey-after-time", &dev->rekey_after_time, WGDEVICE_HAS_REKEY_AFTER_TIME },
+			{ "rekey-timeout", &dev->rekey_timeout, WGDEVICE_HAS_REKEY_TIMEOUT },
+			{ "reject-after-time", &dev->reject_after_time, WGDEVICE_HAS_REJECT_AFTER_TIME },
+			{ "keepalive-timeout", &dev->keepalive_timeout, WGDEVICE_HAS_KEEPALIVE_TIMEOUT },
+			{ "max-handshake-attempts", &dev->max_handshake_attempts, WGDEVICE_HAS_MAX_HANDSHAKE_ATTEMPTS },
+		};
 
+		if (nvlist_exists_binary(nvl_device, "header-protection-key")) {
+			binary = nvlist_get_binary(nvl_device, "header-protection-key", &size);
+			if (binary && size == sizeof(dev->header_protection_key)) {
+				memcpy(dev->header_protection_key, binary, size);
+				dev->flags |= WGDEVICE_HAS_HEADER_PROTECTION_KEY;
+			}
+		}
+		for (i = 0; i < sizeof(range_params) / sizeof(range_params[0]); ++i) {
+			if (nvlist_exists_number(nvl_device, range_params[i].name) &&
+			    (number = nvlist_get_number(nvl_device, range_params[i].name)) <= UINT32_MAX) {
+				/* Packed as (max << 16) | min, same as u16_range_t. */
+				*range_params[i].range = number;
+				dev->flags |= range_params[i].flag;
+			}
+		}
+		if (nvlist_exists_bool(nvl_device, "random-trailers")) {
+			dev->random_trailers = nvlist_get_bool(nvl_device, "random-trailers");
+			dev->flags |= WGDEVICE_HAS_RANDOM_TRAILERS;
+		}
+		if (nvlist_exists_bool(nvl_device, "disable-cookies")) {
+			dev->disable_cookies = nvlist_get_bool(nvl_device, "disable-cookies");
+			dev->flags |= WGDEVICE_HAS_DISABLE_COOKIES;
+		}
+	}
+
 	if (nvlist_exists_number(nvl_device, "user-cookie")) {
 		number = nvlist_get_number(nvl_device, "user-cookie");
 		if (number <= UINT32_MAX) {
@@ -306,8 +363,9 @@ static int kernel_get_device(struct wgdevice **device,
 		}
 		if (nvlist_exists_number(nvl_peers[i], "persistent-keepalive-interval")) {
 			number = nvlist_get_number(nvl_peers[i], "persistent-keepalive-interval");
-			if (number <= UINT16_MAX) {
-				peer->persistent_keepalive_interval = number;
+			if (number <= UINT32_MAX) {
+				peer->persistent_keepalive_interval = version >= WG_AWG_VERSION_3 &&
+					number > UINT16_MAX ? number : u16_range_init(number, number);
 				peer->flags |= WGPEER_HAS_PERSISTENT_KEEPALIVE_INTERVAL;
 			}
 		}
@@ -417,7 +475,29 @@ static int kernel_set_device(struct wgdevice *dev)
 	size_t peer_count = 0, i = 0;
 	struct wgpeer *peer;
 	int ret = 0, s;
+	uint32_t version = kernel_get_awg_version(dev->name);
+	const uint32_t awg3_flags = WGDEVICE_HAS_HEADER_PROTECTION_KEY |
+		WGDEVICE_HAS_CONTENT_PADDING_ADDITION | WGDEVICE_HAS_REKEY_AFTER_TIME |
+		WGDEVICE_HAS_REKEY_TIMEOUT | WGDEVICE_HAS_REJECT_AFTER_TIME |
+		WGDEVICE_HAS_KEEPALIVE_TIMEOUT | WGDEVICE_HAS_MAX_HANDSHAKE_ATTEMPTS |
+		WGDEVICE_HAS_RANDOM_TRAILERS |
+		WGDEVICE_HAS_DISABLE_COOKIES;
 
+	if (version < WG_AWG_VERSION_3 && (dev->flags & awg3_flags)) {
+		errno = EOPNOTSUPP;
+		return -errno;
+	}
+	if (version < WG_AWG_VERSION_3) {
+		for_each_wgpeer(dev, peer) {
+			if ((peer->flags & WGPEER_HAS_PERSISTENT_KEEPALIVE_INTERVAL) &&
+			    u16_range_lo(peer->persistent_keepalive_interval) !=
+			    u16_range_hi(peer->persistent_keepalive_interval)) {
+				errno = EOPNOTSUPP;
+				return -errno;
+			}
+		}
+	}
+
 	strlcpy(wgd.wgd_name, dev->name, sizeof(wgd.wgd_name));
 
 	nvl_device = nvlist_create(0);
@@ -449,24 +529,59 @@ static int kernel_set_device(struct wgdevice *dev)
 		nvlist_add_number(nvl_device, "s3", dev->cookie_reply_packet_junk_size);
 	if (dev->flags & WGDEVICE_HAS_S4)
 		nvlist_add_number(nvl_device, "s4", dev->transport_packet_junk_size);
-	if (dev->flags & WGDEVICE_HAS_H1)
-		nvlist_add_binary(nvl_device, "h1", dev->init_packet_magic_header, strlen(dev->init_packet_magic_header) + 1);
-	if (dev->flags & WGDEVICE_HAS_H2)
-		nvlist_add_binary(nvl_device, "h2", dev->response_packet_magic_header, strlen(dev->response_packet_magic_header) + 1);
-	if (dev->flags & WGDEVICE_HAS_H3)
-		nvlist_add_binary(nvl_device, "h3", dev->underload_packet_magic_header, strlen(dev->underload_packet_magic_header) + 1);
-	if (dev->flags & WGDEVICE_HAS_H4)
-		nvlist_add_binary(nvl_device, "h4", dev->transport_packet_magic_header, strlen(dev->transport_packet_magic_header) + 1);
+	{
+		static const char *const names[] = { "h1", "h2", "h3", "h4" };
+		const u32_range_t ranges[] = { dev->init_header, dev->resp_header,
+			dev->cookie_header, dev->transport_header };
+		const uint32_t flags[] = { WGDEVICE_HAS_H1, WGDEVICE_HAS_H2,
+			WGDEVICE_HAS_H3, WGDEVICE_HAS_H4 };
+
+		for (size_t h = 0; h < 4; ++h) {
+			if (!(dev->flags & flags[h]))
+				continue;
+			if (version >= WG_AWG_VERSION_3)
+				nvlist_add_number(nvl_device, names[h], ranges[h]);
+			else {
+				const char *value = u32_range_to_string(ranges[h]);
+				nvlist_add_binary(nvl_device, names[h], value, strlen(value) + 1);
+			}
+		}
+	}
 	if (dev->flags & WGDEVICE_HAS_I1)
-		nvlist_add_binary(nvl_device, "i1", dev->i1, strlen(dev->i1) + 1);
+		nvlist_add_binary(nvl_device, "i1", dev->i1 ? dev->i1 : "", strlen(dev->i1 ? dev->i1 : "") + 1);
 	if (dev->flags & WGDEVICE_HAS_I2)
-		nvlist_add_binary(nvl_device, "i2", dev->i2, strlen(dev->i2) + 1);
+		nvlist_add_binary(nvl_device, "i2", dev->i2 ? dev->i2 : "", strlen(dev->i2 ? dev->i2 : "") + 1);
 	if (dev->flags & WGDEVICE_HAS_I3)
-		nvlist_add_binary(nvl_device, "i3", dev->i3, strlen(dev->i3) + 1);
+		nvlist_add_binary(nvl_device, "i3", dev->i3 ? dev->i3 : "", strlen(dev->i3 ? dev->i3 : "") + 1);
 	if (dev->flags & WGDEVICE_HAS_I4)
-		nvlist_add_binary(nvl_device, "i4", dev->i4, strlen(dev->i4) + 1);
+		nvlist_add_binary(nvl_device, "i4", dev->i4 ? dev->i4 : "", strlen(dev->i4 ? dev->i4 : "") + 1);
 	if (dev->flags & WGDEVICE_HAS_I5)
-		nvlist_add_binary(nvl_device, "i5", dev->i5, strlen(dev->i5) + 1);
+		nvlist_add_binary(nvl_device, "i5", dev->i5 ? dev->i5 : "", strlen(dev->i5 ? dev->i5 : "") + 1);
+	if (dev->flags & WGDEVICE_HAS_HEADER_PROTECTION_KEY)
+		nvlist_add_binary(nvl_device, "header-protection-key", dev->header_protection_key,
+			sizeof(dev->header_protection_key));
+	if (dev->flags & WGDEVICE_HAS_CONTENT_PADDING_ADDITION)
+		nvlist_add_number(nvl_device, "content-padding-addition",
+			dev->content_padding_addition);
+	if (dev->flags & WGDEVICE_HAS_REKEY_AFTER_TIME)
+		nvlist_add_number(nvl_device, "rekey-after-time",
+			dev->rekey_after_time);
+	if (dev->flags & WGDEVICE_HAS_REKEY_TIMEOUT)
+		nvlist_add_number(nvl_device, "rekey-timeout",
+			dev->rekey_timeout);
+	if (dev->flags & WGDEVICE_HAS_REJECT_AFTER_TIME)
+		nvlist_add_number(nvl_device, "reject-after-time",
+			dev->reject_after_time);
+	if (dev->flags & WGDEVICE_HAS_KEEPALIVE_TIMEOUT)
+		nvlist_add_number(nvl_device, "keepalive-timeout",
+			dev->keepalive_timeout);
+	if (dev->flags & WGDEVICE_HAS_MAX_HANDSHAKE_ATTEMPTS)
+		nvlist_add_number(nvl_device, "max-handshake-attempts",
+			dev->max_handshake_attempts);
+	if (dev->flags & WGDEVICE_HAS_RANDOM_TRAILERS)
+		nvlist_add_bool(nvl_device, "random-trailers", dev->random_trailers);
+	if (dev->flags & WGDEVICE_HAS_DISABLE_COOKIES)
+		nvlist_add_bool(nvl_device, "disable-cookies", dev->disable_cookies);
 	if (dev->flags & WGDEVICE_HAS_FWMARK)
 		nvlist_add_number(nvl_device, "user-cookie", dev->fwmark);
 	if (dev->flags & WGDEVICE_REPLACE_PEERS)
@@ -491,7 +606,9 @@ static int kernel_set_device(struct wgdevice *dev)
 		if (peer->flags & WGPEER_HAS_PRESHARED_KEY)
 			nvlist_add_binary(nvl_peers[i], "preshared-key", peer->preshared_key, sizeof(peer->preshared_key));
 		if (peer->flags & WGPEER_HAS_PERSISTENT_KEEPALIVE_INTERVAL)
-			nvlist_add_number(nvl_peers[i], "persistent-keepalive-interval", peer->persistent_keepalive_interval);
+			nvlist_add_number(nvl_peers[i], "persistent-keepalive-interval",
+				version >= WG_AWG_VERSION_3 ? peer->persistent_keepalive_interval :
+				u16_range_lo(peer->persistent_keepalive_interval));
 		if (peer->endpoint.addr.sa_family == AF_INET || peer->endpoint.addr.sa_family == AF_INET6)
 			nvlist_add_binary(nvl_peers[i], "endpoint", &peer->endpoint.addr, peer->endpoint.addr.sa_len);
 		if (peer->flags & WGPEER_REPLACE_ALLOWEDIPS)
@@ -502,6 +619,8 @@ static int kernel_set_device(struct wgdevice *dev)
 			nvl_aips[j] = nvlist_create(0);
 			if (!nvl_aips[j])
 				goto err_peer;
+			if (aip->flags)
+				nvlist_add_number(nvl_aips[j], "flags", aip->flags);
 			nvlist_add_number(nvl_aips[j], "cidr", aip->cidr);
 			if (aip->family == AF_INET)
 				nvlist_add_binary(nvl_aips[j], "ipv4", &aip->ip4, sizeof(aip->ip4));
