--- src/mod/codecs/mod_dahdi_codec/mod_dahdi_codec.c.orig	2020-05-12 10:19:16 UTC
+++ src/mod/codecs/mod_dahdi_codec/mod_dahdi_codec.c
@@ -33,7 +33,11 @@
 #include <switch.h>
 #include <g711.h>
 #include <poll.h>
+#if defined(__FreeBSD__)
+#include <dahdi/compat/types.h>
+#else
 #include <linux/types.h>		/* __u32 */
+#endif
 #include <sys/ioctl.h>
 #include <unistd.h>
 #include <fcntl.h>
