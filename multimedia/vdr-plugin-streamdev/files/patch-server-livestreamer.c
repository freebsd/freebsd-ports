--- server/livestreamer.c.orig
+++ server/livestreamer.c
@@ -1,7 +1,12 @@
 #include <assert.h>
 
+#ifdef __FreeBSD__
+#include <vdr/libsi/section.h>
+#include <vdr/libsi/descriptor.h>
+#else
 #include <libsi/section.h>
 #include <libsi/descriptor.h>
+#endif
 
 #include <vdr/ringbuffer.h>
 
