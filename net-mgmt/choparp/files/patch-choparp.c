--- choparp.c.orig	2002-11-08 07:36:03.000000000 +0900
+++ choparp.c	2010-05-04 20:39:28.279310506 +0900
@@ -42,6 +42,7 @@
 #include <string.h>
 #include <sys/types.h>
 #include <fcntl.h>
+#include <sys/event.h>
 #include <sys/time.h>
 #include <sys/ioctl.h>
 #include <net/bpf.h>
@@ -75,6 +76,7 @@
 
 struct cidr *targets = NULL, *excludes = NULL;
 u_char	target_mac[ETHER_ADDR_LEN];	/* target MAC address */
+int verbose = 0;
 
 /*
    ARP filter program
@@ -239,6 +241,16 @@
 	fprintf(stderr,"checkarp: WARNING: received unknown type ARP request.\n");
 	return(0);
     }
+    if (ntohl(*(u_int32_t *)(arp->arp_tpa)) == ntohl(*(u_int32_t *)(arp->arp_spa))) {
+	if (verbose != 0)
+	    fprintf(stderr,"checkarp: WARNING: sender equal dest.\n");
+	return(0);
+    }
+    if (0 == ntohl(*(u_int32_t *)(arp->arp_spa))) {
+	if (verbose != 0)
+	    fprintf(stderr,"checkarp: WARNING: zero sender address.\n");
+	return(0);
+    }
     target_ip = ntohl(*(u_int32_t *)(arp->arp_tpa));
     return match(target_ip, targets) && !match(target_ip, excludes);
 }
@@ -280,13 +292,22 @@
     char    *rframe;
     char    *sframe;
     size_t  frame_len;
-    fd_set  fdset;
+    int     kq;
+    struct  kevent kev;
 
-    FD_ZERO(&fdset);
-    FD_SET(fd,&fdset);
+    if ((kq = kqueue()) < 0) {
+        perror("kqueue");
+        return;
+    }
+
+    EV_SET(&kev, fd, EVFILT_READ, EV_ADD, 0, 0, NULL);
+    if (kevent(kq, &kev, 1, NULL, 0, NULL) < 0 ) {
+        perror("kevent");
+        return;
+    }
 
     for(;;){
-        int r = select(fd+1,&fdset, 0, 0, 0);
+        int r = kevent(kq, NULL, 0, &kev, 1, NULL);
 
         if (r < 0) {
             if (errno == EINTR)
@@ -295,7 +316,7 @@
             return;
         }
 
-        rlen = read(fd, buf, buflen);
+        rlen = read(kev.ident, buf, buflen);
         if (rlen < 0) {
             if (errno == EINTR)
                 continue;
@@ -307,7 +328,7 @@
 	while((rframe = getarp(p, rlen, &nextp, &nextlen)) != NULL){
 	    if (checkarp(rframe)){
 		sframe = gen_arpreply(rframe, &frame_len);
-		write(fd, sframe, frame_len);
+		write(kev.ident, sframe, frame_len);
 	    }
 	    p = nextp;
 	    rlen = nextlen;
@@ -362,13 +383,13 @@
 
 void
 usage(void){
-    fprintf(stderr,"usage: choparp if_name mac_addr [-]addr/mask...\n");
+    fprintf(stderr,"usage: choparp [-v] if_name mac_addr [-]addr/mask...\n");
     exit(-1);
 }
 
 int
 main(int argc, char **argv){
-    int	fd;
+    int	ch, fd;
     char *buf, *ifname;
     struct cidr **targets_tail = &targets, **excludes_tail = &excludes;
 #define APPEND(LIST,ADDR,MASK) \
@@ -381,13 +402,24 @@
     } while (0)
     size_t buflen;
 
-    if (argc < 4)
+    while ((ch = getopt(argc, argv, "v")) != -1)
+        switch (ch) {
+        case 'v':
+            verbose++;
+            break;
+        default:
+            usage();
+        }
+    argc -= optind;
+    argv += optind;
+
+    if (argc < 3)
 	usage();
 
-    ifname = argv[1];
-    if (setmac(argv[2], ifname))
+    ifname = argv[0];
+    if (setmac(argv[1], ifname))
 	usage();
-    argv += 3; argc -= 3;
+    argv += 2; argc -= 2;
 
     while (argc > 0) {
 	u_int32_t addr, mask = ~0;
@@ -437,6 +469,9 @@
 #endif
     if ((fd = openbpf(ifname, &buf, &buflen)) < 0)
 	return(-1);
+	#ifndef DEBUG
+    		daemon(0, 0);
+	#endif
     loop(fd, buf, buflen);
     return(-1);
 }
