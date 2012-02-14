$OpenBSD: patch-config_h,v 1.4 2008/12/20 04:36:11 canacar Exp $
--- config.h.orig	Tue Nov  6 22:34:18 2007
+++ config.h	Fri Dec 19 20:28:01 2008
@@ -74,11 +74,20 @@
 #define HAVE_PFSYNC_STATE
 #endif
 
+#if OS_LEVEL > 43
+#define HAVE_PFSYNC_KEY
+#define HAVE_NETWORK_ORDER
+#endif
+
 #ifdef HAVE_PFSYNC_STATE
 typedef struct pfsync_state pf_state_t;
 typedef struct pfsync_state_host pf_state_host_t;
 typedef struct pfsync_state_peer pf_state_peer_t;
+#ifdef HAVE_NETWORK_ORDER
+#define COUNTER(c) ((((u_int64_t) ntohl(c[0]))<<32) + ntohl(c[1]))
+#else
 #define COUNTER(c) ((((u_int64_t) c[0])<<32) + c[1])
+#endif
 #define pfs_ifname ifname
 #else
 typedef struct pf_state pf_state_t;
