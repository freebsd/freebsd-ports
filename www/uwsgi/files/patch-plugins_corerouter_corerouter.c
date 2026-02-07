Fix SOCK_NONBLOCK handling for FreeBSD, copied from NetBSD.
--- plugins/corerouter/corerouter.c.orig	2024-06-05 01:59:02 UTC
+++ plugins/corerouter/corerouter.c
@@ -822,7 +822,7 @@ void uwsgi_corerouter_loop(int id, void *data) {
 			while (ugs) {
 				if (ugs->gateway == &ushared->gateways[id] && ucr->interesting_fd == ugs->fd) {
 					if (!ugs->subscription) {
-#if defined(__linux__) && defined(SOCK_NONBLOCK) && !defined(OBSOLETE_LINUX_KERNEL)
+#if (defined(__linux__) || defined(__FreeBSD__)) && defined(SOCK_NONBLOCK) && !defined(OBSOLETE_LINUX_KERNEL)
 						new_connection = accept4(ucr->interesting_fd, (struct sockaddr *) &cr_addr, &cr_addr_len, SOCK_NONBLOCK);
 						if (new_connection < 0) {
 							taken = 1;
