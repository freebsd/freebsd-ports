--- ./measflow.c.orig	2009-12-01 13:20:07.000000000 -0800
+++ ./measflow.c	2011-06-11 10:51:08.000000000 -0700
@@ -41,7 +41,6 @@
 
 struct timeval prober_packet_gap(struct timeval y, struct timeval x);
 void prober_swait(struct timeval tv, double sleepRes);
-void prober_sbusywait(struct timeval tv);
 
 int mflowSender(int tcpsock, int udpsock, struct sockaddr_in *from, 
 		double capacity, double sleepRes, double *recvrate)
