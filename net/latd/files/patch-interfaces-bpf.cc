--- interfaces-bpf.cc.orig	Tue Dec 23 23:40:11 2003
+++ interfaces-bpf.cc	Tue Dec 23 23:40:32 2003
@@ -25,6 +25,7 @@
 #include <sys/time.h>
 #include <sys/socket.h>
 #include <sys/uio.h>
+#include <assert.h>
 
 #include <net/if.h>
 #include <net/bpf.h>
