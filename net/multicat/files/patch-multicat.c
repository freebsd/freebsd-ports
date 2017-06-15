--- multicat.c.orig	2016-10-07 14:32:44 UTC
+++ multicat.c
@@ -44,7 +44,7 @@
 #include <sys/ioctl.h>
 #include <syslog.h>
 
-#ifdef __FreeBSD__
+#if defined(__FreeBSD__) || defined(__DragonFly__)
 #   include <sys/uio.h>
 #endif
 
@@ -280,14 +280,14 @@ static ssize_t raw_Write( const void *p_
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
 
