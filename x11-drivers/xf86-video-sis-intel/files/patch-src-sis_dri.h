--- src/sis_dri.h.orig	2008-06-06 01:29:26.000000000 +0400
+++ src/sis_dri.h	2008-06-06 01:29:01.000000000 +0400
@@ -116,7 +116,7 @@
   int dummy;
 } SISDRIContextRec, *SISDRIContextPtr;
 
-#ifdef XFree86Server
+#if defined(XFree86Server) || defined(XORG_VERSION_CURRENT)
 
 #include "screenint.h"
 
