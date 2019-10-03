--- src/tun.h.orig	2018-01-13 18:43:41 UTC
+++ src/tun.h
@@ -35,5 +35,6 @@ struct tun_lease_st {
 
 ssize_t tun_write(int sockfd, const void *buf, size_t len);
 ssize_t tun_read(int sockfd, void *buf, size_t len);
+int tun_claim(int sockfd);
 
 #endif
