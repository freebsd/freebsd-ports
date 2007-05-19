--- src/sis_dri.c.orig	Thu Dec  7 19:02:49 2006
+++ src/sis_dri.c	Thu Dec  7 19:04:16 2006
@@ -45,6 +45,9 @@
 #include "sis.h"
 #include "sis_regs.h"
 
+/* XXX - It doesn't work for a reason but I'm too lazy to find out why. */
+void SISDRICloseScreen(ScreenPtr pScreen);
+
 #include "fb.h"
 #include "GL/glxtokens.h"
 
