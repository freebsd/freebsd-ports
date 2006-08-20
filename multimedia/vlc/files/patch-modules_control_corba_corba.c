--- modules/control/corba/corba.c.orig	Sun Aug 20 00:16:21 2006
+++ modules/control/corba/corba.c	Sun Aug 20 00:17:24 2006
@@ -28,8 +28,8 @@
 #include "MediaControl.h"
 #include "orbit/poa/portableserver-poa-type.h"
 
-#include <vlc/control.h>
 #include <vlc/vlc.h>
+#include <vlc/mediacontrol.h>
 #include <vlc/intf.h>
 #include <vlc/vout.h>
 #include <vlc/aout.h>
