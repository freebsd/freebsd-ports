--- inc/slip/slip_user.h.orig	Wed Apr  5 19:48:20 1989
+++ inc/slip/slip_user.h	Thu Sep 18 20:10:32 2003
@@ -46,7 +46,7 @@
  *									     *
  *****************************************************************************/
 
-#define CFGFILE		INSTALL_DIR/slipcfg"
+#define CFGFILE		INSTALL_DIR "/slipcfg"
 #define SLIPDATA	"/usr/spool/slipd/D.%d"
 #define OUTPIPE		"/usr/spool/slipd/outpipe"
 #define PORTLOCK	"/usr/spool/slipd/portlock"
