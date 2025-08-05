--- containers.h.orig	2024-10-01 13:02:42 UTC
+++ containers.h
@@ -29,6 +29,10 @@ struct timespec64 {
 	int64_t tv_nsec;
 };
 
+enum {
+	WGALLOWEDIP_REMOVE_ME = 1U << 0,
+};
+
 struct wgallowedip {
 	uint16_t family;
 	union {
@@ -36,6 +40,7 @@ struct wgallowedip {
 		struct in6_addr ip6;
 	};
 	uint8_t cidr;
+	uint32_t flags;
 	struct wgallowedip *next_allowedip;
 };
 
