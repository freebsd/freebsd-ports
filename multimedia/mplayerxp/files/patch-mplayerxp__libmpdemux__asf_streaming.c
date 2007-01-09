--- mplayerxp/libmpdemux/asf_streaming.c.orig	Wed Jul  6 15:40:40 2005
+++ mplayerxp/libmpdemux/asf_streaming.c	Tue Jan  9 17:58:53 2007
@@ -2,6 +2,7 @@
 #include <stdlib.h>
 #include <string.h>
 #include <unistd.h>
+#include <limits.h>
 #include <errno.h>
 
 #include "config.h"
