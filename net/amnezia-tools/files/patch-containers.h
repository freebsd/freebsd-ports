--- containers.h.orig	2025-09-03 14:11:13 UTC
+++ containers.h
@@ -34,6 +34,10 @@ struct timespec64 {
 	int64_t tv_nsec;
 };
 
+enum {
+	WGALLOWEDIP_REMOVE_ME = 1U << 0,
+};
+
 struct wgallowedip {
 	uint16_t family;
 	union {
@@ -41,6 +45,7 @@ struct wgallowedip {
 		struct in6_addr ip6;
 	};
 	uint8_t cidr;
+	uint32_t flags;
 	struct wgallowedip *next_allowedip;
 };
 
