--- sysdep.h.dist	Wed Nov 17 16:37:52 2004
+++ sysdep.h	Wed Nov 17 16:37:37 2004
@@ -1,6 +1,7 @@
 #ifndef __SYSDEP_H__
 #define __SYSDEP_H__
 
+#include <sys/types.h>
 #include <netinet/in.h>

 int tun_open(char *dev);
