--- Xvnc/programs/Xserver/hw/vnc/rfb.h.orig	Fri Feb  9 05:37:33 2001
+++ Xvnc/programs/Xserver/hw/vnc/rfb.h	Wed Nov 20 21:14:27 2002
@@ -23,6 +23,7 @@
  *  USA.
  */
 
+#include <sys/types.h>
 #include <netinet/in.h>
 #include "scrnintstr.h"
 #include "colormapst.h"
