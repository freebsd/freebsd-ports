--- mplayerxp/libmpdemux/mux_mpxp64.c.orig	Tue Mar  7 19:38:00 2006
+++ mplayerxp/libmpdemux/mux_mpxp64.c	Mon Oct  2 02:01:28 2006
@@ -32,6 +32,18 @@
 
 #include "mpxpav64.h"
 
+#ifndef lrint
+#define lrint(d) ((int32_t)rint(d))
+#endif
+
+#ifndef lrintf
+#define lrintf(f) ((int32_t)rintf(f))
+#endif
+
+#ifndef llrint
+#define llrint(d) ((int64_t)rint(d))
+#endif
+
 typedef struct priv_mpxpav64_stream_s
 {
     /* statistics */
