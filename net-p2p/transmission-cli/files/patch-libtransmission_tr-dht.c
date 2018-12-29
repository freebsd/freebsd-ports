--- libtransmission/tr-dht.c.orig	2018-12-27 04:04:08 UTC
+++ libtransmission/tr-dht.c
@@ -694,6 +694,11 @@ dht_random_bytes (void * buf, size_t size)
     return size;
 }
 
+int dht_sendto(int sockfd, void const* buf, int len, int flags, struct sockaddr const* to, int tolen)
+{
+    return sendto(sockfd, buf, len, flags, to, tolen);
+}
+
 #if defined (_WIN32) && !defined (__MINGW32__)
 int
 dht_gettimeofday (struct timeval * tv, struct timezone * tz)
