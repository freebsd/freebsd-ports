--- src/wmnd.h.orig	Tue May 22 05:06:36 2001
+++ src/wmnd.h	Thu Nov 29 16:08:01 2001
@@ -24,6 +24,37 @@
 #include <X11/xpm.h>
 #include <X11/extensions/shape.h>
 
+#ifdef USE_FREEBSD_SYSCTL
+
+#include <sys/types.h>
+#include <sys/socket.h>
+#include <sys/sysctl.h>
+#include <sys/time.h>
+#include <net/if.h>
+#include <net/if_mib.h>
+
+/* internal structure used for freebsd-systcl */
+
+int freebsd_interface_count=0;
+
+int get_ifmib_general(int row, struct ifmibdata *ifmd) {
+
+  int name[6], len;
+
+  len=sizeof(struct ifmibdata);
+
+  name[0] = CTL_NET;
+    name[1] = PF_LINK;
+    name[2] = NETLINK_GENERIC;
+    name[3] = IFMIB_IFDATA;
+    name[4] = row;
+    name[5] = IFDATA_GENERAL;  
+
+    return sysctl(name, 6, ifmd, &len, NULL, 0);
+}
+
+#endif
+
 /*
  * Wmnd version number, do not modify line layout or sed will not find
  * the main version number
