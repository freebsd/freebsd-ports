--- plugins/sound/gsd-sound-manager.c.orig	2008-04-07 10:04:58.426471043 -0400
+++ plugins/sound/gsd-sound-manager.c	2008-04-07 10:05:10.592326201 -0400
@@ -23,6 +23,7 @@
 
 #include <sys/types.h>
 #include <sys/wait.h>
+#include <signal.h>
 #include <stdlib.h>
 #include <stdio.h>
 #include <unistd.h>
