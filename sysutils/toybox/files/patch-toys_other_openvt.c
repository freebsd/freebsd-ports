--- toys/other/openvt.c.orig	2022-08-12 07:58:03 UTC
+++ toys/other/openvt.c
@@ -44,8 +44,8 @@ config DEALLOCVT
 
 #define FOR_openvt
 #include "toys.h"
-#include <linux/vt.h>
-#include <linux/kd.h>
+#include <sys/consio.h>
+#include <sys/kbio.h>
 
 GLOBALS(
   long c;
@@ -72,12 +72,17 @@ static int activate(int fd, int cc)
 
 void openvt_main(void)
 {
+  struct vt_stat {
+	  unsigned short v_active;
+	  unsigned short v_signal;
+	  unsigned short v_state;
+  };
   struct vt_stat vstate;
   int fd, cc = (int)TT.c;
   pid_t pid;
 
   // find current console
-  if (-1 == (ioctl(fd = open_console(), VT_GETSTATE, &vstate)) ||
+  if (-1 == (ioctl(fd = open_console(), VT_GETACTIVE, &vstate)) ||
       (!cc && 0>=(cc = xioctl(fd, VT_OPENQRY, &fd))))
     perror_exit("can't find open VT");
 
@@ -95,7 +100,7 @@ void openvt_main(void)
     while (-1 == waitpid(pid, NULL, 0) && errno == EINTR) errno = 0;
     if (FLAG(s)) {
       activate(fd, vstate.v_active);
-      dprintf(2, "%d\n", ioctl(fd, VT_DISALLOCATE, cc));
+      dprintf(2, "%d\n", ioctl(fd, VT_ACTIVATE, cc));
     }
   }
 }
@@ -111,5 +116,5 @@ void deallocvt_main(void)
   int fd = open_console(), vt_num = 0; // 0 = all
 
   if (*toys.optargs) vt_num = atolx_range(*toys.optargs, 1, 63);
-  if (-1 == ioctl(fd, VT_DISALLOCATE, vt_num)) perror_exit("%d", vt_num);
+  if (-1 == ioctl(fd, VT_ACTIVATE, vt_num)) perror_exit("%d", vt_num);
 }
