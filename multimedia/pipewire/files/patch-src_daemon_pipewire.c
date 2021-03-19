--- src/daemon/pipewire.c.orig	2021-03-04 15:21:21 UTC
+++ src/daemon/pipewire.c
@@ -25,6 +25,7 @@
 #include <limits.h>
 #include <signal.h>
 #include <getopt.h>
+#include <libgen.h>
 
 #include <spa/utils/result.h>
 #include <pipewire/pipewire.h>
