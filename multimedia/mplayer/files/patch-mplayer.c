--- mplayer.c.orig	Tue Dec 21 13:25:58 2004
+++ mplayer.c	Mon Jan 10 22:43:29 2005
@@ -93,7 +93,7 @@
 #define ROUND(x) ((int)((x)<0 ? (x)-0.5 : (x)+0.5))
 
 #ifdef HAVE_RTC
-#include <linux/rtc.h>
+#include <rtc.h>
 #endif
 
 #ifdef USE_TV
