--- src/udp_proxy_s5.c.orig	Sat Oct  2 17:48:12 2004
+++ src/udp_proxy_s5.c	Sat Oct 16 18:35:59 2004
@@ -37,6 +37,7 @@
 	struct PHB *phb = data;
 	struct sockaddr_in sin;
 	int len;
+	int error = ETIMEDOUT;
 
 	gaim_input_remove(phb->inpa);
 	gaim_debug(GAIM_DEBUG_INFO, "socks5 proxy", "Able to read again.\n");
@@ -85,7 +86,6 @@
 		return;
 	}
 
-	int error = ETIMEDOUT;
 	gaim_debug(GAIM_DEBUG_INFO, "QQ", "Connect didn't block\n");
 	len = sizeof(error);
 	if (getsockopt(phb->udpsock, SOL_SOCKET, SO_ERROR, &error, &len) < 0) {
@@ -216,11 +216,12 @@
 {
 	unsigned char buf[512];
 	struct PHB *phb = data;
+	int ret;
 
 	gaim_input_remove(phb->inpa);
 	gaim_debug(GAIM_DEBUG_INFO, "socks5 proxy", "Able to read.\n");
 
-	int ret = read(source, buf, 2);
+	ret = read(source, buf, 2);
 	if (ret < 2) {
 		gaim_debug(GAIM_DEBUG_INFO, "s5_canread", "packet smaller than 2 octet\n");
 		close(source);
