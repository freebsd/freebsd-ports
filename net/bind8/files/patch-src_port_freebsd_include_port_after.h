--- src/port/freebsd/include/port_after.h.Dist	Sat Apr 27 18:12:45 2002
+++ src/port/freebsd/include/port_after.h	Sun Nov  3 01:34:40 2002
@@ -6,7 +6,6 @@
 #define USE_WAITPID
 #define HAVE_GETRUSAGE
 #define HAVE_FCHMOD
-#define NEED_PSELECT
 #define HAVE_SA_LEN
 #define HAVE_MINIMUM_IFREQ
 #define USE_LOG_CONS
@@ -21,6 +20,13 @@
 #define KSYMS		"/kernel"
 #define KMEM		"/dev/kmem"
 #define UDPSUM		"udpcksum"
+
+#if defined(__FreeBSD_version) && __FreeBSD_version >= 500041
+#undef NEED_PSELECT
+#include <sys/select.h>
+#else
+#define NEED_PSELECT
+#endif
 
 #include <sys/types.h>
 #include <sys/socket.h>
