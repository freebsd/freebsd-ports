--- multicat.c.orig	2019-11-15 11:52:01 UTC
+++ multicat.c
@@ -280,14 +280,14 @@ static ssize_t raw_Write( const void *p_buf, size_t i_
     ssize_t i_ret;
     struct iovec iov[2];
 
-    #if defined(__FreeBSD__)
+    #if defined(__FreeBSD__) || defined(__DragonFly__)
     pktheader.udph.uh_ulen
     #else
     pktheader.udph.len
     #endif
     = htons(sizeof(struct udphdr) + i_len);
 
-    #if defined(__FreeBSD__)
+    #if defined(__FreeBSD__) || defined(__DragonFly__)
     pktheader.iph.ip_len = htons(sizeof(struct udprawpkt) + i_len);
     #endif
 
