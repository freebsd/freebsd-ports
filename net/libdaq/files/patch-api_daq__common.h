--- api/daq_common.h.orig	2019-09-06 11:14:19 UTC
+++ api/daq_common.h
@@ -30,6 +30,9 @@ extern "C" {
 #include <sys/time.h>
 #include <stdint.h>
 #include <unistd.h>
+#if defined(__OpenBSD__) || defined(__FreeBSD__) || defined(__NetBSD__) || defined(__DragonFly__)
+#include <sys/socket.h>
+#endif
 
 #ifndef DAQ_SO_PUBLIC
 #  ifdef HAVE_VISIBILITY
