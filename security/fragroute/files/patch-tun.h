
	

	Include patch below as files/patch-tun.h

--- tun.h.orig	Sun Mar 13 18:32:16 2005
+++ tun.h	Sun Mar 13 18:32:06 2005
@@ -9,8 +9,6 @@
 #ifndef TUN_H
 #define TUN_H
 
-typedef struct tun tun_t;
-
 typedef void (*tun_handler)(void *buf, size_t len, void *arg);
 
 tun_t	*tun_open(struct addr *src, struct addr *dst, int mtu);

