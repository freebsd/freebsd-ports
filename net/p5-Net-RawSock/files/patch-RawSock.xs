--- RawSock.xs.orig     Thu Jan 30 00:11:00 2003
+++ RawSock.xs  Thu Jan 30 09:58:31 2003
@@ -15,6 +15,7 @@

 #include <sys/types.h>
 #include <sys/socket.h>
+#include <netinet/in.h>
 #include <fcntl.h>


@@ -67,7 +68,9 @@
         RETVAL = 2;
       } else {
         len = ntohs(ip_hdr->tot_len);
-        if (sendto(fd,(char *)pkt,len,0x0,(struct sockaddr *)&sa,sizeof(sa))<0) {
+       ip_hdr->tot_len = len;
+        if (sendto(fd, (void *)pkt, len, 0x0,
+                   (struct sockaddr *)&sa, sizeof(sa)) < len) {
           RETVAL = 3;
         } else {
           RETVAL = 0;
