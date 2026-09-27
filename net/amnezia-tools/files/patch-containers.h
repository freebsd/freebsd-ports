--- containers.h.orig	2026-08-12 22:24:49 UTC
+++ containers.h
@@ -32,6 +32,10 @@ struct timespec64 {
 	int64_t tv_nsec;
 };
 
+enum {
+	WGALLOWEDIP_REMOVE_ME = 1U << 0,
+};
+
 struct wgallowedip {
 	uint16_t family;
 	union {
@@ -39,6 +43,7 @@ struct wgallowedip {
 		struct in6_addr ip6;
 	};
 	uint8_t cidr;
+	uint32_t flags;
 	struct wgallowedip *next_allowedip;
 };
 
