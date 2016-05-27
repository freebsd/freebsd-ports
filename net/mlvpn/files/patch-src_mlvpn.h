--- src/mlvpn.h.orig	2015-12-28 11:20:16 UTC
+++ src/mlvpn.h
@@ -138,6 +138,7 @@ typedef struct mlvpn_tunnel_s
     char *name;           /* tunnel name */
     char bindaddr[MLVPN_MAXHNAMSTR]; /* packets source */
     char bindport[MLVPN_MAXPORTSTR]; /* packets port source (or NULL) */
+	uint32_t bindfib;     /* FIB number to use */
     char destaddr[MLVPN_MAXHNAMSTR]; /* remote server ip (can be hostname) */
     char destport[MLVPN_MAXPORTSTR]; /* remote server port */
     int fd;               /* socket file descriptor */
@@ -193,7 +194,7 @@ int mlvpn_rtun_wrr_reset(struct rtunhead
 mlvpn_tunnel_t *mlvpn_rtun_wrr_choose();
 mlvpn_tunnel_t *mlvpn_rtun_choose();
 mlvpn_tunnel_t *mlvpn_rtun_new(const char *name,
-    const char *bindaddr, const char *bindport,
+    const char *bindaddr, const char *bindport, uint32_t bindfib,
     const char *destaddr, const char *destport,
     int server_mode, uint32_t timeout,
     int fallback_only, uint32_t bandwidth,
