--- nmap.h.orig	Sun Mar 30 18:44:33 2003
+++ nmap.h	Sun Mar 30 18:51:47 2003
@@ -344,9 +344,12 @@
 #elif defined(UW)
 #  define NET_SIZE_T size_t
 #elif defined(__FreeBSD__)
-  /* XXX: Apache didn't have this one,
-          so watch it be wrong :)... */
-#  define NET_SIZE_T size_t
+#  if __FreeBSD__ >= 2
+#    include <osreldate.h>
+#    if __FreeBSD_version >= 400000
+#      define NET_SIZE_T socklen_t
+#    endif
+#  endif
 #elif defined(OPENBSD)
 #  define NET_SIZE_T socklen_t
 #elif defined(NETBSD)
