--- uapi/freebsd/dev/wg/if_wg.h.orig	2026-08-12 22:24:49 UTC
+++ uapi/freebsd/dev/wg/if_wg.h
@@ -10,6 +10,9 @@ struct wg_data_io {
 	size_t wgd_size;
 };
 
+#define WG_AWG_VERSION_2 2
+#define WG_AWG_VERSION_3 3
+
 #define SIOCSWG _IOWR('i', 210, struct wg_data_io)
 #define SIOCGWG _IOWR('i', 211, struct wg_data_io)
 
