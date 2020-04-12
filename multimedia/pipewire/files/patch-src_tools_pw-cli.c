--- src/tools/pw-cli.c.orig	2020-03-26 11:34:54 UTC
+++ src/tools/pw-cli.c
@@ -28,7 +28,9 @@
 #include <signal.h>
 #include <string.h>
 #include <ctype.h>
+#ifndef __FreeBSD__
 #include <alloca.h>
+#endif
 #include <getopt.h>
 
 #include <spa/utils/result.h>
