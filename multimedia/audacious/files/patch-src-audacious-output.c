--- src/audacious/output.c.orig	2012-10-28 10:48:02.000000000 +0100
+++ src/audacious/output.c	2012-10-28 10:48:15.000000000 +0100
@@ -24,6 +24,7 @@
 #include <unistd.h>
 
 #include <libaudcore/hook.h>
+#include <libaudcore/audio.h>
 
 #include "debug.h"
 #include "effect.h"
