--- src/tools/pw-cli.c.orig	2020-02-20 14:33:31 UTC
+++ src/tools/pw-cli.c
@@ -28,7 +28,9 @@
 #include <signal.h>
 #include <string.h>
 #include <ctype.h>
+#ifndef __FreeBSD__
 #include <alloca.h>
+#endif
 
 #include <spa/utils/result.h>
 #include <spa/debug/pod.h>
