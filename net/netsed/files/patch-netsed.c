--- netsed.c.orig	Tue Jan  9 11:30:40 2001
+++ netsed.c	Tue Jan  9 11:43:41 2001
@@ -134,8 +134,10 @@
 
 
 void bind_and_listen(int tcp,int port) {
+  int on=1;
   struct sockaddr_in laddr;
   lsock=socket(PF_INET,tcp ? SOCK_STREAM:SOCK_DGRAM,0);
+  setsockopt(lsock, SOL_SOCKET, SO_REUSEADDR, (char *)&on, sizeof(on));
   fcntl(lsock,F_SETFL,O_NONBLOCK);
   laddr.sin_family = PF_INET;
   laddr.sin_port = htons (port);
@@ -186,7 +188,6 @@
   rd=read(s1,buf,sizeof(buf));
   if (rd<0 && errno!=EAGAIN) return 0; // s1 not connected
   if (rd>0) {
-    fcntl(s2,F_SETFL,O_SYNC);
     printf("[+] Caught server -> client packet.\n");
     rd=sed_the_buffer(rd);
     if (write(s2,b2,rd)<=0) return 0; // not able to send
@@ -195,7 +196,6 @@
   rd=read(s2,buf,sizeof(buf));
   if (rd<0 && errno!=EAGAIN) return 0; // s2 not connected
   if (rd>0) {
-    fcntl(s1,F_SETFL,O_SYNC);
     printf("[+] Caught client -> server packet.\n");
     rd=sed_the_buffer(rd);
     if (write(s1,b2,rd)<=0) return 0; // not able to send
