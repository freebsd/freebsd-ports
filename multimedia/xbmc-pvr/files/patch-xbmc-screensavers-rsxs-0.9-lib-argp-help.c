--- xbmc/screensavers/rsxs-0.9/lib/argp-help.c.orig
+++ xbmc/screensavers/rsxs-0.9/lib/argp-help.c
@@ -48,6 +48,9 @@
 #endif
 
 #include "argp.h"
+#ifdef __clang__ // XXX
+#define ARGP_FS_EI
+#endif
 #include "argp-fmtstream.h"
 #include "argp-namefrob.h"
 
