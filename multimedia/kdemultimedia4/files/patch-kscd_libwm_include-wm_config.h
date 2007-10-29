--- kscd/libwm/include/wm_config.h.orig	2007-10-25 15:02:40.000000000 +0200
+++ kscd/libwm/include/wm_config.h	2007-10-25 15:02:50.000000000 +0200
@@ -131,6 +131,8 @@
  ******************************************************************/
 #if defined(__FreeBSD__) || defined(__FreeBSD)
 
+#include <osreldate.h>
+
 #if __FreeBSD_version >= 500100
 #define DEFAULT_CD_DEVICE	"/dev/acd0"
 #else
