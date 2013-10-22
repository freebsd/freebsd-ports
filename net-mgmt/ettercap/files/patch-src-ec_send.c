--- src/ec_send.c.orig	2013-09-12 04:18:45.000000000 +0800
+++ src/ec_send.c	2013-10-22 03:13:55.980398663 +0800
@@ -22,7 +22,7 @@
 #include <ec.h>
 
 #if defined(OS_DARWIN) || defined(OS_BSD)
-   #include <net/bpf.h>
+//   #include <net/bpf.h>
    #include <sys/ioctl.h>
 #endif
 
