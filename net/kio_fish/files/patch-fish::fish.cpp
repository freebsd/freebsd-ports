--- fish/fish.cpp	Mon Oct 22 14:52:05 2001
+++ fish/fish.cpp.new	Mon Nov 26 22:13:52 2001
@@ -39,6 +39,15 @@
 #ifdef HAVE_TERMIOS_H
 #include <termios.h>
 #endif
+#ifdef HAVE_SYS_TYPES_H
+#include <sys/types.h>
+#endif
+#ifdef HAVE_SYS_IOCTL_H
+#include <sys/ioctl.h>
+#endif
+#ifdef HAVE_LIBUTIL_H
+#include <libutil.h>
+#endif
 #include <math.h>
 #include <unistd.h>
 #include <sys/socket.h>
