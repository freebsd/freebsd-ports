
$FreeBSD$

--- channels/chan_oss.c.orig	Wed Aug 13 18:25:16 2003
+++ channels/chan_oss.c	Fri Oct 17 11:27:30 2003
@@ -36,7 +36,7 @@
 #ifdef __linux
 #include <linux/soundcard.h>
 #else
-#include <soundcard.h>
+#include <sys/soundcard.h>
 #endif
 #include "busy.h"
 #include "ringtone.h"
